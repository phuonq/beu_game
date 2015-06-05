/*
 * Menuebutton.cpp
 *
 *  Created on: Jun 4, 2015
 *      Author: huynh
 */

#include "Menuebutton.h"

Menue_button::Menue_button() {

}

Menue_button::Menue_button(Game* game, sf::Vector2f size, sf::Vector2f position) {
	this->game = game;
	this->size = size;
	this->position = position;

}

Menue_button::~Menue_button() {
	// TODO Auto-generated destructor stub
}

void Menue_button::draw(const float dt) {
	this->game->window.draw(sprite);
}

void Menue_button::update(const float dt) {

}

bool Menue_button::check_hit(sf::Vector2f hit_position) {
	if(hit_position.x >= this->position.x && hit_position.x <= this->position.x+size.x && hit_position.y >= this->position.y && hit_position.y <= this->position.y+size.y)
		return true;
	return false;
}

void Menue_button::set_game_pointer(Game* game) {
	this->game = game;
	return;
}

void Menue_button::set_size(sf::Vector2f size) {
	this->size = size;
}

void Menue_button::set_position(sf::Vector2f position) {
	this->position = position;
	sprite.setPosition(this->position);
}

void Menue_button::load_textures(const std::string& name, const std::string& path) {
	texmgr.load_texture(name, path);
	return;
}

