#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <iostream>

#include "GameObject.h"

class Snake : public GameObject {
private:
	bool alive;
	bool eatingFood;
	GLuint dir;
	GLfloat speed;

	pos head;
	std::vector<pos> body;

public:
	Snake();
	~Snake();

	bool isAlive();
	bool isEatingFood();
	void resetEatingFood();

	void change(GLuint dir);
	void move(pos food);
	void render();
};

#endif