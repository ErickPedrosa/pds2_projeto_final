#ifndef TELAPLACAR_H
#define TELAPLACAR_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "../include/ObjetoJogo.hpp"
#include "../include/Botao.hpp"


class TelaPlacar : public ObjetoJogo {
private:
	Botao* voltar;


public:
	TelaPlacar(float display_height, float display_width);
	~TelaPlacar();
	void Render(float display_height, float display_width) override;
	int VerificaClique(int _x, int _y);


};

#endif