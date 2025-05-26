#ifndef TELAINICIAL_H
#define TELAINICIAL_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "../include/IRenderizavel.hpp"


class TelaInicial : IRenderizavel {
	private:
		int x_atual;
		int y_atual;
		//InfoJogadores

	public:
		TelaInicial();
		~TelaInicial();
		void Render(float display_height, float display_width) override;


};

#endif