#ifndef TELAINICIAL_H
#define TELAINICIAL_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>


class TelaInicial {
	private:
		int x_atual;
		int y_atual;
		ALLEGRO_BITMAP* fundo;
		//InfoJogadores

	public:
		TelaInicial();
		~TelaInicial();
		void Render(float display_height, float display_width);


};

#endif