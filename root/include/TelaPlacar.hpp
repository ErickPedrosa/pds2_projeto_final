#ifndef TELAPLACAR_H
#define TELAPLACAR_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "../include/IRenderizavel.hpp"
#include "../include/Botao.hpp"


class TelaPlacar : IRenderizavel {
private:
	int x_atual;
	int y_atual;

	Botao* voltar;


	//InfoJogadores

public:
	TelaPlacar(float display_height, float display_width);
	~TelaPlacar();
	void Render(float display_height, float display_width) override;
	int VerificaClique(int _x, int _y);


};

#endif