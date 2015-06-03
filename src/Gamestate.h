/*
 * gamestate.h
 *
 *  Created on: Jun 2, 2015
 *      Author: huynh
 */

#ifndef GAMESTATE_H_
#define GAMESTATE_H_

#include "Game.h"
#include <SFML/Graphics.hpp>
#include "Gamestate.h"
#include "Texturemanager.h"
class Game;


class Gamestate {
public:

	Game* game;
	sf::Sprite background;
	Texture_manager texmgr;


	virtual void draw(const float dt) = 0;
	virtual void update(const float dt) = 0;
	virtual void handle_input() = 0;

	Gamestate();
	virtual ~Gamestate();

private:
	void load_textures();
};

#endif /* GAMESTATE_H_ */
