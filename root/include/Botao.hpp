/** Desenha o botão com aparência estilizada (GerarBotao)
- Verifica se foi clicado com coordenadas do mouse (FoiClicado)*/

#ifndef BOTAO_H
#define BOTAO_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
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
		float raio = 20.0;

		//Constrate deslocado para botao
		al_draw_filled_rounded_rectangle(x + 2, y + 2, x + width + 2, y + height + 2, raio, raio, al_map_rgba(0, 0, 0, 80));
		// Cor de fundo
		al_draw_filled_rounded_rectangle(x, y, x + width, y + height, raio, raio, cor);
		//Borda para contraste
		al_draw_rounded_rectangle(x, y, x + width, y + height, raio, raio, al_map_rgb(0, 0, 77), 1);
		
		

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

