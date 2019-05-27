#include "Game.h"


Game::Game(GLuint width, GLuint height) : State(GAME_ACTIVE), Width(width), Height(height) {
	
}

Game::~Game() {

}

void Game::Init() {
	snake = new Snake();
	food = new Food();
}

void Game::Update(GLfloat dt) {
	snake->move(food->getFoodPos());

	if (snake->isEatingFood()) {
		food->randomGenerate();
		snake->resetEatingFood();
	}

	if (!snake->isAlive()) {
		State = GAME_OVER;
	}
}


void Game::ProcessInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	// 如果蛇已经死亡则不再接受输入
	if (!snake->isAlive()) return;

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		snake->change(1);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		snake->change(2);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		snake->change(3);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		snake->change(4);
}

void Game::Render(Shader myShader) {

	myShader.use();

	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);
	glm::mat4 model = glm::mat4(1.0f);
	projection = glm::perspective(glm::radians(45.0f), (float)Width / (float)Height, 0.1f, 100.0f);
	view = glm::lookAt(glm::vec3(0.0f, 0.0f, 5.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	
	myShader.setMat4("projection", projection);
	myShader.setMat4("view", view);
	myShader.setMat4("model", model);

	snake->render();
	food->render();
}

void Game::Clear() {
	snake->Clear();
	food->Clear();
}

GameState Game::getGameState() {
	return State;
}

void Game::setGameState(GameState state) {
	State = state;
}