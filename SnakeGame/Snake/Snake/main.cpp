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
	// 初始化，将主版本号和次版本号都设为3，使用核心模式
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// 如果是 Mac OS X 系统，还要加上这个
	// glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);	

	// 创建窗口
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);	// 将该窗口的上下文设为当前线程的上下文
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);	// 窗口大小改变的回调函数

	// 初始化 GLAD，加载 OpenGL 函数指针
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// 初始化游戏
	SnakeGame.Init();

	// 用于计算时间的变量
	GLfloat deltaTime = 0.0f;
	GLfloat lastFrame = 0.0f;

	// 设置游戏状态
	SnakeGame.setGameState(GAME_ACTIVE);

	// 创建着色器对象
	Shader myShader("myShader.vs", "myShader.fs");

	// 启动深度测试
	glEnable(GL_DEPTH_TEST);
	//glDisable(GL_DEPTH_TEST);

	while (!glfwWindowShouldClose(window)) {
		// 计算时间间距
		GLfloat currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		
		glfwPollEvents();

		// 处理用户输入
		SnakeGame.ProcessInput(window);

		// 设置为0.5秒移动一个单位
		if (deltaTime < 0.5) continue;
		lastFrame = currentFrame;

		// 更新游戏状态
		SnakeGame.Update(deltaTime);

		// 渲染
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // 清除颜色缓存和深度缓存
		SnakeGame.Render(myShader);

		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}