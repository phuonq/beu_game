/*
 * Gamestategame.h
 *
 *  Created on: Jun 3, 2015
 *      Author: huynh
 */

#ifndef GAMESTATEGAME_H_
#define GAMESTATEGAME_H_
#include <SFML/Graphics.hpp>
#include "Gamestate.h"

class Gamestate_game : public Gamestate {
public:
	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handle_input();
	Gamestate_game(Game* game);
	virtual ~Gamestate_game();
	void set_escape_flag();
private:
	sf::View game_view;
	sf::View gui_view;
	void load_textures();
	int escape_flag;

};

#endif /* GAMESTATEGAME_H_ */
