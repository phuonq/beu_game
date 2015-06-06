/*
 * Obstacle.cpp
 *
 *  Created on: Jun 2, 2015
 *      Author: phuong
 */

#include "Obstacle.h"

std::vector<Obstacle> Obstacle::list;

Obstacle::Obstacle() {

}

Obstacle::~Obstacle() {

}

void Obstacle::add_Obstacle(Obstacle obstacle) {
	this->list.push_back(obstacle);
}

void Obstacle::remove_Obstacle(std::vector<Obstacle>::iterator it) {
	this->list.erase(it);
	this->~Obstacle();
}

std::vector<Obstacle>::iterator Obstacle::get_pointer_on_first_element() {
	return this->list.begin();
}

std::vector<Obstacle>::iterator Obstacle::get_pointer_on_last_element() {
	return this->list.end();
}

void Obstacle::draw_all_obstacles(const float dt) {
	std::vector<Obstacle>::iterator first = get_pointer_on_first_element();
	std::vector<Obstacle>::iterator last = get_pointer_on_last_element();
	std::vector<Obstacle>::iterator it;

	for (it = first; it != last; it++) {
		it->game->window.draw(it->sprite);
	}
}
void Obstacle::update_all_obstacles(const float dt) {
	std::vector<Obstacle>::iterator first = get_pointer_on_first_element();
	std::vector<Obstacle>::iterator last = get_pointer_on_last_element();
	std::vector<Obstacle>::iterator it;

	for (it = first; it != last; it++) {
		it->update(dt);
	}
}
