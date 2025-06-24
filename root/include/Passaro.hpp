#ifndef PASSARO_H
#define PASSARO_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "../include/ObjetoJogo.hpp"

class Passaro : public ObjetoJogo{
protected:
	int escala;

public:
	Passaro();
	~Passaro();
	void Render(float display_height, float display_width) override; //int op: 0 - Estado normal (passáro caindo) / 1 - Estado pulando 
	void Render(float display_height, float display_width, int op); //int op: 0 - Estado normal (passáro caindo) / 1 - Estado pulando 
	void Restart();

	float getWidth() const override;
	float getHeight() const override;
	float getY() const override;
	float getX() const override;

	float getX_atual() const;
	float getY_atual() const;

};

#endif