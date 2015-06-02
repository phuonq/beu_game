/*
 * Obstacle.cpp
 *
 *  Created on: Jun 2, 2015
 *      Author: phuong
 */

#include "Obstacle.h"

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
