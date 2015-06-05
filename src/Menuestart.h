/*
 * Menuestart.h
 *
 *  Created on: Jun 4, 2015
 *      Author: huynh
 */

#ifndef MENUESTART_H_
#define MENUESTART_H_
#include "Menue.h"
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Menuebutton.h"

class Menue_start : public Menue {
public:
	Menue_button play;
	Game* game;

	void update(const float dt);
	void draw(const float dt);
	void set_game_pointer(Game* game);
	int check_hit(sf::Vector2f hit_position);

	Menue_start();
	Menue_start(Game* game);
	virtual ~Menue_start();
};

#endif /* MENUESTART_H_ */
