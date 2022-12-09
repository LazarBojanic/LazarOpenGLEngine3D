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

Mesh::Mesh(float* data, unsigned int dataSize, unsigned int* indices, unsigned int indicesSize, std::string name, int positionAttributeNumber, int positionDimensions, int colorAttributeNumber, int colorDimensions, int textureAttributeNumber, int textureDimensions, const Texture2D& texture2D, unsigned int textureChannel){
	HRESULT guidResult = CoCreateGuid(&this->id);
	this->data = data;
	this->indices = indices;
	this->vertexCount = indicesSize;
	this->name = name;
	this->textureChannel = textureChannel;
	this->texture2D = new Texture2D(texture2D);
	this->vertexArray = new VertexArray();
	this->vertexArray->bind();
	this->vertexBuffer = new VertexBuffer(
		data,
		dataSize,
		indices,
		indicesSize,
		positionAttributeNumber,
		positionDimensions,
		colorAttributeNumber,
		colorDimensions,
		textureAttributeNumber,
		textureDimensions);
	this->texture2D->bind(this->textureChannel);
	this->vertexArray->unbind();
}
Mesh::Mesh(Primitive& primitive, std::string name, int positionAttributeNumber, int positionDimensions, int colorAttributeNumber, int colorDimensions, int textureAttributeNumber, int textureDimensions) {
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
		textureDimensions);
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