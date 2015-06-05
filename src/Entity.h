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
#include "Game.h"

class Entity {
public:
	Entity();
	Entity(Game* game, const std::string texture_type, const std::string texture_link);
	Entity(sf::Vector2f position, sf::Vector2f velocity, sf::Vector2f accelaration, sf::Vector2f shape_size, Game* game, const std::string texture_type, const std::string texture_link);
	virtual ~Entity();
	virtual void update(double dt);
	void set_game_pointer(Game* game);
	void draw();
	void load_textures(const std::string texture_type, const std::string texture_link);
	void set_texture(const std::string texture_type);
	void set_position(sf::Vector2f position);
	void set_velocity(sf::Vector2f velocity);
	void set_accelaration(sf::Vector2f accelaration);
	void set_shape_size(sf::Vector2f shape_size);
	void set_hitbox(sf::Vector2f middle_to_sides);
	void load_multiple_textures(const std::string texture_link);
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
	Game* game;
	sf::Sprite sprite;
	Texture_manager texmgr;

};

#endif /* ENTITY_H_ */
