#include "../include/Colisao.hpp"
#include <allegro5/allegro.h>



// Funcao que verifica se o teto e chao colidem com passaro
bool Colisao::colidiu(const Passaro* flappy, const TelaDeJogo* telajogo) {
	
		
	return (flappy->getY() < (0 - flappy->getHeight()) || flappy->getY() + flappy->getHeight() > telajogo->getHeight());
	
}

/* Funcao para passaro e obstaculo seria:

return (flappy->getX() + flappy->getWidth() > telajogo->getX() && flappy->getX() < telajogo->getX() + telajogo->getWidth() && flappy->getY()
+ flappy->getHeight() > telajogo->getY() && flappy->getY() < telajogo->getY() + telajogo->getHeight()); */