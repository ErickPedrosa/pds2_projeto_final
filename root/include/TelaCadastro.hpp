#ifndef TELACADASTRO_H
#define TELACADASTRO_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "../include/ObjetoJogo.hpp"
#include "../include/Botao.hpp"
#include "../include/CaixaDeTexto.hpp"
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>


class TelaCadastro : public ObjetoJogo {
private:
	CaixaDeTexto* input;
	Botao* logar;
	Botao* voltar;
	ALLEGRO_FONT* fonte;


public:
	TelaCadastro(float display_height, float display_width);
	~TelaCadastro();
	void Render(float display_height, float display_width) override;
	int VerificaClique(int _x, int _y);
	void VerificaDigitacao(ALLEGRO_EVENT evento);
	std::string GetInput();

};

#endif