#ifndef TELADEJOGO_HPP
#define TELADEJOGO_HPP

#include <vector>
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "ObjetoJogo.hpp"
#include "HUD.hpp"
#include "Obstaculo.hpp"

class TelaDeJogo : public ObjetoJogo {
private:
    float x_atual;
    float y_atual;

    float escala_w;
    float escala_h;
    float velocidade;

    ALLEGRO_BITMAP* sprite;

    std::vector<Obstaculo*> obstaculos;
    HUD* hud;

public:
    
    TelaDeJogo();
    ~TelaDeJogo();

    std::vector<Obstaculo*>& getObstaculos();

  
    void atualizar();
    void Render(float display_height, float display_width, int op);
    void Render(float display_height, float display_width);
    float getWidth() const;
    float getHeight() const;
    void AtualizarHUD(int novoScore, double novoTempo, const std::string& nome);
};

#endif