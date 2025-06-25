#ifndef IRENDERIZAVEL_H
#define IRENDERIZAVEL_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>


class IRenderizavel {
protected:
	ALLEGRO_BITMAP* sprite;

public:

	virtual void Render(float display_height, float display_width) = 0;

};

#endif


/**Define interface para objetos desenhados nas telas com a função Render())*/