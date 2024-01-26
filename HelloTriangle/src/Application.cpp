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
"	color = vec4(1.0f, 0.5f, 0.2f, 1.0f);"
"}\0";

int main() {

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(800, 800, "LearnOpenGL", NULL, NULL);
	if (window == NULL) {
		std::cout << "Fail" << std::endl;
		glfwTerminate();
		return -1;
	}

	// ���˴����ڵ�ǰ�߳�����Ϊ��������
	glfwMakeContextCurrent(window);

	// ����glad
	gladLoadGL();

	GLfloat vertices[] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,	0.5f, 0.0f,
	};

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

	// ɾ��������ɫ�������Ƭ����ɫ������
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	// ����һ��VAO
	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	// ��VAO
	glBindVertexArray(VAO);

	// ����һ������ID��һ��VBO
	GLuint VBO;
	glGenBuffers(1, &VBO);
	// ���½��Ļ���󶨵�GL_ARRAY_BUFFER��
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	// ��֮ǰ����Ķ������ݸ��Ƶ������ڴ���
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	while(!glfwWindowShouldClose(window)) {
		glfwPollEvents();

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// ʹ�ô˺�������ոմ����ĳ������
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);

		glfwSwapBuffers(window);
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	glfwTerminate();
	return 0;
}