#include "../include/Colisao.hpp"
#include <allegro5/allegro.h>



// Verifica se o passaro colide com a tela de jogo
bool Colisao::colidirT(const Passaro* flappy, const TelaDeJogo* telajogo) {
	
		
	return (flappy->getY() < (0 - flappy->getHeight()) || flappy->getY() + flappy->getHeight() > telajogo->getHeight());
	
}

bool Colisao::colidirO(const Passaro* flappy, const Obstaculo* cano) {
	
	// Verifica se o passaro colide com o obstaculo
	return (flappy->getX() + flappy->getWidth() > cano->getAbertura() && flappy->getX() < cano->getAbertura() + cano->getLargura() &&
			flappy->getY() + flappy->getHeight() > cano->getYGap() && flappy->getY() < cano->getYGap() + cano->getAlturaTela());
}

