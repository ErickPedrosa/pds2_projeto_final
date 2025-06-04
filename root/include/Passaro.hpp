#ifndef PASSARO_H
#define PASSARO_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "../include/IRenderizavel.hpp"

class Passaro : IRenderizavel{
private:
	int x_atual;
	int y_atual;

	//InfoJogadores

public:
	Passaro();
	~Passaro();
	void Render(float display_height, float display_width) override; //int op: 0 - Estado normal (passáro caindo) / 1 - Estado pulando 
	void Render(float display_height, float display_width, int op); //int op: 0 - Estado normal (passáro caindo) / 1 - Estado pulando 

	float getX() const;
	float getY() const;
	float getWidth() const;
	float getHeight() const;

};

#endif