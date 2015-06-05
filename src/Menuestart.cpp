/*
 * Menuestart.cpp
 *
 *  Created on: Jun 4, 2015
 *      Author: huynh
 */

#include "Menuestart.h"

Menue_start::Menue_start() {
	//play.set_game_pointer(game);
	play.load_textures("play_button", "textures/play_button.png");
	play.sprite.setTexture(play.texmgr.get_ref("play_button"));
	play.set_size(sf::Vector2f(144,55));
	play.set_position(sf::Vector2f(600,200));
}

Menue_start::Menue_start(Game* game ) {
	this->game = game;
	play = Menue_button(game,sf::Vector2f(144,55),sf::Vector2f(450,200));
	//play.set_game_pointer(game);
	play.load_textures("play_button", "textures/play_button.png");
	play.sprite.setTexture(play.texmgr.get_ref("play_button"));
	play.set_size(sf::Vector2f(144,55));
	play.set_position(sf::Vector2f(450,200));
}

Menue_start::~Menue_start() {
	// TODO Auto-generated destructor stub
}

void Menue_start::update(const float dt) {
	play.update(dt);

}

void Menue_start::draw(const float dt) {
	//play.set_game_pointer(game);

	play.draw(dt);
}

int Menue_start::check_hit(sf::Vector2f hit_position) {
	if(play.check_hit(hit_position))
		return 1;
	return 0;

}


void Menue_start::set_game_pointer(Game* game) {
	this->game = game;
	play.set_game_pointer(game);
}
