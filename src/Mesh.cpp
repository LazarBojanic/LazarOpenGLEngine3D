#include "Mesh.hpp"

Mesh::Mesh() {
	HRESULT guidResult = CoCreateGuid(&this->id);
	this->data = nullptr;
	this->indices = nullptr;
	this->vertexCount = 0;
	this->name = "";
	this->vertexArray = nullptr;
	this->vertexBuffer = nullptr;
	this->indices = nullptr;
	this->vertexCount = 0;
}
Mesh::Mesh(Primitive& primitive, std::string name, int positionAttributeNumber, int positionDimensions, int colorAttributeNumber, int colorDimensions, int textureAttributeNumber, int textureDimensions, unsigned int normalAttributeNumber, unsigned int normalDimensions, bool indexed) {
	HRESULT guidResult = CoCreateGuid(&this->id);
	this->name = name;
	this->primitive = new Primitive(primitive);
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
	this->indices = primitive.getIndices();
	this->vertexCount = primitive.getIndicesCount();
}

Mesh::~Mesh(){
	delete this->primitive;
	delete this->vertexArray;
	delete this->vertexBuffer;
	delete[] this->data;
	delete[] this->indices;
}