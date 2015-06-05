/*
 * Game.cpp
 *
 *  Created on: Jun 2, 2015
 *      Author: huynh
 */
#include <stack>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Game.h"
#include "Gamestate.h"

void Game::push_state(Gamestate* state){
	this->states.push(state);

	return;
}

void Game::pop_state(){
	delete this->states.top();
	this->states.pop();

	return;
}

void Game::change_state(Gamestate* state){
	if(!this->states.empty())
		pop_state();
	push_state(state);

	return;
}

Gamestate* Game::peek_state(){
	if(this->states.empty())
		return NULL;

	return this->states.top();
}

void Game::game_loop(){
	sf::Clock clock;

	while(this->window.isOpen()){
	sf::Time elapsed = clock.restart();
	float dt = elapsed.asSeconds();

	if(peek_state() == NULL)
		continue;
	peek_state()->handle_input();
	peek_state()->update(dt);
	this->window.clear();
	peek_state()->draw(dt);
	this->window.display();

	}
}



Game::Game() {
    this->window.create(sf::VideoMode(800, 600), "Legends Unleashed");
    this->window.setFramerateLimit(60);
    this->window.setMouseCursorVisible(false);
}

Game::~Game() {
	  while(!this->states.empty())
		  pop_state();

}

