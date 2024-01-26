#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	std::cout << key << std::endl;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}

int main() {

	// 初始化GLFW
	glfwInit();
	// 设置GLFW使用的OpenGL版本
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// 设置GLFW使用核心模式 
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// 设置不允许用户调整窗口大小
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	// 创建一个800*600（宽*高）名字为“LearnOpenGL”的窗口
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	// 将当前窗口设置为当前线程的主上下文
	glfwMakeContextCurrent(window);

	glfwSetKeyCallback(window, key_callback);

	// 别忘记加这个
	gladLoadGL();

	GLint width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);

	// 检查窗口是否被退出
	while (!glfwWindowShouldClose(window)) {
		// 检查是否有事件触发
		glfwPollEvents();

		// 渲染指令
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// 交换颜色缓冲
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}