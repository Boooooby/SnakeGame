#include "GameObject.h"

GameObject::GameObject() {
	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);
}

GameObject::~GameObject() {
	Clear();
}

void GameObject::Render(GLfloat x, GLfloat y, glm::vec3 color) {
	GLfloat vertices[] = {
		-0.2f + x, -0.2f + y, -0.2f, color.x, color.y, color.z,
		0.2f + x,  -0.2f + y, -0.2f, color.x, color.y, color.z,
		0.2f + x,  0.2f + y,  -0.2f, color.x, color.y, color.z,
		0.2f + x,  0.2f + y,  -0.2f, color.x, color.y, color.z,
		-0.2f + x, 0.2f + y,  -0.2f, color.x, color.y, color.z,
		-0.2f + x, -0.2f + y, -0.2f, color.x, color.y, color.z,

		-0.2f + x, -0.2f + y, 0.2f, color.x, color.y, color.z,
		0.2f + x,  -0.2f + y, 0.2f, color.x, color.y, color.z,
		0.2f + x,  0.2f + y,  0.2f, color.x, color.y, color.z,
		0.2f + x,  0.2f + y,  0.2f, color.x, color.y, color.z,
		-0.2f + x, 0.2f + y,  0.2f, color.x, color.y, color.z,
		-0.2f + x, -0.2f + y, 0.2f, color.x, color.y, color.z,

		-0.2f + x,  0.2f + y,  0.2f, color.x, color.y, color.z,
		-0.2f + x,  0.2f + y, -0.2f, color.x, color.y, color.z,
		-0.2f + x, -0.2f + y, -0.2f, color.x, color.y, color.z,
		-0.2f + x, -0.2f + y, -0.2f, color.x, color.y, color.z,
		-0.2f + x, -0.2f + y,  0.2f, color.x, color.y, color.z,
		-0.2f + x,  0.2f + y,  0.2f, color.x, color.y, color.z,

		0.2f + x,  0.2f + y,  0.2f, color.x, color.y, color.z,
		0.2f + x,  0.2f + y, -0.2f, color.x, color.y, color.z,
		0.2f + x, -0.2f + y, -0.2f, color.x, color.y, color.z,
		0.2f + x, -0.2f + y, -0.2f, color.x, color.y, color.z,
		0.2f + x, -0.2f + y,  0.2f, color.x, color.y, color.z,
		0.2f + x,  0.2f + y,  0.2f, color.x, color.y, color.z,

		-0.2f + x, -0.2f + y, -0.2f, color.x, color.y, color.z,
		0.2f + x,  -0.2f + y, -0.2f, color.x, color.y, color.z,
		0.2f + x,  -0.2f + y, 0.2f,  color.x, color.y, color.z,
		0.2f + x,  -0.2f + y, 0.2f,  color.x, color.y, color.z,
		-0.2f + x, -0.2f + y, 0.2f,  color.x, color.y, color.z,
		-0.2f + x, -0.2f + y, -0.2f, color.x, color.y, color.z,

		-0.2f + x, 0.2f + y, -0.2f, color.x, color.y, color.z,
		0.2f + x,  0.2f + y, -0.2f, color.x, color.y, color.z,
		0.2f + x,  0.2f + y, 0.2f,  color.x, color.y, color.z,
		0.2f + x,  0.2f + y, 0.2f,  color.x, color.y, color.z,
		-0.2f + x, 0.2f + y, 0.2f,  color.x, color.y, color.z,
		-0.2f + x, 0.2f + y, -0.2f, color.x, color.y, color.z,
	};

	glBindVertexArray(VAO);	// 绑定VAO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);	// 绑定到 GL_ARRAY_BUFFER 目标上
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);	// 将顶点数据复制到缓冲的内存中

	// 位置属性
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);	// 指定如何解释顶点数据
	glEnableVertexAttribArray(0);	// 启用顶点属性
	// 颜色属性
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
}

void GameObject::Clear() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}