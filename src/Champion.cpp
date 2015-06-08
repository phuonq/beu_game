/*
 * Champion.cpp
 *
 *  Created on: Jun 2, 2015
 *      Author: phuong
 */

#include "Champion.h"

std::vector<Champion> Champion::list;

Champion::Champion() {
	this->load_multiple_textures(texture_link_champ);
}

Champion::~Champion() {
	// TODO Auto-generated destructor stub
}

void Champion::add_Champion(Champion champion) {
	this->list.push_back(champion);
}

void Champion::remove_Champion(std::vector<Champion>::iterator it) {
	this->list.erase(it);
}

std::vector<Champion>::iterator Champion::get_pointer_on_first_element() {
	return this->list.begin();
}

std::vector<Champion>::iterator Champion::get_pointer_on_last_element() {
	return this->list.end();
}

void Champion::draw_all_champions(const float dt) {
	std::vector<Champion>::iterator first = get_pointer_on_first_element();
	std::vector<Champion>::iterator last = get_pointer_on_last_element();
	std::vector<Champion>::iterator it;

	for (it = first; it != last; it++) {
		it->game->window.draw(it->sprite);
	}
}

void Champion::update_all_champions(const float dt) {
	std::vector<Champion>::iterator first = get_pointer_on_first_element();
	std::vector<Champion>::iterator last = get_pointer_on_last_element();
	std::vector<Champion>::iterator it;

	for (it = first; it != last; it++) {
		it->sprite.setTexture((it->texmgr.get_ref(it->texture_list[it->texture_number])));
		it->update(dt);
	}
}

double Champion::get_health() {
	return this->health;
}
double Champion::get_mana() {
	return this->mana;
}

double Champion::get_armor() {
	return this->armor;
}

double Champion::get_magic_resist() {
	return this->magic_resist;
}

double Champion::get_attack_damage() {
	return this->attack_damage;
}

double Champion::get_ability_power() {
	return this->ability_power;
}

double Champion::get_movement_speed() {
	return this->movement_speed;
}

double Champion::get_attack_speed() {
	return this->attack_speed;
}

void Champion::set_all_parameters(double health, double mana, double armor, double magic_resist, double attack_damage, double ability_power, double movement_speed, double attack_speed) {
	this->health = health;
	this->mana = mana;
	this->armor = armor;
	this->magic_resist = magic_resist;
	this->attack_damage = attack_damage;
	this->ability_power = ability_power;
	this->movement_speed = movement_speed;
	this->attack_speed = attack_speed;
}

void Champion::set_health(double health) {
	this->health = health;
}

void Champion::set_mana(double mana) {
	this->mana = mana;
}

void Champion::set_armor(double armor) {
	this->armor = armor;
}

void Champion::set_magic_resist(double magic_resist) {
	this->magic_resist = magic_resist;
}

void Champion::set_attack_damage(double attack_damage) {
	this->attack_damage = attack_damage;
}

void Champion::set_ability_power(double ability_power) {
	this->ability_power = ability_power;
}

void Champion::set_movement_speed(double movement_speed) {
	this->movement_speed = movement_speed;
}

void Champion::set_attack_speed(double attack_speed) {
	this->attack_speed = attack_speed;
}
