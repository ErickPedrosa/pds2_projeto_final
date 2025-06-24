/*
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../lib/doctest/doctest/doctest.h"
#include <allegro5/allegro.h>

#include "../include/Passaro.hpp"



TEST_CASE("Testando a função de renderização e pulo do objeto passaro") {
	REQUIRE(al_init());

	ALLEGRO_DISPLAY* disp = al_create_display(1280, 800);
	REQUIRE(disp != nullptr);

	Passaro* flappy = new Passaro();

	CHECK(flappy->getX_atual() == 0); //Passaro inicia na posição (0, 0)
	CHECK(flappy->getY_atual() == 0);


	flappy->Render(al_get_display_height(disp), al_get_display_width(disp), 0); //Passaro caindo normalmente
	CHECK(flappy->getX_atual() == 0);
	CHECK(flappy->getY_atual() == 5);


	flappy->Render(al_get_display_height(disp), al_get_display_width(disp), 1); //Passaro pulou
	CHECK(flappy->getX_atual() == 0);
	CHECK(flappy->getY_atual() == -5);


	flappy->Render(al_get_display_height(disp), al_get_display_width(disp), 2); //Passaro se manteve parado
	CHECK(flappy->getX_atual() == 0);
	CHECK(flappy->getY_atual() == -5);

	delete flappy;

	al_destroy_display(disp);
}

*/