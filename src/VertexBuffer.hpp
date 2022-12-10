#pragma once

#include "GLData.hpp"
#include "IndexBuffer.hpp"
#include "Primitive.hpp"

class VertexBuffer {
private:
	unsigned int vboID;
	float* data;
	unsigned int dataSize;
	IndexBuffer* indexBuffer;
public:
	VertexBuffer(float* data, unsigned int dataSize, unsigned int* indices, unsigned int indicesSize, unsigned int positionAttributeNumber, unsigned int positionDimensions, unsigned int colorAttributeNumber, unsigned int colorDimensions, unsigned int textureAttributeNumber, unsigned int textureDimensions, unsigned int normalAttributeNumber, unsigned int normalDimensions);
	VertexBuffer(Primitive& primitive, unsigned int positionAttributeNumber, unsigned int positionDimensions, unsigned int colorAttributeNumber, unsigned int colorDimensions, unsigned int textureAttributeNumber, unsigned int textureDimensions, unsigned int normalAttributeNumber, unsigned int normalDimensions);
	~VertexBuffer();

	void bind();
	void unbind();

	unsigned int getVboID() {
		return this->vboID;
	}
	float* getData() {
		return this->data;
	}
	unsigned int getDataSize() {
		return this->dataSize;
	}
};