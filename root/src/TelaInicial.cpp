#include "../include/TelaInicial.hpp"
#include <iostream>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>

#define TELA_INICIO 0
#define TELA_PLACAR 1
#define TELA_CADASTRO 2
#define TELA_JOGO 3
#define TELA_SAIR -1


TelaInicial::TelaInicial(float display_height, float display_width){
    x_atual = 0;
    y_atual = 0;

    if (!al_init_image_addon())
    {
        std::cout <<"couldn't initialize image addon" << std::endl;
        //Trown error
    }

    if (!al_init_ttf_addon()) {
        std::cout << "Erro ao inicializar TTF" << std::endl;
    }

    sprite = al_load_bitmap("assets/background-night.png");

    fonteBotao = al_load_ttf_font("assets/VT323-Regular.ttf", 28, 0);
    if (!fonteBotao) {
        std::cout << "Erro ao carregar fonte personalizada!" << std::endl;
        fonteBotao = al_create_builtin_font();
    }

    fonteTitulo = al_load_ttf_font("assets/VT323-Regular.ttf", 60, 0);
    if (!fonteTitulo) {
        std::cout << "Erro ao carregar fonte personalizada!" << std::endl;
    }



    int botao_height = 60;
    int botao_width = 220;

    jogar = new Botao( (display_width/2) - (botao_width/2), (display_height / 2) - (botao_height * 1.5),
                        botao_width, botao_height, al_map_rgb(255, 255, 204),
                        "Jogar", fonteBotao, al_map_rgb(0, 0, 77)
    );

    placar = new Botao((display_width / 2) - (botao_width / 2), (display_height / 2) ,
        botao_width, botao_height, al_map_rgb(0,179,179),
        "Placar", fonteBotao, al_map_rgb(255,255,204)
    );

    sair = new Botao((display_width / 2) - (botao_width / 2), (display_height / 2) + (botao_height * 1.5),
        botao_width, botao_height, al_map_rgb(255, 255, 204),
        "Sair", fonteBotao, al_map_rgb(0, 0, 77)
    );

}



TelaInicial::~TelaInicial() {
    al_destroy_bitmap(sprite);
    al_destroy_font(fonteBotao);
    al_destroy_font(fonteTitulo);
    delete(jogar);
    delete(placar);
    delete(sair);


}

int TelaInicial::VerificaClique(int _x, int _y) {
    if (jogar->FoiClicado(_x, _y)) {
        return TELA_CADASTRO; //Vai para a tela de cadastro;
    }

    if (placar->FoiClicado(_x, _y)) {
        return TELA_PLACAR; //Vai para a tela de placar;
    }

    if (sair->FoiClicado(_x, _y)) {
        return TELA_SAIR; //Sai do Programa;
    }


    return TELA_INICIO;
}


void TelaInicial::Render(float display_height, float display_width) {
   
    int img_w = this->getWidth();
    int img_h = this->getHeight();

    int num_tiles = 5;

    float escala_w = display_width / ((num_tiles - 1) * img_w);
    float escala_h = display_height / img_h;


    x_atual -= 1;
    if (x_atual <= -img_w * escala_w) {
        x_atual += img_w * escala_w;
    }

    for (int i = 0; i < num_tiles; i++) {
        float dx =  (i * img_w * escala_w) + x_atual;  
        float dy = 0;                 

        al_draw_scaled_bitmap(
            sprite,
            0, 0, img_w, img_h,         
            dx, dy,                     
            img_w * escala_w,             
            img_h * escala_h,             
            0
        );
        al_draw_text(fonteTitulo, al_map_rgb(255, 255, 204),
            display_width / 2,
            200,
            ALLEGRO_ALIGN_CENTER,
            "FLAPPY BIRD");
        al_draw_text(fonteTitulo, al_map_rgb(50, 50, 50),
            display_width / 2 + 2,
            202,
            ALLEGRO_ALIGN_CENTER,
            "FLAPPY BIRD");

    
    }


    jogar->GerarBotao();
    placar->GerarBotao();
    sair->GerarBotao();


}

/**- Exibe a tela inicial com fundo animado
- Cria e desenha os botões "Jogar", "Placar", "Sair"
- Verifica cliques e direciona a próxima tela*/