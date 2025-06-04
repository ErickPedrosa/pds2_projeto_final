#ifndef COLISAO_H
#define COLISAO_H

#include <allegro5/allegro.h>

class Colisao {
	//gameobject no caso seriam os objetos do jogo que queremos verificar colisão, falta definir propriamente
public:
	bool colidiu(const gameobject* obj1, const gameobject* obj2);
};



#endif