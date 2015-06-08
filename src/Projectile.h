/*
 * Projectile.h
 *
 *  Created on: Jun 2, 2015
 *      Author: phuong
 */

#ifndef PROJECTILE_H_
#define PROJECTILE_H_

#include "Entity.h"

#define texture_link_proj "textures/Projectiles/"

class Projectile: public Entity {
public:
	Projectile();
	Projectile(sf::Vector2f position, sf::Vector2f velocity, sf::Vector2f accelaration, sf::Vector2f shape_size, Game* game, std::string texture_url, int texture_number)
		: Entity(position,velocity,accelaration,shape_size,game,texture_url,texture_number){};
	virtual ~Projectile();
	void add_Projectile(Projectile projectile);
	void remove_Projectile(std::vector<Projectile>::iterator it);
	std::vector<Projectile>::iterator get_pointer_on_first_element();
	std::vector<Projectile>::iterator get_pointer_on_last_element();
	void draw_all_projectiles(const float dt);
	void update_all_projectiles(const float dt);
	void set_damage(double damage);
	void set_force(sf::Vector2f force);
	sf::Vector2f get_force();
	double get_damage();

private:
	static std::vector<Projectile> list;
	double damage;
	sf::Vector2f force;

};

#endif /* PROJECTILE_H_ */
