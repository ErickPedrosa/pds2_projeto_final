#include "../include/HUD.hpp"
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <iostream>

HUD::HUD() {
	score = 0;
	tempo = 0.0;
	nomeJogador = "Jogador";

	sprite = nullptr;

	al_init_font_addon();
	al_init_ttf_addon();

	fonte = al_load_ttf_font("assets/VT323-Regular.ttf", 28, 0);
	if (!fonte) {
		std::cout << "Erro ao carregar a fonte" << std::endl;
	}
}

HUD::~HUD() {
	if (fonte) {
		al_destroy_font(fonte);
	}
}

void HUD::Atualizar(int novoScore, double novoTempo, const std::string& nome) {
	score = novoScore;
	tempo = novoTempo;
	nomeJogador = nome;
}

void HUD::Render(float display_height, float display_width) {
	if (!fonte) return;

	ALLEGRO_COLOR corTexto = al_map_rgb(255, 255, 204);
	ALLEGRO_COLOR sombra = al_map_rgb(50, 50, 50); 

	
	al_draw_textf(fonte, sombra, display_width / 2 + 2, 10 + 2, ALLEGRO_ALIGN_CENTRE, "score: %d", score);
	al_draw_textf(fonte, corTexto, display_width / 2, 10, ALLEGRO_ALIGN_CENTRE, "score: %d", score);

	al_draw_textf(fonte, sombra, 22, 12, ALLEGRO_ALIGN_LEFT, "tempo: %.1f s", tempo);
	al_draw_textf(fonte, corTexto, 20, 10, ALLEGRO_ALIGN_LEFT, "tempo: %.1f s", tempo);

	al_draw_textf(fonte, sombra, display_width - 18, 12, ALLEGRO_ALIGN_RIGHT, "jogador: %s", nomeJogador.c_str());
	al_draw_textf(fonte, corTexto, display_width - 20, 10, ALLEGRO_ALIGN_RIGHT, "jogador: %s", nomeJogador.c_str());

	

}

/**Exibe informações da partida: score, tempo e nome do jogador
- Atualiza os dados em tempo real
- Renderiza o HUD na tela*/