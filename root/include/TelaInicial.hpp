#ifndef TELAINICIAL_H
#define TELAINICIAL_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "../include/ObjetoJogo.hpp"
#include "../include/Botao.hpp"
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>


class TelaInicial : public ObjetoJogo {
	private:
		Botao *jogar;
		Botao *placar;
		Botao *sair;
		ALLEGRO_FONT* fonteBotao;
		ALLEGRO_FONT* fonteTitulo;


	public:
		TelaInicial(float display_height, float display_width);
		~TelaInicial();
		void Render(float display_height, float display_width) override;
		int VerificaClique(int _x, int _y);

};

#endif