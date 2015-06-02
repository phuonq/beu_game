/*
 * Entity.h
 *
 *  Created on: Jun 1, 2015
 *      Author: phuong
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include <SFML/Graphics.hpp>
#include <list>

class Entity {
public:
	Entity();
	Entity(sf::Vector2f position, sf::Vector2f velocity, sf::Vector2f accelaration, sf::Vector2f shape_size);
	virtual ~Entity();
	virtual void update(double dt);
	void set_position(sf::Vector2f position);
	void set_velocity(sf::Vector2f velocity);
	void set_accelaration(sf::Vector2f accelaration);
	void set_shape_size(sf::Vector2f shape_size);
	void set_hitbox(sf::Vector2f middle_to_sides);
	sf::Vector2f get_position();
	sf::Vector2f get_velocity();
	sf::Vector2f get_accelaration();
	sf::Vector2f get_hitbox();
	sf::RectangleShape get_shape();

protected:
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Vector2f accelaration;
	sf::Vector2f hitbox;
	sf::RectangleShape shape;

};

#endif /* ENTITY_H_ */
