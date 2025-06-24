#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../lib/doctest/doctest/doctest.h"
#include <allegro5/allegro.h>

#include "../include/TelaInicial.hpp"
#include "../include/TelaCadastro.hpp"
#include "../include/TelaPlacar.hpp"
#include "../include/TelaDeJogo.hpp"
#include "../include/TelaGameOver.hpp"

#define TELA_INICIO 0
#define TELA_PLACAR 1
#define TELA_CADASTRO 2
#define TELA_JOGO 3
#define TELA_SAIR -1
#define TELA_GAMEOVER 4

/*
TelaCadastro* telaCadastro = new TelaCadastro(al_get_display_height(disp), al_get_display_width(disp));
TelaPlacar* telaPlacar = new TelaPlacar(al_get_display_height(disp), al_get_display_width(disp));
TelaDeJogo* telaJogo = new TelaDeJogo();
TelaGameOver* telaGameOver = new TelaGameOver(al_get_display_height(disp), al_get_display_width(disp));
*/

TEST_CASE("Testando a função de verificar clique nos botões (Tela Inicial)") {
	REQUIRE(al_init());

	ALLEGRO_DISPLAY* disp = al_create_display(1280, 800);
	REQUIRE(disp != nullptr);

	TelaInicial* telaInicio = new TelaInicial(al_get_display_height(disp), al_get_display_width(disp));



	CHECK(telaInicio->VerificaClique(670, 341) == TELA_CADASTRO);
	CHECK(telaInicio->VerificaClique(668, 436) == TELA_PLACAR);
	CHECK(telaInicio->VerificaClique(638, 513) == TELA_SAIR);
	CHECK(telaInicio->VerificaClique(200, 700) == TELA_INICIO);
	CHECK(telaInicio->VerificaClique(800, 100) == TELA_INICIO);
	


	delete(telaInicio);
	al_destroy_display(disp);
}


/*

delete(telaCadastro);
delete(telaPlacar);
delete(telaJogo);
delete telaGameOver;
*/

