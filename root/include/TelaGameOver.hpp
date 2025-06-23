#ifndef TELAGAMEOVER_HPP
#define TELAGAMEOVER_HPP

#include "Botao.hpp"
#include "IRenderizavel.hpp"

class TelaGameOver : public IRenderizavel {
private:
    ALLEGRO_BITMAP* sprite;
    ALLEGRO_BITMAP* gameOverImg;
    float x_atual;
    float y_atual;
    Botao* reiniciar;
    Botao* voltarMenu;

public:
    TelaGameOver(float display_height, float display_width);
    ~TelaGameOver();

    void Render(float display_height, float display_width) override;
    int VerificaClique(int _x, int _y);
    int getWidth() const;
    int getHeight() const;
};

#endif

