#pragma once

#include "GLData.hpp"
#include "Mesh.hpp"
#include "Shader.hpp"
#include "CubeMap.hpp"

class Skybox {
private:
	std::string name;
	Mesh* mesh;
	Shader* shader;
	CubeMap* cubeMap;
public:
	Skybox(Mesh* mesh, Shader* shader, CubeMap* cubeMap, std::string name);
	~Skybox();
	inline std::string getName() {
		return this->name;
	}
	inline Mesh* getMesh() {
		return this->mesh;
	}
	inline Shader* getShader() {
		return this->shader;
	}
	inline CubeMap* getCubeMap() {
		return this->cubeMap;
	}
};