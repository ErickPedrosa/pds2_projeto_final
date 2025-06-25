#include "../include/Colisao.hpp"
#include <allegro5/allegro.h>



// Verifica se o passaro colide com a tela de jogo
bool Colisao::colidirT(const Passaro* flappy, const TelaDeJogo* telajogo) {
	
		
	return (flappy->getY() < (0 - flappy->getHeight()) || flappy->getY() + flappy->getHeight() > telajogo->getHeight());
	
}

bool Colisao::colidirO(const Passaro* flappy, const Obstaculo* cano) {  
    // Verifica se o passaro colide com o obstaculo  
    return ((flappy->getX() + flappy->getWidth() > cano->getX() &&  
             flappy->getX() < cano->getX() + cano->getLargura()) &&  
            (flappy->getY() < cano->getYGap() ||  
             flappy->getY() + flappy->getHeight() > cano->getYGap() + cano->getAbertura()));  
}

/**Verifica se o Pássaro colidiu com a tela (colidirT)
- Verifica se o Pássaro colidiu com um Obstaculo (colidirO)*/