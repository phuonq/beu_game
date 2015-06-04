/*
 * Mouse.h
 *
 *  Created on: Jun 4, 2015
 *      Author: huynh
 */

#ifndef MOUSE_H_
#define MOUSE_H_
#include <SFML/Graphics.hpp>
#include "Texturemanager.h"
#include "Game.h"

class Mouse {
public:

	Game* game;
	sf::Sprite sprite;

	void load_textures();
	void update();
	void draw();
	Mouse(Game* game);
	Mouse();
	virtual ~Mouse();
	void set_game_pointer(Game* game);

private:
	Texture_manager texmgr;
	sf::Vector2f position;



};

#endif /* MOUSE_H_ */
