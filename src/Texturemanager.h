/*
 * Texturemanager.h
 *
 *  Created on: Jun 3, 2015
 *      Author: huynh
 */

#ifndef TEXTUREMANAGER_H_
#define TEXTUREMANAGER_H_
#include <SFML/Graphics.hpp>
#include <string>
#include <map>


class Texture_manager {
public:
	void load_texture(const std::string& name, const std::string& filename);
	sf::Texture& get_ref(const std::string& texture);
	Texture_manager();
	virtual ~Texture_manager();

private:
	std::map<std::string, sf::Texture> textures;

};

#endif /* TEXTUREMANAGER_H_ */
