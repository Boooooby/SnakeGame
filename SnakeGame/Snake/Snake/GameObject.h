#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

typedef struct Position {
	GLfloat x;
	GLfloat y;

	Position(GLfloat _x, GLfloat _y) {
		x = _x;
		y = _y;
	}
} pos;

class GameObject {
private:
	GLuint VAO, VBO;

public:
	GameObject();
	~GameObject();
	void Render(GLfloat x, GLfloat y, glm::vec3 color);
	void Clear();
};

#endif 
