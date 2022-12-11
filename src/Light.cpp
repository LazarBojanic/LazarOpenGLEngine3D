#include "Light.hpp"

Light::Light(std::string name, glm::vec3 position, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular) {
	this->name = name;
	this->position = position;
	this->ambient = ambient;
	this->diffuse = diffuse;
	this->specular = specular;
}

Light::~Light() {
}
