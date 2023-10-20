#pragma once

#include "Util.hpp"

class Light {
public:
	std::string name;
	glm::vec3 position;
	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;
	Light(std::string name,
		glm::vec3 position,
		glm::vec3 ambient,
		glm::vec3 diffuse,
		glm::vec3 specular);
	~Light();
};