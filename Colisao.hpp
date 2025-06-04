#ifndef COLISAO_H
#define COLISAO_H


#include <allegro5/allegro.h>
#include "root/include/Passaro.hpp"
#include "root/include/TelaDeJogo.hpp"

class Colisao {
	//gameobject no caso seriam os objetos do jogo que queremos verificar colis�o, falta definir propriamente
public:
	bool colidiu(const Passaro* flappy, const TelaDeJogo* telajogo);
};



#endif