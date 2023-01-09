#include "GeometryVertex.hpp"

GeometryVertex::GeometryVertex(glm::vec3 position, glm::vec3 normal, glm::vec2 textureCoords, glm::vec3 tangent, glm::vec3 bitangent) {
	this->position = position;
	this->normal = normal;
	this->textureCoords = textureCoords;
	this->tangent = tangent;
	this->bitangent = bitangent;
}

GeometryVertex::GeometryVertex() {
	this->position = glm::vec3(0);
	this->normal = glm::vec3(0);
	this->textureCoords = glm::vec2(0);
	this->tangent = glm::vec3(0);
	this->bitangent = glm::vec3(0);
}

GeometryVertex::~GeometryVertex() {
}
