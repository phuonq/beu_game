/*
 * Projectile.cpp
 *
 *  Created on: Jun 2, 2015
 *      Author: phuong
 */

#include "Projectile.h"

std::vector<Projectile> Projectile::list;

Projectile::Projectile() {
	this->load_multiple_textures(texture_link_proj);
}

Projectile::~Projectile() {

}

void Projectile::add_Projectile(Projectile obstacle) {
	this->list.push_back(obstacle);
}

void Projectile::remove_Projectile(std::vector<Projectile>::iterator it) {
	this->list.erase(it);
}

std::vector<Projectile>::iterator Projectile::get_pointer_on_first_element() {
	return this->list.begin();
}

std::vector<Projectile>::iterator Projectile::get_pointer_on_last_element() {
	return this->list.end();
}

void Projectile::draw_all_projectiles(const float dt) {
	std::vector<Projectile>::iterator first = get_pointer_on_first_element();
	std::vector<Projectile>::iterator last = get_pointer_on_last_element();
	std::vector<Projectile>::iterator it;

	for (it = first; it != last; it++) {
		it->game->window.draw(it->sprite);
	}
}
void Projectile::update_all_projectiles(const float dt) {
	std::vector<Projectile>::iterator first = get_pointer_on_first_element();
	std::vector<Projectile>::iterator last = get_pointer_on_last_element();
	std::vector<Projectile>::iterator it;

	for (it = first; it != last; it++) {
		it->sprite.setTexture((it->texmgr.get_ref(it->texture_list[it->texture_number])));
		it->update(dt);
	}
}

double Projectile::get_damage() {
	return this->damage;
}

sf::Vector2f Projectile::get_force() {
	return this->force;
}

void Projectile::set_damage(double damage) {
	this->damage = damage;
}

void Projectile::set_force(sf::Vector2f force) {
	this->force.x = force.x;
	this->force.y = force.y;
}




