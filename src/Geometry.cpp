#include "Geometry.hpp"

Geometry::Geometry(std::vector<GeometryVertex> vertices, std::vector<unsigned int>* indices, std::vector<Texture*>* textures) {
    this->vertices = vertices;
    this->indices = indices;
    this->textures = textures;

    for (int i = 0; i < textures->size(); i++) {
        std::cout << textures->at(i)->getPath() << std::endl;
    }

    generate();
}

Geometry::~Geometry() {
    delete this->indices;
    delete this->textures;
    delete this->vertexArray;
    delete this->vertexBuffer;
}

void Geometry::generate() {
    this->vertexArray = new VertexArray();
	this->vertexArray->bind(); 
    this->vertexBuffer = new VertexBuffer(this->vertices, this->indices);
	this->vertexArray->unbind();
}