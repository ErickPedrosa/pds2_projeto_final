#include "../include/TelaInicial.hpp"
#include <iostream>

TelaInicial::TelaInicial() : x_atual(0), y_atual(0) {
    if (!al_init_image_addon())
    {
        std::cout <<"couldn't initialize image addon" << std::endl;
        //Trown error
    }

    fundo = al_load_bitmap("assets/background-night.png");
}


TelaInicial::~TelaInicial() {
    al_destroy_bitmap(fundo);



}

void TelaInicial::Render(float display_height, float display_width) {
    al_clear_to_color(al_map_rgb(0, 0, 0));


    int img_w = al_get_bitmap_width(fundo);
    int img_h = al_get_bitmap_height(fundo);


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
            fundo,
            0, 0, img_w, img_h,         
            dx, dy,                     
            img_w * escala_w,             
            img_h * escala_h,             
            0
        );
    }


    al_flip_display();
}