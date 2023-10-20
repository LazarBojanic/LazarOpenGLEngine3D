#pragma once

#include "Util.hpp"

class Shader{
private:
	GUID id;
	std::string name;
	unsigned int shaderProgram;
	std::string vertexShaderSource;
	std::string fragmentShaderSource;
	unsigned int vertexShaderID;
	unsigned int fragmentShaderID;
public:
	Shader();
	Shader(std::string vertexShaderPath, std::string fragmentShaderPath, std::string name);
	~Shader();

	std::string loadShaderSource(std::string shaderPath);
	void createVertexShader();
	void createFragmentShader();
	void compile(unsigned int shader, std::string shaderSource);
	void createProgramAndAttachShaders(unsigned int vertexShader, unsigned int fragmentShader);
	void use();
	void unbind();

	void setBool(std::string name, bool value, bool useShader);
	void setInt(std::string name, int value, bool useShader);
	void setFloat(std::string name, float value, bool useShader);
	void setVector2f(std::string name, glm::vec2 value, bool useShader);
	void setVector3f(std::string name, glm::vec3 value, bool useShader);
	void setVector4f(std::string name, glm::vec4 value, bool useShader);
	void setMatrix4f(std::string name, glm::mat4 value, bool useShader);

	inline GUID getId() {
		return this->id;
	}
	inline std::string getName() {
		return this->name;
	}
	inline unsigned int getShaderProgram() {
		return this->shaderProgram;
	}
	inline std::string getVertexShaderSource() {
		return this->vertexShaderSource;
	}
	inline std::string getFragmentShaderSource() {
		return this->fragmentShaderSource;
	}
	inline unsigned int getVertexShaderID() {
		return this->vertexShaderID;
	}
	inline unsigned int getFragmentShaderID() {
		return this->fragmentShaderID;
	}
};

