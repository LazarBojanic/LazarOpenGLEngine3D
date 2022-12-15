#pragma once

#include "GLData.hpp"
#include "VertexArray.hpp"
#include "VertexBuffer.hpp"
#include "IndexBuffer.hpp"
#include "Primitive.hpp"

class Mesh {
private:
	GUID id;
	std::string name;
	VertexArray* vertexArray;
	VertexBuffer* vertexBuffer;
	Primitive* primitive;
	float* data;
	float unindexedVertexCount;
	unsigned int* indices;
	unsigned int indicesCount;
	bool indexed;
public:
	Mesh();
	Mesh(Primitive* primitive, std::string name, int positionAttributeNumber, int positionDimensions, int colorAttributeNumber, int colorDimensions, int textureAttributeNumber, int textureDimensions, unsigned int normalAttributeNumber, unsigned int normalDimensions);
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
	inline float getIsIndexed() {
		return this->indexed;
	}
};