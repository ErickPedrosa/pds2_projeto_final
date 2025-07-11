﻿

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/mouse.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#include <iostream>

#include "../include/TelaInicial.hpp"
#include "../include/TelaCadastro.hpp"
#include "../include/TelaPlacar.hpp"
#include "../include/TelaDeJogo.hpp"
#include "../include/Passaro.hpp"
#include "../include/Colisao.hpp"
#include "../include/Obstaculo.hpp"
#include "../include/GerenciadorCadastro.hpp"
#include "../include/TelaGameOver.hpp"

#define SUCESSO 0
#define TELA_INICIO 0
#define TELA_PLACAR 1
#define TELA_CADASTRO 2
#define TELA_JOGO 3
#define TELA_SAIR -1
#define TELA_GAMEOVER 4
#define TELA_PAUSE 5

int main(int argc, char** argv) {
	
	//Inicio do Allegro
	al_init();
	al_install_keyboard();
	al_install_mouse();
	al_init_primitives_addon();
	al_install_audio();
	al_init_acodec_addon();
	al_reserve_samples(2);

	//Inicialização dos módulos do Allegro
	ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);
	ALLEGRO_EVENT_QUEUE* filaEventos = al_create_event_queue();
	ALLEGRO_DISPLAY* disp = al_create_display(1280, 800);
	ALLEGRO_EVENT evento;
	ALLEGRO_SAMPLE* som_pulo = al_load_sample("./assets/wingflap.wav");
	ALLEGRO_AUDIO_STREAM* som_fundo = al_load_audio_stream("./assets/musica_fundo.wav", 4, 2048);

	
	al_set_audio_stream_playmode(som_fundo, ALLEGRO_PLAYMODE_LOOP);
	al_attach_audio_stream_to_mixer(som_fundo, al_get_default_mixer());

	al_init_font_addon();
	al_init_ttf_addon();
	ALLEGRO_FONT* fonte = al_load_ttf_font("./assets/VT323-Regular.ttf", 72, 0);
	if (!fonte) fonte = al_create_builtin_font();

	ALLEGRO_COLOR corTexto = al_map_rgb(255, 255, 204);
	ALLEGRO_COLOR sombra = al_map_rgb(50, 50, 50);

	//Variáveis para timer na Tela de Jogo
	double tempoInicialPartida = 0.0;
	double tempoPausado = 0.0;
	bool entrouNaTelaDeJogo = false;
	bool entrouNaTelaDePausa = false;

	//Registrando eventos na pilha
	al_register_event_source(filaEventos, al_get_keyboard_event_source());
	al_register_event_source(filaEventos, al_get_display_event_source(disp));
	al_register_event_source(filaEventos, al_get_timer_event_source(timer));
	al_register_event_source(filaEventos, al_get_mouse_event_source());

	//Inicializando objetos
	TelaInicial* telaInicio = new TelaInicial(al_get_display_height(disp), al_get_display_width(disp));
	TelaCadastro* telaCadastro = new TelaCadastro(al_get_display_height(disp), al_get_display_width(disp));
	TelaPlacar* telaPlacar = new TelaPlacar(al_get_display_height(disp), al_get_display_width(disp));
	TelaDeJogo* telaJogo = new TelaDeJogo();
	TelaGameOver* telaGameOver = new TelaGameOver(al_get_display_height(disp), al_get_display_width(disp));
	Passaro* flappy = new Passaro();
	Colisao* colidir = new Colisao();
	GerenciadorCadastro* cadastroJogadores = new GerenciadorCadastro();

	//Variáveis de controle do jogo
	bool jogando = true;
	bool pulo = false;
	int telaAtual = 0;
	int scoreAtual = 0;

	//Inicio do timer do jogo
	al_start_timer(timer);

	//Inicio do looping do jogo
	while (jogando) {
		//Espera por um evento na fila
		al_wait_for_event(filaEventos, &evento);

		//Acaba com o programa 
		if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) break;

		//Verifica envento de mouse
		if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			int _x = evento.mouse.x;
			int _y = evento.mouse.y;
			int telaDestino = telaAtual;

			switch (telaAtual) {
			case TELA_INICIO:
				telaDestino = telaInicio->VerificaClique(_x, _y);
				break;
			case TELA_PLACAR:
				telaDestino = telaPlacar->VerificaClique(_x, _y);
				break;
			case TELA_CADASTRO:
				telaDestino = telaCadastro->VerificaClique(_x, _y);
				if (telaDestino == TELA_JOGO)
					//Efetua o login do jogador
					cadastroJogadores->Logar(telaCadastro->GetInput());
				break;
			case TELA_GAMEOVER:
				telaDestino = telaGameOver->VerificaClique(_x, _y);
				break;
			case TELA_SAIR:
				jogando = false;
				break;
			}
			telaAtual = telaDestino;
		}

		if (evento.type == ALLEGRO_EVENT_KEY_CHAR) {
			telaCadastro->VerificaDigitacao(evento);
		}

		//Verifica envento de teclas pressionadas
		if (evento.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (evento.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
			case ALLEGRO_KEY_SPACE:
				pulo = true;
				break;
			case ALLEGRO_KEY_ESCAPE:
				telaAtual = (telaAtual == TELA_JOGO) ? TELA_PAUSE : (telaAtual == TELA_PAUSE ? TELA_JOGO : telaAtual);
				break;
			}
		}

		//Verifica evento de soltar teclas (Quando se solta a tecla de pulo)
		if (evento.type == ALLEGRO_EVENT_KEY_UP) {
			pulo = false;
		}

		if (evento.type == ALLEGRO_EVENT_TIMER) {
			auto topJogadores = cadastroJogadores->TopNJogadores(5);

			//Condicionais para verificar qual tela deve ser mostrada
			switch (telaAtual) {
			case TELA_INICIO:
				al_clear_to_color(al_map_rgb(0, 0, 0));
				telaInicio->Render(al_get_display_height(disp), al_get_display_width(disp));
				break;

			case TELA_PLACAR:
				al_clear_to_color(al_map_rgb(0, 0, 0));
				telaPlacar->Render(al_get_display_height(disp), al_get_display_width(disp), topJogadores, 5);
				break;

			case TELA_CADASTRO:
				al_clear_to_color(al_map_rgb(0, 0, 0));
				telaCadastro->Render(al_get_display_height(disp), al_get_display_width(disp));
				break;

			case TELA_JOGO: {
				al_clear_to_color(al_map_rgb(0, 0, 0));
				if (!entrouNaTelaDeJogo) {
					tempoInicialPartida = al_get_time();
					scoreAtual = 0;
					entrouNaTelaDeJogo = true;
				}
				if (entrouNaTelaDePausa) {
					tempoInicialPartida += al_get_time() - tempoPausado;
					entrouNaTelaDePausa = false;
				}

				telaJogo->atualizar();
				telaJogo->Render(al_get_display_height(disp), al_get_display_width(disp));
				flappy->Render(al_get_display_height(disp), al_get_display_width(disp), 0);

				if (colidir->colidirT(flappy, telaJogo)) {
					telaJogo->Render(al_get_display_height(disp), al_get_display_width(disp), 1);
					flappy->Restart();
					telaAtual = TELA_GAMEOVER;
					entrouNaTelaDeJogo = false;
					cadastroJogadores->AtualizarJogador(scoreAtual);
				}

				for (auto cano : telaJogo->getObstaculos()) {
					if (colidir->colidirO(flappy, cano)) {
						telaJogo->Render(al_get_display_height(disp), al_get_display_width(disp), 1);
						flappy->Restart();
						telaAtual = TELA_GAMEOVER;
						entrouNaTelaDeJogo = false;
						cadastroJogadores->AtualizarJogador(scoreAtual);
					}
				}

				for (auto cano : telaJogo->getObstaculos()) {
					if (!cano->jaContabilizado() &&
						flappy->getX() > cano->getX() + cano->getLargura()) {
						scoreAtual++;
						cano->marcarComoContabilizado();
					}
				}

				if (pulo) {
					flappy->Render(al_get_display_height(disp), al_get_display_width(disp), 1);
					al_play_sample(som_pulo, 0.5, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
				}

				double tempoAtual = al_get_time() - tempoInicialPartida;
				telaJogo->AtualizarHUD(scoreAtual, tempoAtual, telaCadastro->GetInput());
				break;
			}

			case TELA_GAMEOVER:
				al_clear_to_color(al_map_rgb(0, 0, 0));
				telaGameOver->Render(al_get_display_height(disp), al_get_display_width(disp));
				break;

			case TELA_PAUSE:
				al_clear_to_color(al_map_rgb(0, 0, 0));
				if (!entrouNaTelaDePausa) {
					tempoPausado = al_get_time();
					entrouNaTelaDePausa = true;
				}
				telaJogo->Render(al_get_display_height(disp), al_get_display_width(disp));
				flappy->Render(al_get_display_height(disp), al_get_display_width(disp), 2);
				al_draw_textf(fonte, sombra, al_get_display_width(disp) / 2 + 2, al_get_display_height(disp) / 2 + 2, ALLEGRO_ALIGN_CENTRE, "Jogo Pausado");
				al_draw_textf(fonte, corTexto, al_get_display_width(disp) / 2, al_get_display_height(disp) / 2, ALLEGRO_ALIGN_CENTRE, "Jogo Pausado");
				break;
			}

			al_flip_display();
		}
	}

	//Desalocação dos objetos
	delete telaInicio;
	delete telaCadastro;
	delete telaPlacar;
	delete telaJogo;
	delete flappy;
	delete colidir;
	delete cadastroJogadores;
	delete telaGameOver;


	//Destruição dos módulos do Allegro
	al_destroy_font(fonte);
	al_destroy_display(disp);
	al_destroy_timer(timer);
	al_destroy_event_queue(filaEventos);
	al_destroy_sample(som_pulo);
	al_detach_audio_stream(som_fundo);
	al_destroy_audio_stream(som_fundo);
	al_uninstall_audio();
	al_shutdown_ttf_addon();
	al_shutdown_font_addon();
	al_shutdown_primitives_addon();
	al_shutdown_image_addon();
	al_uninstall_system();

	return SUCESSO;
}