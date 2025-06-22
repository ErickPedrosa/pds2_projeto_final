#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/mouse.h>
#include <allegro5/allegro_primitives.h>

#include "../include/TelaInicial.hpp"
#include "../include/TelaCadastro.hpp"
#include "../include/TelaPlacar.hpp"
#include "../include/TelaDeJogo.hpp"
#include "../include/Passaro.hpp"
#include "../include/Colisao.hpp"
#include "../include/Obstaculo.hpp"



#define SUCESSO 0

#define TELA_INICIO 0
#define TELA_PLACAR 1
#define TELA_CADASTRO 2
#define TELA_JOGO 3
#define TELA_SAIR -1



int main(int argc, char** argv) {


	//Inicio do Allegro
	al_init();
	al_install_keyboard();
	al_install_mouse();
	al_init_primitives_addon();




	//Inicializa��o dos m�dulos do Allegro
	ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);
	ALLEGRO_EVENT_QUEUE* filaEventos = al_create_event_queue();
	ALLEGRO_DISPLAY* disp = al_create_display(1280, 800);
	ALLEGRO_FONT* font = al_create_builtin_font();
	ALLEGRO_EVENT evento;

	//Variáveis para timer na Tela de Jogo
	double tempoInicialPartida = 0.0; 
	bool entrouNaTelaDeJogo = false; 

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
	Passaro* flappy = new Passaro();
	Colisao* colidir = new Colisao(); 
    

	//Vari�veis de controle do jogo
	bool jogando = true;
	bool pulo = false;
	int telaAtual = 0;


	//Inicio do timer do jogo
	al_start_timer(timer);


	//Inicio do looping do jogo
	while (jogando)
	{

		//Espera por um evento na fila
		al_wait_for_event(filaEventos, &evento);


		//Acaba com o programa 
		if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {

			break;
		}


		//Verifica envento de mouse
		if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			int _x = evento.mouse.x;
			int _y = evento.mouse.y;

			int telaDestino = telaAtual; //Por default se mant�m;

			switch (telaAtual)
			{
			case TELA_INICIO:
				telaDestino = telaInicio->VerificaClique(_x, _y);
				break;

			case TELA_PLACAR:
				telaDestino = telaPlacar->VerificaClique(_x, _y);
				break;

			case TELA_CADASTRO:
				telaDestino = telaCadastro->VerificaClique(_x, _y);
				break;

			case TELA_SAIR:
				//Thrown a error
				jogando = false;
				break;

			default:
				break;
			}

			telaAtual = telaDestino;
		}


		//Verifica envento de teclas pressionadas
		if (evento.type == ALLEGRO_EVENT_KEY_DOWN) {

			switch (evento.keyboard.keycode) {
			case ALLEGRO_KEY_C:
				telaAtual = 0;
				break;
			case ALLEGRO_KEY_X:
				telaAtual = 3;
				break;
			case ALLEGRO_KEY_UP:
				pulo = true;
				break;
			case ALLEGRO_KEY_SPACE:
				pulo = true;
				break;
			}
		}

		//Verifica evento de soltar teclas (Quando se solta a tecla de pulo)
		if (evento.type == ALLEGRO_EVENT_KEY_UP) {
			pulo = false;
		}



		if (evento.type == ALLEGRO_EVENT_TIMER) {

			//Limpa a tela
			al_clear_to_color(al_map_rgb(0, 0, 0));

			//Condicionais para verificar qual tela deve ser mostrada
			switch (telaAtual)
			{
			case 0:
				telaInicio->Render(al_get_display_height(disp), al_get_display_width(disp));
				break;

			case 1:
				telaPlacar->Render(al_get_display_height(disp), al_get_display_width(disp));
				break;

			case 2:
				telaCadastro->Render(al_get_display_height(disp), al_get_display_width(disp));
				break;

			case 3: {
				if (!entrouNaTelaDeJogo) {
					tempoInicialPartida = al_get_time();
					entrouNaTelaDeJogo = true;
				}

				telaJogo->atualizar();
				telaJogo->Render(al_get_display_height(disp), al_get_display_width(disp));
				flappy->Render(al_get_display_height(disp), al_get_display_width(disp), 0);

				if (colidir->colidirT(flappy, telaJogo)) {
					flappy->Restart();
					telaAtual = 0;
					entrouNaTelaDeJogo = false;
					//mandar para a tela de game over
				}

				for (auto cano : telaJogo->getObstaculos()) {
					if (colidir->colidirO(flappy, cano)) {
						flappy->Restart();
						telaAtual = 0;
						entrouNaTelaDeJogo = false;
						//mandar para a tela de game over
					}
				}

				if (pulo) {
					flappy->Render(al_get_display_height(disp), al_get_display_width(disp), 1);

				}

				double tempoAtual = al_get_time() - tempoInicialPartida;
				int scoreAtual = static_cast <int>(tempoAtual);
				std::string nomeJogador = "Teste";
				telaJogo->AtualizarHUD(scoreAtual, tempoAtual, nomeJogador);


				break;
			}
			default:
				entrouNaTelaDeJogo = false;
				break;
			}



		}



		//Renderiza a tela no display
		al_flip_display();

	}

	//Desaloca��o dos objetos
	delete(telaInicio);
	delete(telaCadastro);
	delete(telaPlacar);
	delete(telaJogo);
	delete(flappy);
	delete(colidir);
	


	//Destrui��o dos m�dulos do Allegro
	al_destroy_font(font);
	al_destroy_display(disp);
	al_destroy_timer(timer);
	al_destroy_event_queue(filaEventos);


	return SUCESSO;
}
