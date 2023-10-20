#pragma once

#include "Util.hpp"

class Material{
public:
	std::string name;
	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;
	float shininess;
	Material(std::string name, 
	glm::vec3 ambient,
	glm::vec3 diffuse,
	glm::vec3 specular,
	float shininess);
	~Material();
};