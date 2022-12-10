#include "VertexBuffer.hpp"

VertexBuffer::VertexBuffer(float* data, unsigned int dataSize, unsigned int* indices, unsigned int indicesSize, unsigned int positionAttributeNumber, unsigned int positionDimensions, unsigned int colorAttributeNumber, unsigned int colorDimensions, unsigned int textureAttributeNumber, unsigned int textureDimensions, unsigned int normalAttributeNumber, unsigned int normalDimensions, bool indexed) {
	this->data = data;
	this->dataSize = dataSize;
	glGenBuffers(1, &this->vboID);
	bind();
	glBufferData(GL_ARRAY_BUFFER, dataSize, data, GL_STATIC_DRAW);
	if (indexed) {
		this->indexBuffer = new IndexBuffer(indices, indicesSize);
	}
	glEnableVertexAttribArray(positionAttributeNumber);
	glVertexAttribPointer(positionAttributeNumber, positionDimensions, GL_FLOAT, GL_FALSE, (positionDimensions + colorDimensions + textureDimensions + normalDimensions) * sizeof(float), (void*)0);
	glEnableVertexAttribArray(colorAttributeNumber);
	glVertexAttribPointer(colorAttributeNumber, colorDimensions, GL_FLOAT, GL_FALSE, (positionDimensions + colorDimensions + textureDimensions + normalDimensions) * sizeof(float), (void*)(positionDimensions * sizeof(float)));
	glEnableVertexAttribArray(textureAttributeNumber);
	glVertexAttribPointer(textureAttributeNumber, textureDimensions, GL_FLOAT, GL_FALSE, (positionDimensions + colorDimensions + textureDimensions + normalDimensions) * sizeof(float), (void*)((positionDimensions + colorDimensions) * sizeof(float)));
	glEnableVertexAttribArray(normalAttributeNumber);
	glVertexAttribPointer(normalAttributeNumber, normalDimensions, GL_FLOAT, GL_FALSE, (positionDimensions + colorDimensions + textureDimensions + normalDimensions) * sizeof(float), (void*)((positionDimensions + colorDimensions + textureDimensions) * sizeof(float)));
}
VertexBuffer::VertexBuffer(Primitive& primitive, unsigned int positionAttributeNumber, unsigned int positionDimensions, unsigned int colorAttributeNumber, unsigned int colorDimensions, unsigned int textureAttributeNumber, unsigned int textureDimensions, unsigned int normalAttributeNumber, unsigned int normalDimensions, bool indexed){
	glGenBuffers(1, &this->vboID);
	bind();
	glBufferData(GL_ARRAY_BUFFER, primitive.getDataSize(), primitive.getData(), GL_STATIC_DRAW);
	if (indexed) {
		this->indexBuffer = new IndexBuffer(primitive.getIndices(), primitive.getIndicesSize());
	}
	
	glEnableVertexAttribArray(positionAttributeNumber);
	glVertexAttribPointer(positionAttributeNumber, positionDimensions, GL_FLOAT, GL_FALSE, (positionDimensions + colorDimensions + textureDimensions + normalDimensions) * sizeof(float), (void*)0);
	glEnableVertexAttribArray(colorAttributeNumber);
	glVertexAttribPointer(colorAttributeNumber, colorDimensions, GL_FLOAT, GL_FALSE, (positionDimensions + colorDimensions + textureDimensions + normalDimensions) * sizeof(float), (void*)(positionDimensions * sizeof(float)));
	glEnableVertexAttribArray(textureAttributeNumber);
	glVertexAttribPointer(textureAttributeNumber, textureDimensions, GL_FLOAT, GL_FALSE, (positionDimensions + colorDimensions + textureDimensions + normalDimensions) * sizeof(float), (void*)((positionDimensions + colorDimensions) * sizeof(float)));
	glEnableVertexAttribArray(normalAttributeNumber);
	glVertexAttribPointer(normalAttributeNumber, normalDimensions, GL_FLOAT, GL_FALSE, (positionDimensions + colorDimensions + textureDimensions + normalDimensions) * sizeof(float), (void*)((positionDimensions + colorDimensions + textureDimensions) * sizeof(float)));
}
VertexBuffer::~VertexBuffer() {
	delete this->indexBuffer;
}
void VertexBuffer::bind() {
	glBindBuffer(GL_ARRAY_BUFFER, this->vboID);
}
void VertexBuffer::unbind() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}