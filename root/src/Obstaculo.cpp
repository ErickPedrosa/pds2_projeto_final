#include "../include/Obstaculo.hpp"
#include <iostream>
#include <cstdlib>

Obstaculo::Obstaculo(int x_inicial, int altura_tela, float abertura) {
    x_atual = x_inicial;
    y_atual = 0;
    this->altura_tela = altura_tela;
    this->abertura = abertura;

    sprite = al_load_bitmap("assets/pipe-green.png");
    if (!sprite) {
        std::cout << "Erro ao carregar sprite do cano!" << std::endl;
    }

    largura = al_get_bitmap_width(sprite);
    y_gap = rand() % (altura_tela - (int)abertura - 200) + 100;
}

void Obstaculo::atualizar(int velocidade) {
    x_atual -= velocidade;
}

bool Obstaculo::foraDaTela() const {
    return x_atual + largura < 0;
}

void Obstaculo::resetar(int novaX) {  // <-- MANTÉM int para bater com o .hpp
    x_atual = novaX;
    y_gap = rand() % (altura_tela - (int)abertura - 200) + 100;
}

void Obstaculo::Render(float display_height, float display_width) {
    al_draw_scaled_bitmap(
        sprite,
        0, 0,
        largura,
        al_get_bitmap_height(sprite),
        x_atual,
        y_gap - al_get_bitmap_height(sprite),
        largura,
        al_get_bitmap_height(sprite),
        ALLEGRO_FLIP_VERTICAL
    );

    al_draw_scaled_bitmap(
        sprite,
        0, 0,
        largura,
        al_get_bitmap_height(sprite),
        x_atual,
        y_gap + abertura,
        largura,
        al_get_bitmap_height(sprite),
        0
    );
}
