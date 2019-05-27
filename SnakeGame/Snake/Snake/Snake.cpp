#include "Snake.h"

Snake::Snake() : alive(true), eatingFood(false), dir(0), speed(0.4), head(pos(0.0f, 0.0f)) {
	for (GLuint i = 0; i < 3; i++) {
		body.push_back(pos(0.0f, -0.4f - i * 0.4f));
	}
}

Snake::~Snake() {

}

void Snake::change(GLuint dir) {
	this->dir = dir;
}

void Snake::move(pos food) {
	GLfloat tailX = body[body.size() - 1].x;
	GLfloat tailY = body[body.size() - 1].y;
	if (dir != 0) {
		for (GLuint i = body.size() - 1; i > 0; i--) {
			body[i].x = body[i-1].x;
			body[i].y = body[i-1].y;
		}
		body[0].x = head.x;
		body[0].y = head.y;
	}
	
	switch (dir) {
	case 1:
		head.y += speed;
		break;
	case 2:
		head.y -= speed;
		break;
	case 3:
		head.x -= speed;
		break;
	case 4:
		head.x += speed;
		break;
	default:
		break;
	}

	if (abs(head.x - food.x) < 0.01 && abs(head.y - food.y) < 0.01) {
		eatingFood = true;
		body.push_back(pos(tailX, tailY));
	}

	if (head.x > 2 || head.x < -2 || head.y > 2 || head.y < -2) {
		alive = false;
		dir = 0;
	}
	for (GLuint i = 0; i < body.size() - 1; i++) {
		if (head.x == body[i].x && head.y == body[i].y) {
			alive = false;
			dir = 0;
		}
	}
}

void Snake::render() {
	glm::vec3 headColor(0.0f, 1.0f, 0.0f);
	glm::vec3 bodyColor(0.0f, 1.0f, 0.5f);
	if (!alive) {
		headColor = glm::vec3(0.2f, 0.2f, 0.2f);
		bodyColor = glm::vec3(0.2f, 0.2f, 0.2f);
	}
	Render(head.x, head.y, headColor);
	//std::cout << "(" << head.x << "," << head.y << ")";
	for (GLuint i = 0; i < body.size(); i++) {
		//std::cout << " - (" << body[i].x << "," << body[i].y << ")";
		Render(body[i].x, body[i].y, bodyColor);
	}
	//std::cout << std::endl;
}

bool Snake::isAlive() {
	return alive;
}

bool Snake::isEatingFood() {
	return eatingFood;
}

void Snake::resetEatingFood() {
	eatingFood = false;
}