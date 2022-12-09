#include "IndexBuffer.hpp"

IndexBuffer::IndexBuffer(unsigned int* data, unsigned int dataSize) {
	glGenBuffers(1, &this->iboID);
	bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, dataSize, data, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer() {
}

void IndexBuffer::bind() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->iboID);
}

void IndexBuffer::unbind() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
