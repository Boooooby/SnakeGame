#define GLEW_STATIC
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Game.h"
#include "Shader.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

const GLuint SCR_WIDTH = 800;
const GLuint SCR_HEIGHT = 800;

Game SnakeGame(SCR_WIDTH, SCR_HEIGHT);

int main(int argc, char *argv[]) {
	// ��ʼ���������汾�źʹΰ汾�Ŷ���Ϊ3��ʹ�ú���ģʽ
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// ����� Mac OS X ϵͳ����Ҫ�������
	// glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);	

	// ��������
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);	// ���ô��ڵ���������Ϊ��ǰ�̵߳�������
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);	// ���ڴ�С�ı�Ļص�����

	// ��ʼ�� GLAD������ OpenGL ����ָ��
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// ��ʼ����Ϸ
	SnakeGame.Init();

	// ���ڼ���ʱ��ı���
	GLfloat deltaTime = 0.0f;
	GLfloat lastFrame = 0.0f;

	// ������Ϸ״̬
	SnakeGame.setGameState(GAME_ACTIVE);

	// ������ɫ������
	Shader myShader("myShader.vs", "myShader.fs");

	// ������Ȳ���
	glEnable(GL_DEPTH_TEST);
	//glDisable(GL_DEPTH_TEST);

	while (!glfwWindowShouldClose(window)) {
		// ����ʱ����
		GLfloat currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		
		glfwPollEvents();

		// �����û�����
		SnakeGame.ProcessInput(window);

		// ����Ϊ0.5���ƶ�һ����λ
		if (deltaTime < 0.5) continue;
		lastFrame = currentFrame;

		// ������Ϸ״̬
		SnakeGame.Update(deltaTime);

		// ��Ⱦ
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // �����ɫ�������Ȼ���
		SnakeGame.Render(myShader);

		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}