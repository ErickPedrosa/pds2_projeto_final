


#include "../include/TelaDeJogo.hpp"
#include <iostream>

TelaDeJogo::TelaDeJogo() {
    if (!al_init_image_addon())
    {
        std::cout << "couldn't initialize image addon" << std::endl;
        //Trown error
    }

    fundo = al_load_bitmap("assets/background-day.png");
}


TelaDeJogo::~TelaDeJogo() {
    al_destroy_bitmap(fundo);



}

void TelaDeJogo::Render(float display_height, float display_width) {
    al_clear_to_color(al_map_rgb(0, 0, 0));


    int img_w = al_get_bitmap_width(fundo);
    int img_h = al_get_bitmap_height(fundo);


    int num_tiles = 5;

    float escala_w = display_width / (num_tiles * img_w);
    float escala_h = display_height / img_h;



    for (int i = 0; i < num_tiles; i++) {
        float dx = i * img_w * escala_w;
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