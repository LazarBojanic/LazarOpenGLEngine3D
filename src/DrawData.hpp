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
	std::vector<Texture*>* textureList;
public:
	DrawData(std::string name, Mesh* mesh, Shader* shader, Material* material, Light* light, std::vector<Texture*>* textureList);
	DrawData(DrawData& drawData);
	~DrawData();
	inline std::string getName() {
		return this->name;
	}
	inline Mesh* getMesh() {
		return this->mesh;
	}
	inline Shader* getShader() {
		return this->shader;
	}
	inline Material* getMaterial() {
		return this->material;
	}
	inline Light* getLight() {
		return this->light;
	}
	inline std::vector<Texture*>* getTextureList() {
		return this->textureList;
	}
	void setShader(const Shader& shader);
};