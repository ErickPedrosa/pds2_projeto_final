#include "../include/TelaPlacar.hpp"
#include <iostream>
#include <tuple>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>


#define TELA_INICIO 0
#define TELA_PLACAR 1
#define TELA_CADASTRO 2
#define TELA_JOGO 3
#define TELA_SAIR -1


TelaPlacar::TelaPlacar(float display_height, float display_width){
    x_atual = 0;
    y_atual = 0;
    
    if (!al_init_image_addon())
    {
        std::cout << "couldn't initialize image addon" << std::endl;
        //Trown error
    }

    if (!al_init_ttf_addon()) {
        std::cout << "Erro ao inicializar TTF" << std::endl;
    }


    sprite = al_load_bitmap("assets/background-night.png");

    fonteBotaoP = al_load_ttf_font("assets/VT323-Regular.ttf", 28, 0);
    if (!fonteBotaoP) {
        std::cout << "Erro ao carregar fonte personalizada!" << std::endl;
        fonteBotaoP = al_create_builtin_font();
    }


    int botao_height = 60;
    int botao_width = 220;



    voltar = new Botao((display_width / 2) - (botao_width / 2), (display_height / 2) + 200,
        botao_width, botao_height, al_map_rgb(0,179,179),
        "Voltar", fonteBotaoP, al_map_rgb(255,255,204)
    );

}


TelaPlacar::~TelaPlacar() {
    al_destroy_bitmap(sprite);
    al_destroy_font(fonteBotaoP);

    delete(voltar);


}

int TelaPlacar::VerificaClique(int _x, int _y) {

    if (voltar->FoiClicado(_x, _y)) {
        return TELA_INICIO;
    }
    else {
        return TELA_PLACAR;
    }

}


void TelaPlacar::Render(float display_height, float display_width, std::vector<std::tuple<std::string, int, int>> topJogadores, int num_linhas) {
    this->Render(display_height, display_width); // Renderiza o fundo da tela, se necessário

    int col_width = 200;
    int row_height = 40;

    // Centraliza a tabela horizontalmente e coloca ela mais embaixo verticalmente
    int x = (display_width / 2) - ((col_width * 3) / 2);
    int y = (display_height / 2) - ((row_height * num_linhas) / 2);

    ALLEGRO_FONT* fonteTabela = al_load_ttf_font("assets/VT323-Regular.ttf", 22, 0);
    if (!fonteTabela) {
        std::cout << "Erro ao carregar fonte da tabela" << std::endl;
        return;
    }

    
    ALLEGRO_COLOR corTexto = al_map_rgb(0,0,77);
    ALLEGRO_COLOR corBorda = al_map_rgb(0,0,77);
    ALLEGRO_COLOR corFundo = al_map_rgb(255,255,204);

    int cy_header = y;  // mesma base vertical
    int cx = x;

    std::vector<std::string> headers = { "Nome", "High Score", "N. Jogos" };

    for (int col = 0; col < headers.size(); ++col) {
        cx = x + col * col_width;
        al_draw_filled_rectangle(cx, cy_header, cx + col_width, cy_header + row_height, corFundo);
        al_draw_rectangle(cx, cy_header, cx + col_width, cy_header + row_height, corBorda, 1);
        al_draw_text(fonteTabela, corTexto, cx + col_width / 2,
            cy_header + row_height / 2 - al_get_font_line_height(fonteTabela) / 2,
            ALLEGRO_ALIGN_CENTER, headers[col].c_str());
    }


    int i = 0;
    for (const auto& jogador : topJogadores) {
        int cy = y + (i + 1) * row_height;

        // Nome
        int cx = x + 0 * col_width;
        al_draw_filled_rectangle(cx, cy, cx + col_width, cy + row_height, corFundo);
        al_draw_rectangle(cx, cy, cx + col_width, cy + row_height, corBorda, 1);
        al_draw_text(fonteTabela, corTexto, cx + col_width / 2,
            cy + row_height / 2 - al_get_font_line_height(fonteTabela) / 2,
            ALLEGRO_ALIGN_CENTER, std::get<0>(jogador).c_str());

        // Pontuação
        cx = x + 1 * col_width;
        al_draw_filled_rectangle(cx, cy, cx + col_width, cy + row_height, corFundo);
        al_draw_rectangle(cx, cy, cx + col_width, cy + row_height, corBorda, 1);
        al_draw_text(fonteTabela, corTexto, cx + col_width / 2,
            cy + row_height / 2 - al_get_font_line_height(fonteTabela) / 2,
            ALLEGRO_ALIGN_CENTER, std::to_string(std::get<1>(jogador)).c_str());

        // Número de jogos
        cx = x + 2 * col_width;
        al_draw_filled_rectangle(cx, cy, cx + col_width, cy + row_height, corFundo);
        al_draw_rectangle(cx, cy, cx + col_width, cy + row_height, corBorda, 1);
        al_draw_text(fonteTabela, corTexto, cx + col_width / 2,
            cy + row_height / 2 - al_get_font_line_height(fonteTabela) / 2,
            ALLEGRO_ALIGN_CENTER, std::to_string(std::get<2>(jogador)).c_str());

        i++;
    }

    al_destroy_font(fonteTabela); 
}


void TelaPlacar::Render(float display_height, float display_width) {



    int img_w = this->getWidth();
    int img_h = this->getHeight();


    int num_tiles = 5;

    float escala_w = display_width / ((num_tiles - 1) * img_w);
    float escala_h = display_height / img_h;


    x_atual -= 1;
    if (x_atual <= -img_w * escala_w) {
        x_atual += img_w * escala_w;
    }

    for (int i = 0; i < num_tiles; i++) {
        float dx = (i * img_w * escala_w) + x_atual;
        float dy = 0;

        al_draw_scaled_bitmap(
            sprite,
            0, 0, img_w, img_h,
            dx, dy,
            img_w * escala_w,
            img_h * escala_h,
            0
        );
    }

    voltar->GerarBotao();


}

/**Exibe o fundo da tela de placar
- Mostra uma tabela com os melhores jogadores
- Verifica cliques no botão "Voltar"*/