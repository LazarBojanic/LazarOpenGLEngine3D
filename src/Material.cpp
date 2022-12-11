#include "Material.hpp"

Material::Material(std::string name, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float shininess){
	this->name = name;
	this->ambient = ambient;
	this->diffuse = diffuse;
	this->specular = specular;
	this->shininess = shininess;
}

Material::~Material(){
}
