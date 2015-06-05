/*
 * Mouse.cpp
 *
 *  Created on: Jun 4, 2015
 *      Author: huynh
 */

#include "Mouse.h"

Mouse::Mouse(Game* game) {
	this->game = game;
	load_textures();
	this->sprite.setTexture(this->texmgr.get_ref("mouse"));
}

Mouse::Mouse() {
	load_textures();
	this->sprite.setTexture(this->texmgr.get_ref("mouse"));
}


Mouse::~Mouse() {
	// TODO Auto-generated destructor stub
}

void Mouse::set_game_pointer(Game* game){
	this->game = game;
	return;
}

void Mouse::load_textures(){
	this->texmgr.load_texture("mouse", "textures/mouse.png");
	return;
}

void Mouse::update(const float dt){
	position = sf::Vector2f(sf::Mouse::getPosition(this->game->window) + sf::Vector2i(-9,-9));
	sprite.setPosition(position);
}

void Mouse::draw(const float dt){
	this->game->window.draw(this->sprite);
}

sf::Vector2f Mouse::get_position() {
	return position;
}
