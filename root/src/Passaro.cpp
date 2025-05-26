#include "../include/Passaro.hpp"
#include <iostream>


Passaro::Passaro() : x_atual(0), y_atual(0) {
    if (!al_init_image_addon())
    {
        std::cout << "couldn't initialize image addon" << std::endl;
        //Trown error
    }

    sprite = al_load_bitmap("assets/bluebird-midflap.png");
}


Passaro::~Passaro() {
    al_destroy_bitmap(sprite);



}

void Passaro::Render(float display_height, float display_width) {
    int op_padrao = 0;

    this->Render(display_height, display_width, op_padrao);
}


void Passaro::Render(float display_height, float display_width, int op) {

    int img_w = al_get_bitmap_width(sprite);
    int img_h = al_get_bitmap_height(sprite);

    float escala_w = 1.5;
    float escala_h = 1.5;

    switch (op)
    {
    case 0:
        y_atual += 5;


        break;

    case 1:
        y_atual -= 10;


        break;
    }

   

    
    float dx = img_w + (display_width/10);
    float dy = img_h + y_atual;

    al_draw_scaled_bitmap(
        sprite,
        0, 0, img_w, img_h,
        dx, dy,
        img_w * escala_w,
        img_h * escala_h,
        0
    );
    

}
