#ifndef COLISAO_H
#define COLISAO_H


#include <allegro5/allegro.h>
#include "../include/Passaro.hpp"
#include "../include/TelaDeJogo.hpp"
#include "../include/Obstaculo.hpp"

class Colisao {
	
public:
	bool colidirT(const Passaro* flappy, TelaDeJogo& telajogo);
	bool colidirO(const Passaro* flappy, const Obstaculo* cano);
};


#endif