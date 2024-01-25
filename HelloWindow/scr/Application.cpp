#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main() {

	// ��ʼ��GLFW
	glfwInit();
	// ����GLFWʹ�õ�OpenGL�汾
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// ����GLFWʹ�ú���ģʽ 
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// ���ò������û��������ڴ�С
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	// ����һ��800*600����*�ߣ�����Ϊ��LearnOpenGL���Ĵ���
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	// ����ǰ��������Ϊ��ǰ�̵߳���������
	glfwMakeContextCurrent(window);

	// ��鴰���Ƿ��˳�
	while (!glfwWindowShouldClose(window)) {
		// ����Ƿ����¼�����
		glfwPollEvents();

		// ��Ⱦָ��

		// ������ɫ����
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}