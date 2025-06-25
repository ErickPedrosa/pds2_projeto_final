#include "../include/TelaDeJogo.hpp"
#include <iostream>
#include <cstdlib>


TelaDeJogo::TelaDeJogo() {
    x_atual = 0;
    y_atual = 0;

    if (!al_init_image_addon()) {
        std::cout << "Couldn't initialize image addon" << std::endl;
    }

    sprite = al_load_bitmap("assets/background-day.png");
    

    escala_w = 1.0;
    escala_h = 1.0;

    velocidade = 2.0f;

    for (int i = 0; i < 3; i++) {
        int x_pos = 400 + i * 300;
        obstaculos.push_back(new Obstaculo(x_pos, 800, 200));
    }

    hud = new HUD();
}

TelaDeJogo::~TelaDeJogo() {
    al_destroy_bitmap(sprite);
    for (auto o : obstaculos) delete o;
    obstaculos.clear();
    delete hud;
}

std::vector<Obstaculo*>& TelaDeJogo::getObstaculos() { return obstaculos; }


void TelaDeJogo::Render(float display_height, float display_width, int op) {

    if (op == 1)
    {
        for (auto ob : obstaculos) {
            delete ob;
            
        }
        obstaculos.clear();

        for (int i = 0; i < 3; i++) {
            int x_pos = 400 + i * 300;
            obstaculos.push_back(new Obstaculo(x_pos, 800, 200));
        }
    }
    
    this->Render(display_height, display_width);


    }


void TelaDeJogo::Render(float display_height, float display_width) {


    int img_w = al_get_bitmap_width(sprite);
    int img_h = al_get_bitmap_height(sprite);
    



    int num_tiles = 5;

    escala_w = display_width / ((num_tiles - 1) * img_w);
    escala_h = display_height / img_h;

    for (int i = 0; i < num_tiles; i++) {
        float dx = (i * img_w * escala_w) + x_atual;
        float dy = 0;

        al_draw_scaled_bitmap(
            sprite,
            0, 0, img_w, img_h,
            dx, dy,
            img_w * escala_w,
            img_h * escala_h,
            0
        );
    }

    for (auto o : obstaculos) {
        o->Render(display_height, display_width);
    }

    hud->Render(display_height, display_width);





    
}



float TelaDeJogo::getHeight() const {
   return al_get_bitmap_height(sprite) *this->escala_h;
}




void TelaDeJogo::atualizar() {
    x_atual -= velocidade;

    if (x_atual <= -al_get_bitmap_width(sprite) * escala_w) {
        x_atual += al_get_bitmap_width(sprite) * escala_w;
    }

    // Define uma distância mínima entre os canos
    float distancia_entre_canos = 400.0f;

    // Acha a maior posição X dos canos (o que está mais à direita)
    float ultima_posicao_x = 0;
    for (auto obs : obstaculos) {
        if (obs->getX() > ultima_posicao_x) {
            ultima_posicao_x = obs->getX();
        }
    }

    for (auto obs : obstaculos) {
        obs->atualizar(velocidade);

        if (obs->foraDaTela()) {
            float novaX = ultima_posicao_x + distancia_entre_canos;
            obs->resetar((int)novaX);
            ultima_posicao_x = novaX; // atualiza para o próximo cano seguir esse
        }
    }
}

void TelaDeJogo::AtualizarHUD(int novoScore, double novoTempo, const std::string& nome) {
    hud->Atualizar(novoScore, novoTempo, nome);
}


float TelaDeJogo::getWidth() const {
    return al_get_bitmap_width(sprite) * this->escala_w;
}


/** -Executa o loop da partida
- Atualiza a posição do pássaro
- Verifica colisões
- Controla o score e o tempo*/