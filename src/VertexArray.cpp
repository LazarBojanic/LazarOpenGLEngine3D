#include "VertexArray.hpp"

VertexArray::VertexArray() {
	glGenVertexArrays(1, &this->vaoID);
}

VertexArray::~VertexArray() {
}

void VertexArray::bind() {
	glBindVertexArray(this->vaoID);
}

void VertexArray::unbind() {
	glBindVertexArray(0);
}
