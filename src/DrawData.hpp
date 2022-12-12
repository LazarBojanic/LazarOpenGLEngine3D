#pragma once

#include "GLData.hpp"
#include "Mesh.hpp"
#include "Shader.hpp"
#include "Material.hpp"
#include "Light.hpp"
#include "Texture.hpp"

class DrawData {
private:
	std::string name;
	Mesh* mesh;
	Shader* shader;
	Material* material;
	Light* light;
	Texture* texture;
public:
	DrawData(std::string name, Mesh& mesh, Shader& shader, Material& material, Light& light, Texture& texture);
	~DrawData();
	std::string getName() {
		return this->name;
	}
	Mesh* getMesh() {
		return this->mesh;
	}
	Shader* getShader() {
		return this->shader;
	}
	Material* getMaterial() {
		return this->material;
	}
	Light* getLight() {
		return this->light;
	}
	Texture* getTexture() {
		return this->texture;
	}
	void setShader(const Shader& shader);
};