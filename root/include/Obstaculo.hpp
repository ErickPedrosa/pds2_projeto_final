#ifndef OBSTACULO_HPP
#define OBSTACULO_HPP

#include "ObjetoJogo.hpp"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>


class Obstaculo : public ObjetoJogo {
private:
    float abertura;
    int altura_tela;
    int largura;
    int y_gap;

public:
    Obstaculo(int x_inicial, int altura_tela, float abertura);

    void atualizar(float velocidade);
    void Render(float display_height, float display_width);
    bool foraDaTela() const;
    void resetar(float novaX);
};

#endif
#pragma once
