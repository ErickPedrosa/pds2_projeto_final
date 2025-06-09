#ifndef TELADEJOGO_H
#define TELADEJOGO_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "../include/ObjetoJogo.hpp"


class TelaDeJogo : public ObjetoJogo{
protected:
	float escala_w;
	float escala_h;
public:
	TelaDeJogo();
	~TelaDeJogo();
	void Render(float display_height, float display_width) override;
	float getWidth() const override;
	float getHeight() const override;

};

#endif