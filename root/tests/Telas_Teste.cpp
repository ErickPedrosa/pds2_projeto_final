/*

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../lib/doctest/doctest/doctest.h"
#include <allegro5/allegro.h>

#include "../include/TelaInicial.hpp"
#include "../include/TelaCadastro.hpp"
#include "../include/TelaPlacar.hpp"
#include "../include/TelaGameOver.hpp"

#define TELA_INICIO 0
#define TELA_PLACAR 1
#define TELA_CADASTRO 2
#define TELA_JOGO 3
#define TELA_SAIR -1
#define TELA_GAMEOVER 4


TEST_CASE("Testando a função de verificar clique nos botões (Tela Inicial)") {
	REQUIRE(al_init());

	ALLEGRO_DISPLAY* disp = al_create_display(1280, 800);
	REQUIRE(disp != nullptr);

	TelaInicial* telaInicio = new TelaInicial(al_get_display_height(disp), al_get_display_width(disp));



	CHECK(telaInicio->VerificaClique(670, 341) == TELA_CADASTRO); //Coordenadas do botão jogar
	CHECK(telaInicio->VerificaClique(668, 436) == TELA_PLACAR); //Coordenadas do botão placar
	CHECK(telaInicio->VerificaClique(638, 513) == TELA_SAIR); //Coordenadas do botão sair
	CHECK(telaInicio->VerificaClique(200, 700) == TELA_INICIO); //Coordenadas da tela sem botão 
	CHECK(telaInicio->VerificaClique(800, 100) == TELA_INICIO); //Coordenadas da tela sem botão
	


	delete(telaInicio);
	al_destroy_display(disp);
}


TEST_CASE("Testando a função de verificar clique nos botões (Tela Cadastro)") {
	REQUIRE(al_init());

	ALLEGRO_DISPLAY* disp = al_create_display(1280, 800);
	REQUIRE(disp != nullptr);

	TelaCadastro* telaCadastro = new TelaCadastro(al_get_display_height(disp), al_get_display_width(disp));



	CHECK(telaCadastro->VerificaClique(577, 433) == TELA_JOGO); //Coordenadas do botão jogar
	CHECK(telaCadastro->VerificaClique(668, 527) == TELA_INICIO); //Coordenadas do botão voltar
	CHECK(telaCadastro->VerificaClique(50, 50) == TELA_CADASTRO); //Coordenadas da tela sem botão
	CHECK(telaCadastro->VerificaClique(200, 700) == TELA_CADASTRO); //Coordenadas da tela sem botão 
	CHECK(telaCadastro->VerificaClique(800, 100) == TELA_CADASTRO); //Coordenadas da tela sem botão




	delete(telaCadastro);
	al_destroy_display(disp);
}


TEST_CASE("Testando a função de verificar clique nos botões (Tela Placar)") {
	REQUIRE(al_init());

	ALLEGRO_DISPLAY* disp = al_create_display(1280, 800);
	REQUIRE(disp != nullptr);

	TelaPlacar* telaPlacar = new TelaPlacar(al_get_display_height(disp), al_get_display_width(disp));



	CHECK(telaPlacar->VerificaClique(640, 635) == TELA_INICIO); //Coordenadas do botão jogar
	CHECK(telaPlacar->VerificaClique(2000, 1000) == TELA_PLACAR); //Coordenadas da tela sem botão 
	CHECK(telaPlacar->VerificaClique(200, 700) == TELA_PLACAR); //Coordenadas da tela sem botão 
	CHECK(telaPlacar->VerificaClique(800, 100) == TELA_PLACAR); //Coordenadas da tela sem botão



	delete(telaPlacar);
	al_destroy_display(disp);
}


TEST_CASE("Testando a função de verificar clique nos botões (Tela Game-Over)") {
	REQUIRE(al_init());

	ALLEGRO_DISPLAY* disp = al_create_display(1280, 800);
	REQUIRE(disp != nullptr);

	TelaGameOver* telaGameOver = new TelaGameOver(al_get_display_height(disp), al_get_display_width(disp));



	CHECK(telaGameOver->VerificaClique(714, 485) == TELA_JOGO); //Coordenadas do botão reiniciar
	CHECK(telaGameOver->VerificaClique(645, 583) == TELA_INICIO); //Coordenadas do botão voltar para o inicio
	CHECK(telaGameOver->VerificaClique(50, 650) == TELA_PLACAR); //Coordenadas da tela sem botão 
	CHECK(telaGameOver->VerificaClique(800, 100) == TELA_PLACAR); //Coordenadas da tela sem botão
	CHECK(telaGameOver->VerificaClique(10, 1000) == TELA_PLACAR); //Coordenadas da tela sem botão



	delete(telaGameOver);
	al_destroy_display(disp);
}


*/

