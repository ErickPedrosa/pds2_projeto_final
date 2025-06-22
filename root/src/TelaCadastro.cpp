#include "../include/TelaCadastro.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>


#define TELA_INICIO 0
#define TELA_PLACAR 1
#define TELA_CADASTRO 2
#define TELA_JOGO 3
#define TELA_SAIR -1


TelaCadastro::TelaCadastro(float display_height, float display_width){
    x_atual = 0;
    y_atual = 0;

    if (!al_init_image_addon())
    {
        std::cout << "couldn't initialize image addon" << std::endl;
        //Trown error
    }

    sprite = al_load_bitmap("assets/background-night.png");

    int botao_height = 100;
    int botao_width = 300;

    fonte = al_create_builtin_font();

    std::srand(std::time(nullptr)); 
    int numero = 1000 + std::rand() % 9000;
    std::string placeholder = "Jogador" + std::to_string(numero);



    input = new CaixaDeTexto(
        (display_width / 2) - (botao_width / 2), (display_height / 2) - (botao_height * 1.5),
        botao_width, botao_height / 2,
        al_map_rgb(255, 255, 255),           
        al_map_rgb(0, 0, 0),                 
        fonte,
        placeholder
    );

    logar = new Botao((display_width / 2) - (botao_width / 2), (display_height / 2),
        botao_width, botao_height, al_map_rgb(255, 255, 255),
        "Logar", fonte, al_map_rgb(0, 0, 0)
    );

    voltar = new Botao((display_width / 2) - (botao_width / 2), (display_height / 2) + (botao_height * 1.5),
        botao_width, botao_height, al_map_rgb(255, 255, 255),
        "Voltar", fonte, al_map_rgb(0, 0, 0)
    );

}




TelaCadastro::~TelaCadastro() {
    al_destroy_bitmap(sprite);


    delete(input);
    delete(logar);
    delete(voltar);
    

    
    al_destroy_font(fonte);
    
    

}

int TelaCadastro::VerificaClique(int _x, int _y) {
    if (logar->FoiClicado(_x, _y)) {
        return TELA_JOGO;
    }


    if (voltar->FoiClicado(_x, _y)) {
        return TELA_INICIO; 
    }

    input->Ativar(input->FoiClicado(_x, _y));

    return TELA_CADASTRO;
}

void TelaCadastro::VerificaDigitacao(ALLEGRO_EVENT evento) {
    if (input->EstaAtivado())
    {
        if (evento.keyboard.unichar >= 32 && evento.keyboard.unichar <= 126) {
            input->texto += static_cast<char>(evento.keyboard.unichar);
        }
        else if (evento.keyboard.keycode == ALLEGRO_KEY_BACKSPACE && !input->texto.empty()) {
            input->texto.pop_back();
        }
    }
    
}


void TelaCadastro::Render(float display_height, float display_width) {



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

    logar->GerarBotao();
    voltar->GerarBotao();
    input->Desenhar();


}