/*
 * Menuebutton.h
 *
 *  Created on: Jun 4, 2015
 *      Author: huynh
 */

#ifndef MENUEBUTTON_H_
#define MENUEBUTTON_H_
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Texturemanager.h"

class Menue_button {
public:
	Game* game;
	Texture_manager texmgr;
	sf::Sprite sprite;

	void draw(const float dt);
	void update(const float dt);
	bool check_hit(sf::Vector2f hit_position);
	void set_game_pointer(Game* game);
	void set_size(sf::Vector2f size);
	void set_position(sf::Vector2f position);
	void load_textures(const std::string& name, const std::string& path);
	Menue_button(Game* game, sf::Vector2f size, sf::Vector2f position);
	Menue_button();
	virtual ~Menue_button();

private:
	sf::Vector2f size;
	sf::Vector2f position;
};

#endif /* MENUEBUTTON_H_ */
