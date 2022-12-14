#pragma once



class Primitive {
public:
	float* data;
	unsigned int dataCount;
	unsigned int dataSize;
	unsigned int* indices;
	unsigned int indicesCount;
	unsigned int indicesSize;
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
};