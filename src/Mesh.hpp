#pragma once

#include "GLData.hpp"
#include "VertexArray.hpp"
#include "VertexBuffer.hpp"
#include "IndexBuffer.hpp"
#include "Texture2D.hpp"
#include "Primitive.hpp"

class Mesh {
private:
	GUID id;
	std::string name;
	VertexArray* vertexArray;
	VertexBuffer* vertexBuffer;
	Primitive* primitive;
	unsigned int textureChannel;
	Texture2D* texture2D;
	float* data;
	unsigned int* indices;
	unsigned int vertexCount;
public:
	Mesh();
	Mesh(Primitive& primitive, std::string name, int positionAttributeNumber, int positionDimensions, int colorAttributeNumber, int colorDimensions, int textureAttributeNumber, int textureDimensions);
	Mesh(float* data, unsigned int dataSize, unsigned int* indices, unsigned int indicesSize, std::string name, int positionAttributeNumber, int positionDimensions, int colorAttributeNumber, int colorDimensions, int textureAttributeNumber, int textureDimensions, const Texture2D& texture2D, unsigned int textureChannel);
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
	inline unsigned int getTextureChannel() {
		return this->textureChannel;
	}
	inline Texture2D* getTexture2D() {
		return this->texture2D;
	}
	inline float* getData() {
		return this->data;
	}
	inline unsigned int* getIndices() {
		return this->indices;
	}
	inline unsigned int getVertexCount() {
		return this->vertexCount;
	}
};