#include "DrawData.hpp"


DrawData::DrawData(std::string name, Mesh* mesh, Shader* shader, Material* material, Light* light, std::vector<Texture*>* textureList) {
	this->name = name;
	this->mesh = new Mesh(*mesh);
	this->shader = new Shader(*shader);
	this->material = new Material(*material);
	this->light = new Light(*light);
	this->textureList = textureList;
}
DrawData::DrawData(DrawData& drawData) {
	this->name = drawData.getName();
	this->mesh = new Mesh(*drawData.getMesh());
	this->shader = new Shader(*drawData.getShader());
	this->material = new Material(*drawData.getMaterial());
	this->light = new Light(*drawData.getLight());
	this->textureList = drawData.getTextureList();
}
DrawData::~DrawData() {
	delete this->mesh;
	delete this->shader;
	delete this->material;
	delete this->light;
	delete this->textureList;
}

void DrawData::setShader(const Shader& shader){
	this->shader = new Shader(shader);
}