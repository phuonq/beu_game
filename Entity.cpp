/*
 * Entity.cpp
 *
 *  Created on: Jun 1, 2015
 *      Author: phuong
 */

#include "Entity.h"

Entity::Entity() {

}

Entity::Entity(double position[], double velocity[], double accelaration[]) {
	this->position.assign (position,position+2);
	this->velocity.assign (velocity,velocity+2);
	this->accelaration.assign (accelaration,accelaration+2);
}

Entity::~Entity() {
	// TODO Auto-generated destructor stub
}

void Entity::update(double dt) {
	for(int i=0; i<2; i++) {
		position[i] += velocity[i] * dt;
	}
}

void Entity::set_accelaration(double accelaration[]) {
	this->accelaration.assign (accelaration,accelaration+2);
}

void Entity::set_position(double position[]) {
	this->position.assign (position,position+2);
}

void Entity::set_velocity(double velocity[]) {
	this->velocity.assign (velocity,velocity+2);
}

std::vector<double> Entity::get_position() {
	return this->position;
}

std::vector<double> Entity::get_velocity() {
	return this->velocity;
}

std::vector<double> Entity::get_accelaration() {
	return this->position;
}
