#pragma once

#include "Primitive.hpp"

class Cube : public Primitive {
public:
	Cube() {
		this->data = new float[64] {
		   //positions             colors              texture coordinates
			-0.5f, -0.5f, -0.5f,   1.0f, 0.0f, 0.0f,   0.0f, 0.0f, //LDF
			 0.5f, -0.5f, -0.5f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, //RDF
			-0.5f, -0.5f,  0.5f,   0.0f, 0.0f, 1.0f,   1.0f, 1.0f, //LDB
			 0.5f, -0.5f,  0.5f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f, //RDB
			-0.5f,  0.5f, -0.5f,   1.0f, 0.5f, 0.0f,   0.0f, 0.0f, //LUF
			 0.5f,  0.5f, -0.5f,   1.0f, 0.0f, 1.0f,   1.0f, 0.0f, //RUF
			-0.5f,  0.5f,  0.5f,   0.0f, 0.0f, 0.0f,   1.0f, 1.0f, //LUB
			 0.5f,  0.5f,  0.5f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f  //RUB
		};
		this->dataCount = 64;
		this->dataSize = 64 * sizeof(float);
		this->indices = new unsigned int[36] {
			//Down
			0, 1, 2,
			2, 1, 3,
			//Front
			0, 1, 4,
			4, 1, 5,
			//Right
			1, 3, 7,
			7, 5, 1,
			//Back
			3, 2, 7,
			7, 2, 6,
			//Left
			2, 0, 4,
			4, 6, 2,
			//Up
			4, 5, 7,
			7, 6, 4
		};
		this->indicesCount = 36;
		this->indicesSize = 36 * sizeof(unsigned int);
	}
};