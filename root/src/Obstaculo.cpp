/**Gera e posiciona obstáculos
- Atualiza posicao horizontal (movimento)
- Renderiza os canos superiores e inferiores
- Verifica se saiu da tela
- Reseta posicao com nova abertura
- Informa abertura e posicao vertical
- Controla se o score ja foi contabilizado*/

#include "../include/Obstaculo.hpp"
#include <iostream>
#include <cstdlib>


Obstaculo::Obstaculo(int x_inicial, int altura_tela, float abertura) {
    x_atual = x_inicial;
    this->altura_tela = altura_tela;
    this->abertura = abertura;

    sprite = al_load_bitmap("assets/pipe-green.png");
    if (!sprite) {
        std::cout << "couldn't initialize image addon" << std::endl;
    }

    largura = al_get_bitmap_width(sprite);
    y_gap = rand() % (altura_tela - (int)abertura - 200) + 50;

    pontoContabilizado = false;
}

Obstaculo::~Obstaculo() {
    if (sprite) {
        al_destroy_bitmap(sprite); 
        sprite = nullptr; 
    }
}

void Obstaculo::atualizar(int velocidade) {
    x_atual -= velocidade;
}

bool Obstaculo::foraDaTela() const {
    return x_atual + largura < 0;
}

void Obstaculo::resetar(int novaX) {
    x_atual = novaX;

    int margem_superior = 50; // espaço mínimo entre o cano superior e o topo da tela
    int max_gap_top = altura_tela - abertura - 112 - 50; // 112 = altura da base (chão)

    y_gap = rand() % (max_gap_top - margem_superior + 1) + margem_superior;

    pontoContabilizado = false;
}



void Obstaculo::Render(float display_height, float display_width) {
    int altura_cano = al_get_bitmap_height(sprite);
    int largura_cano = al_get_bitmap_width(sprite);

    // cano de cima
    float altura_superior = y_gap;
    al_draw_scaled_bitmap(
        sprite,
        0, 0,
        largura_cano, altura_cano,
        x_atual,
        0, // começa no topo da tela
        largura_cano,
        altura_superior, // aumenta se estiver longe do chão
        ALLEGRO_FLIP_VERTICAL
    );

    // cano de baixo
    float altura_inferior = altura_tela - (y_gap + abertura);
    al_draw_scaled_bitmap(
        sprite,
        0, 0,
        largura_cano, altura_cano,
        x_atual,
        y_gap + abertura,
        largura_cano,
        altura_inferior, // diminue se estiver perto do chão
        0
    );
}


float Obstaculo::getAbertura() const { return abertura; }
int Obstaculo::getLargura() const { return largura; }
int Obstaculo::getYGap() const { return y_gap; }
int Obstaculo::getAlturaTela() const { return altura_tela; }

bool Obstaculo::jaContabilizado() const {
    return pontoContabilizado;
}

void Obstaculo::marcarComoContabilizado() {
    pontoContabilizado = true;
}
