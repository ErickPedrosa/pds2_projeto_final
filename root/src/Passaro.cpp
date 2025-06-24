#include "../include/Passaro.hpp"
#include <iostream>


Passaro::Passaro() : escala(1.5) {
    x_atual = 0;
    y_atual = 0;
    
    if (!al_init_image_addon())
    {
        std::cout << "couldn't initialize image addon" << std::endl;
        //Trown error
    }

    sprite = al_load_bitmap("assets/bluebird-midflap-lacinho-redimensionado.png");
}


Passaro::~Passaro() {
    al_destroy_bitmap(sprite);
}

void Passaro::Render(float display_height, float display_width) {
    int op_padrao = 0;

    this->Render(display_height, display_width, op_padrao);
}


void Passaro::Render(float display_height, float display_width, int op) {

    int img_w = this->getWidth();
    int img_h = this->getHeight();

    float escala_w = this->escala;
    float escala_h = this->escala;

    switch (op)
    {
    case 0:
        y_atual += 5;


        break;

    case 1:
        y_atual -= 10;


        break;
    case 2:
        y_atual = y_atual;
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

float Passaro::getWidth() const { return al_get_bitmap_width(sprite) * this->escala; }
float Passaro::getHeight() const { return al_get_bitmap_height(sprite) * this->escala; } 
float Passaro::getX() const {
    
    int img_w = al_get_bitmap_width(sprite);
    float dx = img_w + (al_get_display_width(al_get_current_display()) / 10);
    return dx;
}

float Passaro::getY() const {
   
    int img_h = al_get_bitmap_height(sprite);
    float dy = img_h + y_atual;
    return dy;
}

void Passaro::Restart() {
    x_atual = 0;
    y_atual = 0;
}