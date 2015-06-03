/*
 * Gamestategame.cpp
 *
 *  Created on: Jun 3, 2015
 *      Author: huynh
 */

#include "Gamestategame.h"

Gamestate_game::Gamestate_game(Game* game) {
	load_textures();
	this->game = game;
	sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
	this->gui_view.setSize(pos);
	this->game_view.setSize(pos);
	pos *=0.5f;
	this->gui_view.setCenter(pos);
	this->game_view.setCenter(pos);
	this->background.setTexture(this->texmgr.get_ref("background_game"));

}

Gamestate_game::~Gamestate_game() {
	// TODO Auto-generated destructor stub
}

void Gamestate_game::draw(const float dt){
	this->game->window.clear(sf::Color::Blue);
	this->game->window.draw(this->background);

	return;
}

void Gamestate_game::update(const float dt){
	return;
}

void Gamestate_game::handle_input(){
	sf::Event event;

	while(this->game->window.pollEvent(event)){
		switch(event.type){
		case sf::Event::Closed:
			this->game->window.close();
			break;
		case sf::Event::Resized:
			game_view.setSize(event.size.width, event.size.height);
			gui_view.setSize(event.size.width, event.size.height);
			this->background.setPosition(this->game->window.mapPixelToCoords(sf::Vector2i(0, 0), this->gui_view));
			this->background.setScale(float(event.size.width) / float(this->background.getTexture()->getSize().x),
			                    float(event.size.height) / float(this->background.getTexture()->getSize().y));
			break;
		default:
			break;
		}
	}
	return;
}

void Gamestate_game::load_textures(){
	texmgr.load_texture("background_game", "textures/background_game.jpg");
}
