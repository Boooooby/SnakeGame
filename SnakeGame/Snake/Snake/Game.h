#ifndef GAME_H
#define GAME_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

#include "GameObject.h"
#include "Snake.h"
#include "Food.h"
#include "Shader.h"

enum GameState {
	GAME_ACTIVE,
	GAME_MENU,
	GAME_WIN,
	GAME_OVER
};

class Game {
private:
	GLuint Width, Height;
	GameState State;
	Snake *snake;
	Food *food;

public:	
	Game(GLuint width, GLuint height);
	~Game();
	
	void Init();
	
	void ProcessInput(GLFWwindow* window);
	void Update(GLfloat dt);
	void Render(Shader myShader);
	void Clear();

	GameState getGameState();
	void setGameState(GameState state);
};

#endif
