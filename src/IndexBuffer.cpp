#include "IndexBuffer.hpp"

IndexBuffer::IndexBuffer(std::vector<unsigned int>* indices) {
	glGenBuffers(1, &this->iboID);
	bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices->size() * sizeof(unsigned int), &indices->at(0), GL_STATIC_DRAW);
}
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
