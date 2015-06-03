#include "src/Game.h"
#include "src/Gamestatestart.h"
#include "src/Gamestategame.h"

int main()
{


	Game game;

	game.push_state(new Gamestate_start(&game));
	game.game_loop();

	return 0;
}
