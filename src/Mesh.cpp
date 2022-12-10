#include "Mesh.hpp"

Mesh::Mesh() {
	HRESULT guidResult = CoCreateGuid(&this->id);
	this->data = nullptr;
	this->indices = nullptr;
	this->vertexCount = 0;
	this->name = "";
	this->textureChannel = 0;
	this->texture2D = nullptr;
	this->vertexArray = nullptr;
	this->vertexBuffer = nullptr;
}
Mesh::Mesh(Primitive& primitive, std::string name, int positionAttributeNumber, int positionDimensions, int colorAttributeNumber, int colorDimensions, int textureAttributeNumber, int textureDimensions, unsigned int normalAttributeNumber, unsigned int normalDimensions) {
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
		normalDimensions);
	this->vertexArray->unbind();
}

Mesh::~Mesh(){
	delete this->primitive;
	delete this->texture2D;
	delete this->vertexArray;
	delete this->vertexBuffer;
	delete[] this->data;
	delete[] this->indices;
}