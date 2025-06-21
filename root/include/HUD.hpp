#ifndef HUD_H
#define HUD_H

#include "../include/ObjetoJogo.hpp"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <string>


class HUD : public ObjetoJogo {
private:
	int score;
	double tempo;
	std::string nomeJogador;
	ALLEGRO_FONT* fonte;

public:
	HUD();
	~HUD();

	void Atualizar(int novoScore, double novoTempo, const std::string& nome);
	void Render(float display_height, float display_width) override;

};

#endif
