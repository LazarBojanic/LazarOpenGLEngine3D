#include "DrawData.hpp"


DrawData::DrawData(std::string name, Mesh& mesh, Shader& shader, Material& material, Light& light, Texture& texture) {
	this->name = name;
	this->mesh = new Mesh(mesh);
	this->shader = new Shader(shader);
	this->material = new Material(material);
	this->light = new Light(light);
	this->texture = new Texture(texture);
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