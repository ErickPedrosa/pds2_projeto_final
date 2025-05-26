#ifndef TELACADASTRO_H
#define TELACADASTRO_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "../include/IRenderizavel.hpp"
#include "../include/Botao.hpp"


class TelaCadastro : IRenderizavel {
private:
	int x_atual;
	int y_atual;

	Botao* cadastrar;
	Botao* logar;
	Botao* voltar;


	//InfoJogadores

public:
	TelaCadastro(float display_height, float display_width);
	~TelaCadastro();
	void Render(float display_height, float display_width) override;
	int VerificaClique(int _x, int _y);

};

#endif