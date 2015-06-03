/*
 * Texturemanager.cpp
 *
 *  Created on: Jun 3, 2015
 *      Author: huynh
 */

#include "Texturemanager.h"

Texture_manager::Texture_manager() {
	// TODO Auto-generated constructor stub

}

Texture_manager::~Texture_manager() {
	// TODO Auto-generated destructor stub
}

void Texture_manager::load_texture(const std::string& name, const std::string& filename){
	sf::Texture tex;
	tex.loadFromFile(filename);

	this->textures[name] = tex;

	return;
}

sf::Texture& Texture_manager::get_ref(const std::string& texture){
	return this->textures.at(texture);
}
