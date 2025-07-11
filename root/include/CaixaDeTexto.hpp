/**Armazena texto digitado
- Identifica se foi clicada
- Controla estado de ativacao
- Desenha interface de entrada de texto*/

#ifndef CAIXADETEXTO_H
#define CAIXADETEXTO_H


#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <string>

class CaixaDeTexto {
protected:
    int x, y, width, height;
    bool ativa;

    ALLEGRO_COLOR corFundo;
    ALLEGRO_COLOR corTexto;
    ALLEGRO_FONT* fonte;

public:
    std::string texto;



    CaixaDeTexto(int _x, int _y, int _w, int _h,
        ALLEGRO_COLOR _corFundo,
        ALLEGRO_COLOR _corTexto,
        ALLEGRO_FONT* _fonte,
        const std::string& _texto)
        : 
        x(_x), y(_y), width(_w), height(_h),
        corFundo(_corFundo), corTexto(_corTexto),
        fonte(_fonte),
        ativa(false), texto(_texto) {
    }


    bool FoiClicado(int mouse_x, int mouse_y) {
        return (mouse_x >= x && mouse_x <= x + width &&
            mouse_y >= y && mouse_y <= y + height);
    }

    void Ativar(bool estado) {
        ativa = estado;
    }

    bool EstaAtivado() const {
        return ativa;
    }

    std::string ObterTexto() const {
        return texto;
    }

    void Desenhar() {
        float raio = 6.0f;  
        // Fundo arredondado
        al_draw_filled_rounded_rectangle(x, y, x + width, y + height, raio, raio, corFundo);

        // Borda arredondada
        al_draw_rounded_rectangle(x, y, x + width, y + height, raio, raio, al_map_rgb(0, 0, 77), 1);

        std::string exibido = texto;
        ALLEGRO_COLOR cor = corTexto;

        al_draw_text(fonte, cor, x + width/2, y + height / 2 - al_get_font_line_height(fonte) / 2, ALLEGRO_ALIGN_CENTER,
           exibido.c_str());
    }

 };


#endif

