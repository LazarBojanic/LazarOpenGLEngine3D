#pragma once

#include "GLData.hpp"

class IndexBuffer {
private:
	unsigned int iboID;
public:
	IndexBuffer(unsigned int* data, unsigned int dataSize);
	~IndexBuffer();
	void bind();
	void unbind();
	unsigned int getIboID() {
		return this->iboID;
	}
};