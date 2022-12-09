#pragma once



class Primitive {
public:
	float* data;
	unsigned int dataCount;
	unsigned int dataSize;
	unsigned int* indices;
	unsigned int indicesCount;
	unsigned int indicesSize;
	float* getData() {
		return this->data;
	}
	unsigned int getDataCount() {
		return this->dataCount;
	}
	unsigned int getDataSize() {
		return this->dataSize;
	}
	unsigned int* getIndices() {
		return this->indices;
	}
	unsigned int getIndicesCount() {
		return this->indicesCount;
	}
	unsigned int getIndicesSize() {
		return this->indicesSize;
	}
};