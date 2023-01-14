#include "Skybox.hpp"

Skybox::Skybox(Mesh* mesh, Shader* shader, CubeMap* cubeMap, std::string name) {
	this->name = name;
	this->mesh = mesh;
	this->shader = shader;
	this->cubeMap = cubeMap;
}

Skybox::~Skybox() {
	delete this->mesh;
	delete this->shader;
	delete this->cubeMap;
}
