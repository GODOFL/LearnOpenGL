#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main(){\n"
"	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 color;\n"
"void main(){\n"
"color = vec4(1.0f, 0.5f, 0.2f, 1.0f);"
"}\0";

int main() {

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(800, 800, "LearnOpenGL", NULL, NULL);
	if (window == NULL) {
		std::cout << "Fail" << std::endl;
		glfwTerminate();
		return -1;
	}

	GLfloat vertices[] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,	0.5f, 0.0f,
	};

	// ����һ������ID��һ��VBO����
	GLuint VBO;
	glGenBuffers(1, &VBO);
	// ���½��Ļ���󶨵�GL_ARRAY_BUFFER��
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	// ��֮ǰ����Ķ������ݸ��Ƶ������ڴ���
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// ����һ��������ɫ������
	GLuint vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);

	// ����ɫ��Դ�븽�ӵ���ɫ�������ϣ�������
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	// ����һ��Ƭ����ɫ������
	GLuint fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	// ����ɫ��Դ�븽�ӵ���ɫ�������ϣ�������
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	// ����һ���������
	GLuint shaderProgram;
	shaderProgram = glCreateProgram();

	// ��������ɫ�������Ƭ����ɫ�����󸽼ӵ������ϣ�Ȼ����������
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	// ʹ�ô˺�������ոմ����ĳ������
	glUseProgram(shaderProgram);

	// ɾ��������ɫ�������Ƭ����ɫ������
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
	glEnableVertexAttribArray(0);

	while(!glfwWindowShouldClose(window)) {
		
	}

	glfwTerminate();
	return 0;
}