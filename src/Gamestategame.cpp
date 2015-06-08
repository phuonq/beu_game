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
	escape_flag = 0;
	this->game->window.setMouseCursorVisible(true);

	obstacle.set_game_pointer(game);
	champ.add_Champion(Champion(sf::Vector2f(400,500), sf::Vector2f(0,0), sf::Vector2f(0,0), sf::Vector2f(48,48), game, texture_link_champ, 0));
}

Gamestate_game::~Gamestate_game() {
	// TODO Auto-generated destructor stub
}

void Gamestate_game::draw(const float dt){
	this->game->window.clear(sf::Color::Blue);
	this->game->window.draw(this->background);
	this->obstacle.draw_all_obstacles(dt);
	this->champ.draw_all_champions(dt);
	this->projectile.draw_all_projectiles(dt);
	return;
}

void Gamestate_game::update(const float dt){

	std::vector<Projectile>::iterator it;
	std::vector<Projectile>::iterator first_pro = projectile.get_pointer_on_first_element();
	std::vector<Projectile>::iterator last_pro = projectile.get_pointer_on_last_element();
	std::vector<Obstacle>::iterator it2;
	std::vector<Obstacle>::iterator first_obs = obstacle.get_pointer_on_first_element();
	std::vector<Obstacle>::iterator last_obs = obstacle.get_pointer_on_last_element();

	for (it = first_pro; it!=last_pro; it++) {
		for (it2 = first_obs; it2!=last_obs; it2++) {

			if ((it->bottom_side_hitbox() < it2->bottom_side_hitbox() && it->bottom_side_hitbox() > it2->top_side_hitbox())
				|| ((it->top_side_hitbox() > it2->top_side_hitbox() && it->top_side_hitbox() < it2->bottom_side_hitbox())
				&& ((it->left_side_hitbox() > it2->left_side_hitbox() && it->left_side_hitbox() < it2->left_side_hitbox()))
				|| (it->right_side_hitbox() > it2->left_side_hitbox() && it->right_side_hitbox() < it2->right_side_hitbox()))) {
				obstacle.remove_Obstacle(it2);
				projectile.remove_Projectile(it);
			}
		}
	}


	this->obstacle.update_all_obstacles(dt);
	this->champ.update_all_champions(dt);
	this->projectile.update_all_projectiles(dt);
	if(this->champ.get_pointer_on_first_element()->get_velocity().x > 0)
		this->champ.get_pointer_on_first_element()->set_velocity(sf::Vector2f(this->champ.get_pointer_on_first_element()->get_velocity().x-8*dt,0.f));
	if(this->champ.get_pointer_on_first_element()->get_velocity().x < 0)
		this->champ.get_pointer_on_first_element()->set_velocity(sf::Vector2f(this->champ.get_pointer_on_first_element()->get_velocity().x+8*dt,0.f));
	if(escape_flag == 1)
		this->game->pop_state();
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
		case sf::Event::KeyPressed:
			if(event.key.code == sf::Keyboard::Escape)
				set_escape_flag();
			if(event.key.code == sf::Keyboard::A) {
				// this->champ.get_pointer_on_first_element()->set_velocity(sf::Vector2f(-5,0));
				if(this->champ.get_pointer_on_first_element()->get_velocity().x > -5 )
					this->champ.get_pointer_on_first_element()->set_velocity(sf::Vector2f(this->champ.get_pointer_on_first_element()->get_velocity().x-3,0.f));
			}
			if(event.key.code == sf::Keyboard::D)
				this->champ.get_pointer_on_first_element()->set_velocity(sf::Vector2f(5,0));
			break;
		case sf::Event::MouseButtonPressed:
			if(event.mouseButton.button == sf::Mouse::Left) {
				sf::Vector2f c_pos = this->champ.get_pointer_on_first_element()->get_position();
				sf::Vector2f m_pos = sf::Vector2f(sf::Mouse::getPosition(this->game->window));
				projectile.add_Projectile(Projectile(c_pos,m_pos-c_pos, sf::Vector2f(0,0), sf::Vector2f(15,15),game,texture_link_proj,0));
			}
			else if(event.mouseButton.button == sf::Mouse::Right) {
				sf::Vector2f m_pos = sf::Vector2f(sf::Mouse::getPosition(this->game->window));
				obstacle.add_Obstacle(Obstacle(m_pos, sf::Vector2f(0,0), sf::Vector2f(0,0), sf::Vector2f(48,48),game,texture_link_obs,0));
			}
			break;
		default:
			break;
		}
	}
	return;
}

void Gamestate_game::load_textures(){
	texmgr.load_texture("background_game", "textures/background_game.png");
}

void Gamestate_game::set_escape_flag() {
	this->game->window.setMouseCursorVisible(false);
	escape_flag = 1;
}
