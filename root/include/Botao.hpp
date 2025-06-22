#ifndef BOTAO_H
#define BOTAO_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <string>

struct Botao
{
	int x, y;
	int height, width;
	ALLEGRO_COLOR cor;
	std::string descricao;
	ALLEGRO_FONT* fonte;
	ALLEGRO_COLOR corDoTexto;

	Botao(int _x, int _y, int _w, int _h, ALLEGRO_COLOR _cor,
		const std::string& _descricao, ALLEGRO_FONT* _fonte, ALLEGRO_COLOR _corDoTexto)
		: x(_x), y(_y), width(_w), height(_h), cor(_cor),
		descricao(_descricao), fonte(_fonte), corDoTexto(_corDoTexto) {
	}

	void GerarBotao() {

		al_draw_filled_rectangle(x, y, x + width, y + height, cor);

		al_draw_text(fonte, corDoTexto,
			x + width / 2,
			y + height / 2 - al_get_font_line_height(fonte) / 2,
			ALLEGRO_ALIGN_CENTER, descricao.c_str()
		);

	}

	bool FoiClicado(int mouse_x, int mouse_y) {
		return (mouse_x >= x && mouse_x <= x + width &&
			mouse_y >= y && mouse_y <= y + height);
	}



};


#endif