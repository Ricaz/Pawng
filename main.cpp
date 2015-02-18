#include "Game.hpp"
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));
	Game::Init();	
	return 0;
}
