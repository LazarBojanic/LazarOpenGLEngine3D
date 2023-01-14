#include "Geometry.hpp"

Geometry::Geometry(std::vector<GeometryVertex> vertices, std::vector<unsigned int> indices) {
    this->vertices = vertices;
    this->indices = indices;
    generate();
}

Geometry::~Geometry() {
    delete this->vertexArray;
    delete this->vertexBuffer;
}

void Geometry::generate() {
    this->vertexArray = new VertexArray();
	this->vertexArray->bind(); 
    this->vertexBuffer = new VertexBuffer(this->vertices, this->indices);
	this->vertexArray->unbind();
    
}