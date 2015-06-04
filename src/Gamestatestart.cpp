/*
 * Gamestatestart.cpp
 *
 *  Created on: Jun 2, 2015
 *      Author: huynh
 */

#include "Gamestatestart.h"
#include "Gamestategame.h"

Gamestate_start::Gamestate_start(Game* game) {
	load_textures();
	this->game = game;
	mouse.set_game_pointer(game);
	sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
	this->view.setSize(pos);
	pos *= 0.5f;
	this->view.setCenter(pos);
	this->background.setTexture(this->texmgr.get_ref("background_start"));
}

Gamestate_start::~Gamestate_start() {
	// TODO Auto-generated destructor stub
}

void Gamestate_start::draw(const float dt){
	this->game->window.setView(this->view);
	this->game->window.clear(sf::Color::Red);
	this->game->window.draw(this->background);
	this->game->window.draw(this->mouse.sprite);

	return;
}

void Gamestate_start::update(const float dt){
	mouse.update();
}

void Gamestate_start::handle_input(){
	sf::Event event;

	while(this->game->window.pollEvent(event)){
		switch(event.type){
		case sf::Event::Closed:
			game->window.close();
			break;
		case sf::Event::Resized:
			this->view.setSize(event.size.width, event.size.height);
			this->background.setPosition(this->game->window.mapPixelToCoords(sf::Vector2i(0, 0)));
			this->background.setScale(float(event.size.width) / float(this->background.getTexture()->getSize().x),
			                    float(event.size.height) / float(this->background.getTexture()->getSize().y));
			break;
		case sf::Event::KeyPressed:
			if(event.key.code == sf::Keyboard::Escape)
				this->game->window.close();
			else if(event.key.code == sf::Keyboard::Return)
				this->load_game();
	        break;
		default:
			break;
		}
	}
	return;
}

void Gamestate_start::load_game(){
	this->game->push_state(new Gamestate_game(this->game));
}

void Gamestate_start::load_textures(){
	texmgr.load_texture("background_start", "textures/background_start.jpg");
}

