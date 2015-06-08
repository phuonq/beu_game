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
#include "Game.h"
#include "Obstacle.h"
#include "Projectile.h"
#include "Champion.h"

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

	Obstacle obstacle;
	Projectile projectile;
	Champion champ;

};

#endif /* GAMESTATEGAME_H_ */
