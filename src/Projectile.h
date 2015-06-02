/*
 * Projectile.h
 *
 *  Created on: Jun 2, 2015
 *      Author: phuong
 */

#ifndef PROJECTILE_H_
#define PROJECTILE_H_

#include "Entity.h"

class Projectile: public Entity {
public:
	Projectile();
	virtual ~Projectile();

private:
	double health;
	double mana;
	sf::Vector2f jump_accelaration;
};

#endif /* PROJECTILE_H_ */
