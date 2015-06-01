/*
 * Entity.h
 *
 *  Created on: Jun 1, 2015
 *      Author: phuong
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include <vector>

class Entity {
public:
	Entity();
	Entity(double position[], double velocity[], double accelaration[]);
	virtual ~Entity();
	virtual void update(double dt);
	void set_position(double position[]);
	void set_velocity(double velocity[]);
	void set_accelaration(double accelaration[]);
	std::vector<double> get_position();
	std::vector<double> get_velocity();
	std::vector<double> get_accelaration();

protected:
	std::vector<double> position;
	std::vector<double> velocity;
	std::vector<double> accelaration;

};

#endif /* ENTITY_H_ */
