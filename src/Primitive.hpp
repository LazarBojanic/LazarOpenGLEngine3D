#pragma once



class Primitive {
public:
	bool indexed;
	float* data;
	unsigned int dataCount;
	unsigned int dataSize;
	unsigned int* indices;
	unsigned int indicesCount;
	unsigned int indicesSize;
	unsigned int unindexedVertexCount;
	inline bool getIsIndexed() {
		return this->indexed;
	}
	inline float* getData() {
		return this->data;
	}
	inline unsigned int getDataCount() {
		return this->dataCount;
	}
	inline unsigned int getDataSize() {
		return this->dataSize;
	}
	inline unsigned int* getIndices() {
		return this->indices;
	}
	inline unsigned int getIndicesCount() {
		return this->indicesCount;
	}
	inline unsigned int getIndicesSize() {
		return this->indicesSize;
	}
	inline unsigned int getUnindexedVertexCount() {
		return this->unindexedVertexCount;
	}
};