#ifndef GAMEOBJ_H
#define GAMEOBJ_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "IRenderizavel.hpp"

class ObjetoJogo : public  IRenderizavel{
protected:
	int x_atual;
	int y_atual;

public:
	virtual float getX() const { return x_atual; };
	virtual float getY() const { return y_atual; };
	virtual float getWidth() const { return al_get_bitmap_width(sprite); };
	virtual float getHeight() const { return al_get_bitmap_height(sprite); };

};

#endif
