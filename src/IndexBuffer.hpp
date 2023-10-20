#pragma once

#include "Util.hpp"

class IndexBuffer {
private:
	unsigned int iboID;
public:
	IndexBuffer(unsigned int* data, unsigned int dataSize);
	IndexBuffer(std::vector<unsigned int> indices);
	~IndexBuffer();
	void bind();
	void unbind();
	unsigned int getIboID() {
		return this->iboID;
	}
};