/*

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../lib/doctest/doctest/doctest.h"
#include <allegro5/allegro.h>

#include "../include/GerenciadorCadastro.hpp"



TEST_CASE("Testando a fun��o que devolve os N jogadores com as maiores pontua��es") {


	GerenciadorCadastro* cadastro = new GerenciadorCadastro();

	CHECK(cadastro->TopNJogadores(5).size() == 5);
	CHECK(cadastro->TopNJogadores(10).size() == 10);
	CHECK(cadastro->TopNJogadores(5).size() != 20);

	delete cadastro;

}

*/