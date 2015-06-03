#include "Game.h"
#include "Gamestatestart.h"
#include "Gamestategame.h"

int main()
{


	Game game;

	game.push_state(new Gamestate_start(&game));
	game.game_loop();

	return 0;
}
