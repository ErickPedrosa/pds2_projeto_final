#ifndef TELAPLACAR_H
#define TELAPLACAR_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "../include/ObjetoJogo.hpp"
#include "../include/Botao.hpp"
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>

#include <vector>
#include <algorithm>
#include <tuple>    

class TelaPlacar : public ObjetoJogo {
private:
	Botao* voltar;
	ALLEGRO_FONT* fonteBotaoP;


public:
	TelaPlacar(float display_height, float display_width);
	~TelaPlacar();
	void Render(float display_height, float display_width) override;
	void Render(float display_height, float display_width, std::vector<std::tuple<std::string, int, int>> topJogadores, int num_linhas);
	int VerificaClique(int _x, int _y);


};

#endif