#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_font.h>

#include "../include/TelaInicial.hpp"
#include "../include/TelaDeJogo.hpp"
#include "../include/Passaro.hpp"

#define SUCESSO 0



int main(int argc, char** argv) {
	
	al_init();
	al_install_keyboard();
	
	ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);
	ALLEGRO_EVENT_QUEUE* filaEventos = al_create_event_queue();

	ALLEGRO_DISPLAY* disp = al_create_display(1280, 800);
	

	al_register_event_source(filaEventos, al_get_keyboard_event_source());
	al_register_event_source(filaEventos, al_get_display_event_source(disp));
	al_register_event_source(filaEventos, al_get_timer_event_source(timer));

	ALLEGRO_FONT* font = al_create_builtin_font();

	ALLEGRO_EVENT evento;
	
	TelaInicial* telaInicio = new TelaInicial();
	TelaDeJogo *telaJogo = new TelaDeJogo();
	Passaro* flappy = new Passaro();


	bool inicio = true;
	bool pulo = false;

	al_start_timer(timer);
	while (1)
	{
		al_wait_for_event(filaEventos, &evento);

		//Gerar Tela Inicial ou De Jogo (if)

		if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
			break;
		}


		if (evento.type == ALLEGRO_EVENT_KEY_DOWN) {
			
			switch (evento.keyboard.keycode) {
			case ALLEGRO_KEY_C:
				inicio = false;
				break;
			case ALLEGRO_KEY_X:
				inicio = true;
				break;
			case ALLEGRO_KEY_UP:
				pulo = true;
				break;
			case ALLEGRO_KEY_SPACE:
				pulo = true;
				break;
			}
		}

		if (evento.type == ALLEGRO_EVENT_KEY_UP) {
			pulo = false;
		}

		al_clear_to_color(al_map_rgb(0, 0, 0));


		if (inicio)
		{
			telaInicio->Render(al_get_display_height(disp), al_get_display_width(disp));
			
		}
		else
		{
			telaJogo->Render(al_get_display_height(disp), al_get_display_width(disp));
			flappy->Render(al_get_display_height(disp), al_get_display_width(disp), 0);


			if (pulo) {
				flappy->Render(al_get_display_height(disp), al_get_display_width(disp), 1);
			}
		}
		
		al_flip_display();

	}

	delete(telaInicio);
	delete(telaJogo);

	al_destroy_font(font);
	al_destroy_display(disp);
	al_destroy_timer(timer);
	al_destroy_event_queue(filaEventos);


	return SUCESSO;
}

