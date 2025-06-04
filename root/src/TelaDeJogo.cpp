


#include "../include/TelaDeJogo.hpp"
#include <iostream>

TelaDeJogo::TelaDeJogo() {
    if (!al_init_image_addon())
    {
        std::cout << "couldn't initialize image addon" << std::endl;
        //Trown error
    }

    sprite = al_load_bitmap("assets/background-day.png");
}


TelaDeJogo::~TelaDeJogo() {
    al_destroy_bitmap(sprite);



}

void TelaDeJogo::Render(float display_height, float display_width) {
 


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

}

float TelaDeJogo::getX() const { return 0; }
float TelaDeJogo::getY() const { return 0; }
float TelaDeJogo::getWidth() const { return al_get_bitmap_width(sprite); }
float TelaDeJogo::getHeight() const { return al_get_bitmap_height(sprite); }