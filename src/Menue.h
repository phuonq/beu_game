/*
 * Menue.h
 *
 *  Created on: Jun 4, 2015
 *      Author: huynh
 */

#ifndef MENUE_H_
#define MENUE_H_
#include <SFML/Graphics.hpp>
#include "Game.h"

class Menue {
public:


	void update(const float dt);
	void draw(const float dt);
	int check_hit(sf::Vector2f hit_position);
	Menue();
	virtual ~Menue();

private:

};

#endif /* MENUE_H_ */
