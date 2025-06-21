#ifndef TELADEJOGO_HPP
#define TELADEJOGO_HPP

#include <vector>
#include <allegro5/allegro.h>
#include "Obstaculo.hpp"

class TelaDeJogo {
private:
    float x_atual;
    float y_atual;

    float escala_w;
    float escala_h;

    float velocidade;
    ALLEGRO_BITMAP* sprite;

    std::vector<Obstaculo*> obstaculos;

public:
    TelaDeJogo();
    ~TelaDeJogo();

	std::vector<Obstaculo*>& getObstaculos();

    void atualizar();
    void Render(float display_height, float display_width);

    float getWidth() const;
    float getHeight() const;
};

#endif
