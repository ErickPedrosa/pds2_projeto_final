#include "Colisao.hpp"
#include <allegro5/allegro.h>



// Função que verifica se dois objetos colidem
bool Colisao::colidiu(const gameobject* obj1, const gameobject* obj2) {
	
		return (obj1->getx() + obj1->getwidth() > obj2->getx() && obj1->getx() < obj2->getx() + obj2->getwidth() && obj1->gety()
			+ obj1->getheight() > obj2->gety() && obj1->gety() < obj2->gety() + obj2->getheight());
	
}

//caso retornar true, passar pra tela de morte.