#include "../include/TelaGameOver.hpp"
#include <iostream>

#define TELA_INICIO 0
#define TELA_PLACAR 1
#define TELA_CADASTRO 2
#define TELA_JOGO 3
#define TELA_SAIR -1

TelaGameOver::TelaGameOver(float display_height, float display_width) {
    x_atual = 0;
    y_atual = 0;

        if (!al_init_image_addon()) {
            std::cout << "couldn't initialize image addon" << std::endl;
        }

    sprite = al_load_bitmap("assets/background-night.png");
    gameOverImg = al_load_bitmap("assets/gameover.png");

    int botao_height = 100;
    int botao_width = 300;

    reiniciar = new Botao((display_width / 2) - (botao_width / 2),
        (display_height / 2) + 50,
        botao_width, botao_height,
        al_map_rgb(255, 255, 255),
        "Reiniciar", al_create_builtin_font(), al_map_rgb(0, 0, 0));

    voltarMenu = new Botao((display_width / 2) - (botao_width / 2),
        (display_height / 2) + 170,
        botao_width, botao_height,
        al_map_rgb(200, 200, 200),
        "Menu Inicial", al_create_builtin_font(), al_map_rgb(0, 0, 0));


}

TelaGameOver::~TelaGameOver() {
    al_destroy_bitmap(sprite);
    al_destroy_bitmap(gameOverImg);
    delete reiniciar;
    delete voltarMenu;
}

int TelaGameOver::VerificaClique(int _x, int _y) {
    if (reiniciar->FoiClicado(_x, _y)) {
        return TELA_JOGO;
    }
    if (voltarMenu->FoiClicado(_x, _y)) {
        return TELA_INICIO;
    }
    return TELA_PLACAR;
}

int TelaGameOver::getWidth() const {
    return al_get_bitmap_width(sprite);
}

int TelaGameOver::getHeight() const {
    return al_get_bitmap_height(sprite);
}

void TelaGameOver::Render(float display_height, float display_width) {
    int img_w = getWidth();
    int img_h = getHeight();

        int num_tiles = 5;
    float escala_w = display_width / ((num_tiles - 1) * img_w);
    float escala_h = display_height / img_h;

    x_atual -= 1;
    if (x_atual <= -img_w * escala_w) {
        x_atual += img_w * escala_w;
    }

    for (int i = 0; i < num_tiles; i++) {
        float dx = (i * img_w * escala_w) + x_atual;
        float dy = 0;

        al_draw_scaled_bitmap(sprite, 0, 0, img_w, img_h,
            dx, dy, img_w * escala_w, img_h * escala_h, 0);
    }

    float go_w = al_get_bitmap_width(gameOverImg);
    float go_h = al_get_bitmap_height(gameOverImg);
    al_draw_bitmap(gameOverImg, (display_width - go_w) / 2, (display_height - go_h) / 2 - 100, 0);

    reiniciar->GerarBotao();
    voltarMenu->GerarBotao();

 

}