#include "Shader.hpp"

Shader::Shader() {
}

Shader::Shader(std::string vertexShaderPath, std::string fragmentShaderPath, std::string name) {
	HRESULT guidResult = CoCreateGuid(&this->id);
	this->name = name;
	createVertexShader();
	createFragmentShader();

	this->vertexShaderSource = loadShaderSource(vertexShaderPath);
	this->fragmentShaderSource = loadShaderSource(fragmentShaderPath);

	compile(this->vertexShaderID, this->vertexShaderSource);
	compile(this->fragmentShaderID, this->fragmentShaderSource);

	createProgramAndAttachShaders(this->vertexShaderID, this->fragmentShaderID);
}
Shader::~Shader() {
}
std::string Shader::loadShaderSource(std::string shaderPath) {
	std::string shaderSource;
	std::ifstream shaderFile;
	shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try {
		std::stringstream shaderStream;
		shaderFile.open(shaderPath);
		shaderStream << shaderFile.rdbuf();
		shaderFile.close();
		shaderSource = shaderStream.str();
		shaderStream.clear();
	}
	catch (std::ifstream::failure e) {
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}
	return shaderSource;
}
void Shader::createVertexShader() {
	vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
}
void Shader::createFragmentShader() {
	fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
}
void Shader::compile(unsigned int shader, std::string shaderSource) {
	const char* shaderSourceCString = shaderSource.c_str();
	glShaderSource(shader, 1, &shaderSourceCString, NULL);
	glCompileShader(shader);
	int success;
	char infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << "Error compiling shader " << this->name << "\n" << infoLog << std::endl;
	}
}
void Shader::createProgramAndAttachShaders(unsigned int vertexShader, unsigned int fragmentShader) {
	this->shaderProgram = glCreateProgram();
	glAttachShader(this->shaderProgram, vertexShader);
	glAttachShader(this->shaderProgram, fragmentShader);
	glLinkProgram(this->shaderProgram);
	int success;
	char infoLog[512];
	glGetProgramiv(this->shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(this->shaderProgram, 512, NULL, infoLog);
		std::cout << "Error linking shader " << this->name << "\n" << infoLog << std::endl;
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}
void Shader::use() {
	glUseProgram(this->shaderProgram);
}
void Shader::unbind() {
	glUseProgram(0);
}
void Shader::setBool(std::string name, bool value, bool useShader) {
	if (useShader) {
		use();
	}
	glUniform1i(glGetUniformLocation(this->shaderProgram, name.c_str()), (int)value);
}
void Shader::setInt(std::string name, int value, bool useShader) {
	if (useShader) {
		use();
	}
	glUniform1i(glGetUniformLocation(this->shaderProgram, name.c_str()), value);
}
void Shader::setFloat(std::string name, float value, bool useShader) {
	if (useShader) {
		use();
	}
	glUniform1f(glGetUniformLocation(this->shaderProgram, name.c_str()), value);
}
void Shader::setVector2f(std::string name, glm::vec2 value, bool useShader) {
	if (useShader) {
		use();
	}
	glUniform2f(glGetUniformLocation(this->shaderProgram, name.c_str()), value.x, value.y);
}
void Shader::setVector3f(std::string name, glm::vec3 value, bool useShader) {
	if (useShader) {
		use();
	}
	glUniform3f(glGetUniformLocation(this->shaderProgram, name.c_str()), value.x, value.y, value.z);
}
void Shader::setVector4f(std::string name, glm::vec4 value, bool useShader) {
	if (useShader) {
		use();
	}
	glUniform4f(glGetUniformLocation(this->shaderProgram, name.c_str()), value.x, value.y, value.z, value.w);
}
void Shader::setMatrix4f(std::string name, glm::mat4 value, bool useShader) {
	if (useShader) {
		use();
	}
	glUniformMatrix4fv(glGetUniformLocation(this->shaderProgram, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}