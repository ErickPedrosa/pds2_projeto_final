/*
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../lib/doctest/doctest/doctest.h"
#include <allegro5/allegro.h>

#include "../include/Colisao.hpp"
#include "../include/Passaro.hpp"
#include "../include/TelaDeJogo.hpp"
#include "../include/Obstaculo.hpp"



TEST_CASE("Testando a colis�o com a tela") {
	REQUIRE(al_init());

	ALLEGRO_DISPLAY* disp = al_create_display(1280, 800);
	REQUIRE(disp != nullptr);

	Passaro* flappy = new Passaro();
	TelaDeJogo* tela = new TelaDeJogo();
	Colisao* colisao = new Colisao();

	CHECK(colisao->colidirT(flappy, tela) == false); //Passaro inicia na posi��o (0, 0) -> N�o est� colidindo



	flappy->Render(al_get_display_height(disp), al_get_display_width(disp), 0); //Passaro caindo normalmente -> N�o est� colidindo
	CHECK(colisao->colidirT(flappy, tela) == false); 



	for (int i = 0; i < flappy->getHeight(); i++){
		flappy->Render(al_get_display_height(disp), al_get_display_width(disp), 1); //Passaro pulou at� sair da tela -> Colide
	}
	CHECK(colisao->colidirT(flappy, tela) == true); 



	flappy->Render(al_get_display_height(disp), al_get_display_width(disp), 2); //Passaro se manteve parado -> Continua colidindo
	CHECK(colisao->colidirT(flappy, tela) == true); 



	for (int i = 0; i < flappy->getHeight() * 2; i++)
	{
		flappy->Render(al_get_display_height(disp), al_get_display_width(disp), 0); //Passaro caindo at� voltar -> N�o est� colidindo
	}
	CHECK(colisao->colidirT(flappy, tela) == false);



	for (int i = 0; i < flappy->getHeight() + al_get_display_height(disp); i++)
	{
		flappy->Render(al_get_display_height(disp), al_get_display_width(disp), 0); //Passaro caindo at� sair da tela novamente -> N�o est� colidindo
	}
	CHECK(colisao->colidirT(flappy, tela) == true);


	delete flappy;
	delete tela;
	delete colisao;

	al_destroy_display(disp);
}



TEST_CASE("Testando a colis�o com a tela") {
	REQUIRE(al_init());

	ALLEGRO_DISPLAY* disp = al_create_display(1280, 800);
	REQUIRE(disp != nullptr);

	Passaro* flappy = new Passaro();
	Obstaculo* obstaculo = new Obstaculo(162, al_get_display_height(disp), 100);
	Colisao* colisao = new Colisao();


	CHECK(colisao->colidirO(flappy, obstaculo) == true); //Passaro e o Obstaculo iniciados na mesma posi��o -> Est� colidindo

	delete obstaculo;
	obstaculo = new Obstaculo(400, al_get_display_height(disp), 100);

	CHECK(colisao->colidirO(flappy, obstaculo) == false); //Passaro e o Obstaculo iniciados em posi��es diferentes -> N�o est� colidindo


	delete flappy;
	delete obstaculo;
	delete colisao;

	al_destroy_display(disp);
}

*/
