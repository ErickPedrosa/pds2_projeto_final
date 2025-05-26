#ifndef TELADEJOGO_H
#define TELADEJOGO_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "../include/IRenderizavel.hpp"


class TelaDeJogo : IRenderizavel{
private:
	int x_atual;
	int y_atual;
	//InfoJogadores

public:
	TelaDeJogo();
	~TelaDeJogo();
	void Render(float display_height, float display_width) override;


};

#endif