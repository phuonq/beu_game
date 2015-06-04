/*
 * Mouse.cpp
 *
 *  Created on: Jun 4, 2015
 *      Author: huynh
 */

#include "Mouse.h"

Mouse::Mouse(Game* game) {
	load_textures();
	this->game = game;
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

void Mouse::update(){
	position = sf::Vector2f(sf::Mouse::getPosition(this->game->window));
	sprite.setPosition(position);
}

void Mouse::draw(){
	this->game->window.draw(this->sprite);
}
