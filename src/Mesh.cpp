#include "Mesh.hpp"

Mesh::Mesh() {
	HRESULT guidResult = CoCreateGuid(&this->id);
	this->data = nullptr;
	this->indices = nullptr;
	this->name = "";
	this->vertexArray = nullptr;
	this->vertexBuffer = nullptr;
	this->indices = nullptr;
	this->indexed = true;
	this->indicesCount = 0;
	this->unindexedVertexCount = 0;
}
Mesh::Mesh(Primitive* primitive, std::string name, int positionAttributeNumber, int positionDimensions, int colorAttributeNumber, int colorDimensions, int textureAttributeNumber, int textureDimensions, unsigned int normalAttributeNumber, unsigned int normalDimensions) {
	HRESULT guidResult = CoCreateGuid(&this->id);
	this->name = name;
	this->primitive = new Primitive(*primitive);
	this->vertexArray = new VertexArray();
	this->vertexArray->bind();
	this->vertexBuffer = new VertexBuffer(
		primitive,
		positionAttributeNumber,
		positionDimensions,
		colorAttributeNumber,
		colorDimensions,
		textureAttributeNumber,
		textureDimensions,
		normalAttributeNumber,
		normalDimensions,
		indexed);
	this->vertexArray->unbind();
	this->indices = primitive->getIndices();
	this->indexed = primitive->getIsIndexed();
	this->indicesCount = primitive->getIndicesCount();
	this->unindexedVertexCount = primitive->getUnindexedVertexCount();
}

Mesh::~Mesh(){
	delete this->primitive;
	delete this->vertexArray;
	delete this->vertexBuffer;
	delete[] this->data;
	delete[] this->indices;
}