/*
 * Entity.cpp
 *
 *  Created on: Jun 1, 2015
 *      Author: phuong
 */

#include "Entity.h"

Entity::Entity() {

}

Entity::Entity(sf::Vector2f position, sf::Vector2f velocity, sf::Vector2f accelaration, sf::Vector2f shape_size) {
	this->position = position;
	this->velocity = velocity;
	this->accelaration = accelaration;
	this->shape.setSize(shape_size);
	this->shape.setPosition(position);
	this->hitbox.x = shape_size.x/2;
	this->hitbox.y = shape_size.y/2;
}

Entity::~Entity() {
	// TODO Auto-generated destructor stub
}

void Entity::update(double dt) {
	velocity.x += accelaration.x * dt;
	velocity.y += accelaration.y * dt;
	shape.move(velocity);
}

void Entity::set_hitbox(sf::Vector2f middle_to_sides) {
	this->hitbox = middle_to_sides;
}

void Entity::set_shape_size(sf::Vector2f shape_size) {
	this->shape.setSize(shape_size);
}

void Entity::set_accelaration(sf::Vector2f accelaration) {
	this->accelaration = accelaration;
}

void Entity::set_position(sf::Vector2f position) {
	this->position = position;
}

void Entity::set_velocity(sf::Vector2f velocity) {
	this->velocity = velocity;
}

sf::Vector2f Entity::get_position() {
	return this->position;
}

sf::Vector2f Entity::get_velocity() {
	return this->velocity;
}

sf::Vector2f Entity::get_accelaration() {
	return this->position;
}

sf::RectangleShape Entity::get_shape() {
	return this->shape;
}

sf::Vector2f Entity::get_hitbox() {
	return this->hitbox;
}
