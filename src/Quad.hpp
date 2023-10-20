#pragma once

#include "Primitive.hpp"

class Quad : public Primitive {
public:
	Quad(bool indexed) {
		this->indexed = indexed;
		if (this->indexed) {
			this->data = new float[44] {

		   //positions             colors               texture coordinates
			-0.5f, -0.5f, 0.0f,    1.0f, 0.0f, 0.0f,    0.0f, 0.0f,    -1.0f, -1.0f, 1.0f, //bottom left
			 0.5f, -0.5f, 0.0f,    0.0f, 1.0f, 0.0f,    1.0f, 0.0f,     1.0f, -1.0f, 1.0f, //bottom right
			 0.5f,  0.5f, 0.0f,    0.0f, 0.0f, 1.0f,    1.0f, 1.0f,     1.0f,  1.0f, 1.0f, //top right
			-0.5f,  0.5f, 0.0f,    1.0f, 1.0f, 0.0f,	0.0f, 1.0f,    -1.0f,  1.0f, 1.0f //top left
			};
			this->unindexedVertexCount = 6;
			this->dataCount = 44;
			this->dataSize = 44 * sizeof(float);
			this->indices = new unsigned int[6] {
				0, 1, 2,
				2, 3, 0
			};
			this->indicesCount = 6;
			this->indicesSize = 6 * sizeof(unsigned int);
		}
		else {
			this->data = new float[66] {

		   //positions             colors               texture coordinates
			-0.5f, -0.5f, 0.0f,    1.0f, 0.0f, 0.0f,    0.0f, 0.0f,    -1.0f, -1.0f,  1.0f, //bottom left
			 0.5f, -0.5f, 0.0f,    0.0f, 1.0f, 0.0f,    1.0f, 0.0f,     1.0f, -1.0f,  1.0f, //bottom right
			 0.5f,  0.5f, 0.0f,    0.0f, 0.0f, 1.0f,    1.0f, 1.0f,     1.0f,  1.0f,  1.0f, //top right
			 0.5f,  0.5f, 0.0f,    0.0f, 0.0f, 1.0f,    1.0f, 1.0f,     1.0f,  1.0f,  1.0f, //top right
			-0.5f,  0.5f, 0.0f,    1.0f, 1.0f, 0.0f,	0.0f, 1.0f,    -1.0f,  1.0f,  1.0f, //top left
			-0.5f, -0.5f, 0.0f,    1.0f, 0.0f, 0.0f,    0.0f, 0.0f,    -1.0f, -1.0f,  1.0f, //bottom left
			};
			this->unindexedVertexCount = 6;
			this->dataCount = 66;
			this->dataSize = 66 * sizeof(float);
			this->indices = new unsigned int[6] {
				0, 1, 2,
				2, 3, 0
			};
			this->indicesCount = 6;
			this->indicesSize = 6 * sizeof(unsigned int);
		}
	}
};