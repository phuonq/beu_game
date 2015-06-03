/*
 * game.h
 *
 *  Created on: Jun 2, 2015
 *      Author: huynh
 */

#ifndef GAME_H_
#define GAME_H_


#include <SFML/Graphics.hpp>
#include <stack>
#include "Gamestate.h"
#include "Texturemanager.h"

class Gamestate;

class Game {
public:

	std::stack<Gamestate*> states;
	sf::RenderWindow window;
	//sf::Sprite background;
	//Texture_manager texmgr;

	void push_state(Gamestate* state);
	void pop_state();
	void change_state(Gamestate* state);
	Gamestate* peek_state();

	void game_loop();

	Game();
	~Game();

private:
	//void load_textures();
};

#endif /* GAME_H_ */
