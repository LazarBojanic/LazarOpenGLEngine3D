#include "Mesh.hpp"

Mesh::Mesh() {
	HRESULT guidResult = CoCreateGuid(&this->id);
	this->data = nullptr;
	this->indices = nullptr;
	this->name = "";
	this->primitive = nullptr;
	this->model = nullptr;
	this->vertexArray = nullptr;
	this->vertexBuffer = nullptr;
	this->indices = nullptr;
	this->indexed = true;
	this->indicesCount = 0;
	this->unindexedVertexCount = 0;
}
Mesh::Mesh(Primitive* primitive, Model* model, std::string name, int positionAttributeNumber, int positionDimensions, int colorAttributeNumber, int colorDimensions, int textureAttributeNumber, int textureDimensions, unsigned int normalAttributeNumber, unsigned int normalDimensions) {
	if (primitive != nullptr && model == nullptr) {
		HRESULT guidResult = CoCreateGuid(&this->id);
		this->name = name;
		this->primitive = new Primitive(*primitive);
		this->model = nullptr;
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
	else if (primitive == nullptr && model != nullptr) {
		HRESULT guidResult = CoCreateGuid(&this->id);
		this->name = name;
		this->primitive = nullptr;
		this->model = new Model(*model);
		this->indices = nullptr;
		this->indexed = true;
		this->indicesCount = 0;
		this->unindexedVertexCount = 0;
	}
	else {
		std::cout << "Mesh must have a primitive or model geometry" << std::endl;
		HRESULT guidResult = CoCreateGuid(&this->id);
		this->data = nullptr;
		this->indices = nullptr;
		this->name = "";
		this->primitive == nullptr;
		this->model = nullptr;
		this->vertexArray = nullptr;
		this->vertexBuffer = nullptr;
		this->indices = nullptr;
		this->indexed = true;
		this->indicesCount = 0;
		this->unindexedVertexCount = 0;
	}
}

Mesh::~Mesh(){
	if (this->primitive != nullptr) {
		delete this->primitive;
	}
	if (this->model != nullptr) {
		delete this->model;
	}
	delete this->vertexArray;
	delete this->vertexBuffer;
	delete[] this->data;
	delete[] this->indices;
}