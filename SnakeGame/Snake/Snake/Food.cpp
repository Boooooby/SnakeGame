#include "Food.h"

Food::Food() : foodPos(pos(0.0f, 0.0f)) {
	randomGenerate();
}

Food::~Food() {

}

void Food::render() {
	Render(foodPos.x, foodPos.y, glm::vec3(1.0f, 0.0f, 0.0f));
}

void Food::randomGenerate() {
	int randX = rand() % 11 - 5;
	int randY = rand() % 11 - 5;
	foodPos.x = randX * 0.4f;
	foodPos.y = randY * 0.4f;
	//std::cout << "(" << foodPos.x << "," << foodPos.y << ")";
}

pos Food::getFoodPos() {
	return foodPos;
}