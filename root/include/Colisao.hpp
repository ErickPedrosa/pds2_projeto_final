#ifndef COLISAO_H
#define COLISAO_H


#include <allegro5/allegro.h>
#include "../include/Passaro.hpp"
#include "../include/TelaDeJogo.hpp"

class Colisao {
	//gameobject no caso seriam os objetos do jogo que queremos verificar colisão, falta definir propriamente
public:
	bool colidiu(const Passaro* flappy, const TelaDeJogo* telajogo);
};


#endif