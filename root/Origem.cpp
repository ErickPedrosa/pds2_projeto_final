//Main para teste do programa;

#include <allegro5/allegro.h>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "Lib/doctest/doctest/doctest.h"

int fact(int n) {
	return n <= 1 ? n : fact(n - 1) * n;
}

TEST_CASE("Testing the fatorial function") {
	CHECK(fact(0) == 1);
	CHECK(fact(1) == 1);
	CHECK(fact(2) == 2);
	CHECK(fact(3) == 6);
	CHECK(fact(10) == 3628800);

}