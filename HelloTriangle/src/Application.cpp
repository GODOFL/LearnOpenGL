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

	// 生成一个缓冲ID和一个VBO对象
	GLuint VBO;
	glGenBuffers(1, &VBO);
	// 将新建的缓冲绑定到GL_ARRAY_BUFFER上
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	// 将之前定义的顶点数据复制到缓冲内存中
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// 创建一个顶点着色器对象
	GLuint vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);

	// 将着色器源码附加到着色器对象上，并编译
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	// 创建一个片段着色器对象
	GLuint fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	// 将着色器源码附加到着色器对象上，并编译
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	// 创建一个程序对象
	GLuint shaderProgram;
	shaderProgram = glCreateProgram();

	// 将顶点着色器对象和片段着色器对象附加到程序上，然后链接他们
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	// 使用此函数激活刚刚创建的程序对象
	glUseProgram(shaderProgram);

	// 删除顶点着色器对象和片段着色器对象
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
	glEnableVertexAttribArray(0);

	while(!glfwWindowShouldClose(window)) {
		
	}

	glfwTerminate();
	return 0;
}