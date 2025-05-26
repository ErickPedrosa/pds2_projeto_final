#ifndef TELADEJOGO_H
#define TELADEJOGO_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>


class TelaDeJogo {
private:
	int x_atual;
	int y_atual;
	ALLEGRO_BITMAP* fundo;
	//InfoJogadores

public:
	TelaDeJogo();
	~TelaDeJogo();
	void Render(float display_height, float display_width);


};

#endif