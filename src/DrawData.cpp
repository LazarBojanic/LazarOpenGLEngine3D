#include "DrawData.hpp"


DrawData::DrawData(std::string name, Mesh* mesh, Shader* shader, Material* material, Light* light, Texture* texture) {
	this->name = name;
	this->mesh = new Mesh(*mesh);
	this->shader = new Shader(*shader);
	this->material = new Material(*material);
	this->light = new Light(*light);
	if (texture != nullptr) {
		this->texture = new Texture(*texture);
	}
	else {
		this->texture = nullptr;
	}
}
DrawData::DrawData(DrawData& drawData) {
	this->name = drawData.getName();
	this->mesh = new Mesh(*drawData.getMesh());
	this->shader = new Shader(*drawData.getShader());
	this->material = new Material(*drawData.getMaterial());
	this->light = new Light(*drawData.getLight());
	if (drawData.texture != nullptr) {
		this->texture = new Texture(*drawData.getTexture());
	}
	else {
		this->texture = nullptr;
	}
}
DrawData::~DrawData() {
	delete this->mesh;
	delete this->shader;
	delete this->material;
	delete this->light;
	delete this->texture;
}

void DrawData::setShader(const Shader& shader){
	this->shader = new Shader(shader);
}