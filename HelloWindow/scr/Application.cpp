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

	glfwSetKeyCallback(window, key_callback);

	// �����Ǽ����
	gladLoadGL();

	GLint width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);

	// ��鴰���Ƿ��˳�
	while (!glfwWindowShouldClose(window)) {
		// ����Ƿ����¼�����
		glfwPollEvents();

		// ��Ⱦָ��
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// ������ɫ����
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}