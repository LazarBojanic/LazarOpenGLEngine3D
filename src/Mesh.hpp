#pragma once

#include "GLData.hpp"
#include "Primitive.hpp"
#include "Model.hpp"

class Mesh {
private:
	GUID id;
	std::string name;
	VertexArray* vertexArray;
	VertexBuffer* vertexBuffer;
	Primitive* primitive;
	Model* model;
	float* data;
	float unindexedVertexCount;
	unsigned int* indices;
	unsigned int indicesCount;
	bool indexed;
public:
	Mesh();
	Mesh(Primitive* primitive, Model* model, std::string name, int positionAttributeNumber, int positionDimensions, int colorAttributeNumber, int colorDimensions, int textureAttributeNumber, int textureDimensions, unsigned int normalAttributeNumber, unsigned int normalDimensions);
	Mesh(Primitive* primitive, std::string name, int positionAttributeNumber, int positionDimensions);
	~Mesh();
	inline GUID getId() {
		return this->id;
	}
	inline std::string getName() {
		return this->name;
	}
	inline VertexArray* getVertexArray() {
		return this->vertexArray;
	}
	inline VertexBuffer* getVertexBuffer() {
		return this->vertexBuffer;
	}
	inline Primitive* getPrimitive() {
		return this->primitive;
	}
	inline Model* getModel() {
		return this->model;
	}
	inline float* getData() {
		return this->data;
	}
	inline unsigned int* getIndices() {
		return this->indices;
	}
	inline unsigned int getIndicesCount() {
		return this->indicesCount;
	}
	inline float getUnindexedVertexCount() {
		return this->unindexedVertexCount;
	}
	inline bool getIsIndexed() {
		return this->indexed;
	}
};