/*
 * Gamestatestart.h
 *
 *  Created on: Jun 2, 2015
 *      Author: huynh
 */

#ifndef GAMESTATESTART_H_
#define GAMESTATESTART_H_
#include "Game.h"
#include <SFML/Graphics.hpp>
#include "Mouse.h"

class Gamestate_start: public Gamestate {
public:

	Mouse mouse;
	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handle_input();
	Gamestate_start(Game* game);
	virtual ~Gamestate_start();

private:
	sf::View view;
	void load_textures();
	void load_game();
};

#endif /* GAMESTATESTART_H_ */
