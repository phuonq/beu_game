/*
 * Obstacle.h
 *
 *  Created on: Jun 2, 2015
 *      Author: phuong
 */

#ifndef OBSTACLE_H_
#define OBSTACLE_H_

#include "Entity.h"

#define texture_link "texture/Obstacles/"

class Obstacle: public Entity {
public:
	Obstacle();
	virtual ~Obstacle();
	void add_Obstacle(Obstacle obstacle);
	void remove_Obstacle(std::vector<Obstacle>::iterator it);
	std::vector<Obstacle>::iterator get_pointer_on_first_element();
	std::vector<Obstacle>::iterator get_pointer_on_last_element();
	void draw_all_obstacles(const float dt);
	void update_all_obstacles(const float dt);

private:
	static std::vector<Obstacle> list;
};

#endif /* OBSTACLE_H_ */
