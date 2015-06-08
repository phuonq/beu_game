/*
 * Champion.h
 *
 *  Created on: Jun 2, 2015
 *      Author: phuong
 */

#ifndef CHAMPION_H_
#define CHAMPION_H_

#include "Entity.h"

#define texture_link_champ "textures/Champions/"

class Champion: public Entity {
public:
	Champion();
	virtual ~Champion();
	Champion(sf::Vector2f position, sf::Vector2f velocity, sf::Vector2f accelaration, sf::Vector2f shape_size, Game* game, std::string texture_url, int texture_number)
		: Entity(position,velocity,accelaration,shape_size,game,texture_url,texture_number){};
	void add_Champion(Champion champ);
	void remove_Champion(std::vector<Champion>::iterator it);
	std::vector<Champion>::iterator get_pointer_on_first_element();
	std::vector<Champion>::iterator get_pointer_on_last_element();
	void draw_all_champions(const float dt);
	void update_all_champions(const float dt);
	double get_health();
	double get_mana();
	double get_armor();
	double get_magic_resist();
	double get_attack_damage();
	double get_ability_power();
	double get_movement_speed();
	double get_attack_speed();
	void set_all_parameters(double health, double mana, double armor, double magic_resist, double attack_damage, double ability_power, double movement_speed, double attack_speed);
	void set_health(double health);
	void set_mana(double mana);
	void set_armor(double armor);
	void set_magic_resist(double magic_resist);
	void set_attack_damage(double attack_damage);
	void set_ability_power(double ability_power);
	void set_movement_speed(double movement_speed);
	void set_attack_speed(double attack_speed);

private:
	static std::vector<Champion> list;
	double health;
	double mana;
	sf::Vector2f jump_accelaration;
	double magic_resist;
	double attack_damage;
	double ability_power;
	double movement_speed;
	double attack_speed;
	double armor;

};

#endif /* CHAMPION_H_ */
