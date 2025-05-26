#include "../include/TelaCadastro.hpp"
#include <iostream>

TelaCadastro::TelaCadastro(float display_height, float display_width) : x_atual(0), y_atual(0) {
    if (!al_init_image_addon())
    {
        std::cout << "couldn't initialize image addon" << std::endl;
        //Trown error
    }

    sprite = al_load_bitmap("assets/background-night.png");

    int botao_height = 100;
    int botao_width = 300;

    logar = new Botao((display_width / 2) - (botao_width / 2), (display_height / 2) - (botao_height * 1.5),
        botao_width, botao_height, al_map_rgb(255, 255, 255),
        "Logar", al_create_builtin_font(), al_map_rgb(0, 0, 0)
    );

    cadastrar = new Botao((display_width / 2) - (botao_width / 2), (display_height / 2),
        botao_width, botao_height, al_map_rgb(255, 255, 255),
        "Cadastrar", al_create_builtin_font(), al_map_rgb(0, 0, 0)
    );

    voltar = new Botao((display_width / 2) - (botao_width / 2), (display_height / 2) + (botao_height * 1.5),
        botao_width, botao_height, al_map_rgb(255, 255, 255),
        "Voltar", al_create_builtin_font(), al_map_rgb(0, 0, 0)
    );

}




TelaCadastro::~TelaCadastro() {
    al_destroy_bitmap(sprite);

    delete(logar);
    delete(cadastrar);
    delete(voltar);


}

int TelaCadastro::VerificaClique(int _x, int _y) {
    if (logar->FoiClicado(_x, _y)) {
        return 3; //Se mant�m pois ainda n�o temos tela de login
    }

    if (cadastrar->FoiClicado(_x, _y)) {
        return 3; //Se mant�m pois ainda n�o temos para cadastrar
    }

    if (voltar->FoiClicado(_x, _y)) {
        return 0; //Volta para a p�gina inicial 
    }


    return 2;
}

void TelaCadastro::Render(float display_height, float display_width) {



    int img_w = al_get_bitmap_width(sprite);
    int img_h = al_get_bitmap_height(sprite);


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

        al_draw_scaled_bitmap(
            sprite,
            0, 0, img_w, img_h,
            dx, dy,
            img_w * escala_w,
            img_h * escala_h,
            0
        );
    }

    logar->GerarBotao();
    cadastrar->GerarBotao();
    voltar->GerarBotao();


}