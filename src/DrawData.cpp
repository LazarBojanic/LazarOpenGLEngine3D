#include "DrawData.hpp"


DrawData::DrawData(std::string name, Mesh& mesh, Shader& shader, Material& material, Light& light, Texture2D& texture2D) {
	this->name = name;
	this->mesh = new Mesh(mesh);
	this->shader = new Shader(shader);
	this->material = new Material(material);
	this->light = new Light(light);
	this->texture2D = new Texture2D(texture2D);
}
DrawData::~DrawData() {
	delete this->mesh;
	delete this->shader;
	delete this->material;
	delete this->light;
	delete this->texture2D;
}

void DrawData::setShader(const Shader& shader){
	this->shader = new Shader(shader);
}