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
VertexBuffer::VertexBuffer(Primitive* primitive, unsigned int positionAttributeNumber, unsigned int positionDimensions, unsigned int colorAttributeNumber, unsigned int colorDimensions, unsigned int textureAttributeNumber, unsigned int textureDimensions, unsigned int normalAttributeNumber, unsigned int normalDimensions, bool indexed){
	glGenBuffers(1, &this->vboID);
	bind();
	glBufferData(GL_ARRAY_BUFFER, primitive->getDataSize(), primitive->getData(), GL_STATIC_DRAW);
	if (indexed) {
		this->indexBuffer = new IndexBuffer(primitive->getIndices(), primitive->getIndicesSize());
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


VertexBuffer::VertexBuffer(std::vector<GeometryVertex> vertices, std::vector<unsigned int>* indices) {
	glGenBuffers(1, &this->vboID);
	bind();
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GeometryVertex), &vertices.at(0), GL_STATIC_DRAW);
	this->indexBuffer = new IndexBuffer(indices);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GeometryVertex), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(GeometryVertex), (void*)offsetof(GeometryVertex, normal));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(GeometryVertex), (void*)offsetof(GeometryVertex, textureCoords));
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(GeometryVertex), (void*)offsetof(GeometryVertex, tangent));
	glEnableVertexAttribArray(4);
	glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(GeometryVertex), (void*)offsetof(GeometryVertex, bitangent));
	glEnableVertexAttribArray(5);
	glVertexAttribIPointer(5, 4, GL_INT, sizeof(GeometryVertex), (void*)offsetof(GeometryVertex, boneIds));
	glEnableVertexAttribArray(6);
	glVertexAttribPointer(6, 4, GL_FLOAT, GL_FALSE, sizeof(GeometryVertex), (void*)offsetof(GeometryVertex, weights));



	

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