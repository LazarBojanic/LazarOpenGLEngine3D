#pragma once

#include "Primitive.hpp"

class OtherCube : public Primitive {
public:
	OtherCube() {
		this->data = new float[396] {
			//positions                  //color                //uvs              //normals
			 -0.5f, -0.5f, -0.5f,        1.0f, 1.0f, 1.0f ,		0.0f, 0.0f,       0.0f, 0.0f, -1.0f,
			 0.5f, -0.5f, -0.5f,		1.0f, 1.0f, 1.0f ,		1.0f, 0.0f, 		0.0f, 0.0f, -1.0f,
			 0.5f, 0.5f, -0.5f,		    1.0f, 1.0f, 1.0f ,		1.0f, 1.0f, 	    0.0f, 0.0f, -1.0f,
			 0.5f, 0.5f, -0.5f,		    1.0f, 1.0f, 1.0f ,		1.0f, 1.0f, 	    0.0f, 0.0f, -1.0f,
			 -0.5f, 0.5f, -0.5f,		1.0f, 1.0f, 1.0f ,		0.0f, 1.0f, 	    0.0f, 0.0f, -1.0f,
			 -0.5f, -0.5f, -0.5f,	    1.0f, 1.0f, 1.0f ,		0.0f, 0.0f, 	    0.0f, 0.0f, -1.0f,
				
			 -0.5f, -0.5f, 0.5f,		1.0f, 1.0f, 1.0f ,		0.0f, 0.0f, 	   0.0f, 0.0f, 1.0f,
			 0.5f, -0.5f, 0.5f,			1.0f, 1.0f, 1.0f ,		1.0f, 0.0f, 	   0.0f, 0.0f, 1.0f,
			 0.5f, 0.5f, 0.5f,			1.0f, 1.0f, 1.0f ,		1.0f, 1.0f, 	   0.0f, 0.0f, 1.0f,
			 0.5f, 0.5f, 0.5f,			1.0f, 1.0f, 1.0f ,		1.0f, 1.0f, 	   0.0f, 0.0f, 1.0f,
			 -0.5f, 0.5f, 0.5f,			1.0f, 1.0f, 1.0f ,		0.0f, 1.0f, 	    0.0f, 0.0f, 1.0f,
			 -0.5f, -0.5f, 0.5f,		1.0f, 1.0f, 1.0f ,		0.0f, 0.0f, 	   0.0f, 0.0f, 1.0f,

			 -0.5f, 0.5f, 0.5f,			1.0f, 1.0f, 1.0f ,		1.0f, 0.0f,       -1.0f, 0.0f, 0.0f,
			 -0.5f, 0.5f, -0.5f,		1.0f, 1.0f, 1.0f ,		1.0f, 1.0f        -1.0f, 0.0f, 0.0f,
			 -0.5f, -0.5f, -0.5f,		1.0f, 1.0f, 1.0f ,		0.0f, 1.0f        -1.0f, 0.0f, 0.0f,
			 -0.5f, -0.5f, -0.5f,		1.0f, 1.0f, 1.0f ,		0.0f, 1.0f        -1.0f, 0.0f, 0.0f,
			 -0.5f, -0.5f, 0.5f,		1.0f, 1.0f, 1.0f ,		0.0f, 0.0f,       -1.0f, 0.0f, 0.0f,
			 -0.5f, 0.5f, 0.5f,			1.0f, 1.0f, 1.0f ,		1.0f, 0.0f,       -1.0f, 0.0f, 0.0f,

			0.5f, 0.5f, 0.5f,			1.0f, 1.0f, 1.0f ,		1.0f, 0.0f,        1.0f, 0.0f, 0.0f,
			 0.5f, 0.5f, -0.5f,			1.0f, 1.0f, 1.0f ,		1.0f, 1.0f,       1.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, -0.5f,		1.0f, 1.0f, 1.0f ,		0.0f, 1.0f, 		1.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, -0.5f,		1.0f, 1.0f, 1.0f ,		0.0f, 1.0f, 		1.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.5f,			1.0f, 1.0f, 1.0f ,		0.0f, 0.0f,        1.0f, 0.0f, 0.0f,
			 0.5f, 0.5f, 0.5f,			1.0f, 1.0f, 1.0f ,		1.0f, 0.0f,        1.0f, 0.0f, 0.0f,

			 -0.5f, -0.5f, -0.5f,		1.0f, 1.0f, 1.0f ,		 0.0f, 1.0f, 		0.0f, -1.0f, 0.0f,
			 0.5f, -0.5f, -0.5f,		1.0f, 1.0f, 1.0f ,		 1.0f, 1.0f, 		0.0f, -1.0f, 0.0f,
			 0.5f, -0.5f, 0.5f,			1.0f, 1.0f, 1.0f ,		 1.0f, 0.0f, 		0.0f, -1.0f, 0.0f,
			 0.5f, -0.5f, 0.5f,			1.0f, 1.0f, 1.0f ,		 1.0f, 0.0f, 		0.0f, -1.0f, 0.0f,
			 -0.5f, -0.5f, 0.5f,		1.0f, 1.0f, 1.0f ,		 0.0f, 0.0f,		 0.0f, -1.0f, 0.0f,
			 -0.5f, -0.5f, -0.5f,		1.0f, 1.0f, 1.0f ,		 0.0f, 1.0f, 		0.0f, -1.0f, 0.0f,

			 -0.5f, 0.5f, -0.5f,		1.0f, 1.0f, 1.0f ,		 0.0f, 1.0f,        0.0f, 1.0f, 0.0f,
			0.5f, 0.5f, -0.5f,			1.0f, 1.0f, 1.0f ,		 1.0f, 1.0f,       0.0f, 1.0f, 0.0f,
	 		0.5f, 0.5f, 0.5f,			1.0f, 1.0f, 1.0f ,		 1.0f, 0.0f,        0.0f, 1.0f, 0.0f,
			0.5f, 0.5f, 0.5f,			1.0f, 1.0f, 1.0f ,		 1.0f, 0.0f,        0.0f, 1.0f, 0.0f,
	 		-0.5f, 0.5f, 0.5f,			1.0f, 1.0f, 1.0f ,		 0.0f, 0.0f,       0.0f, 1.0f, 0.0f,
			 -0.5f, 0.5f, -0.5f,		1.0f, 1.0f, 1.0f ,		 0.0f, 1.0f, 	    0.0f, 1.0f, 0.0f
		};
		this->dataCount = 396;
		this->dataSize = 396 * sizeof(float);
		this->indices = new unsigned int[108] {
			//Down
			0, 1, 2,
				2, 3, 0,
				//Front
				0, 1, 5,
				5, 4, 0,
				//Right
				1, 2, 6,
				6, 5, 1,
				//Back
				2, 3, 7,
				7, 6, 2,
				//Left
				3, 0, 4,
				4, 7, 3,
				//Up
				4, 5, 6,
				6, 7, 4,


				//Down
				8, 9, 10,
				10, 11, 8,
				//Front
				8, 9, 13,
				13, 12, 8,
				//Right
				9, 10, 14,
				14, 13, 9,
				//Back
				10, 11, 15,
				15, 14, 10,
				//Left
				11, 8, 12,
				12, 15, 11,
				//Up
				12, 13, 14,
				14, 15, 12,


				//Down
				16, 17, 18,
				18, 19, 16,
				//Front
				16, 17, 21,
				21, 20, 16,
				//Right
				17, 18, 22,
				22, 21, 17,
				//Back
				18, 19, 23,
				23, 22, 18,
				//Left
				19, 16, 20,
				20, 23, 19,
				//Up
				20, 21, 22,
				22, 23, 20,
		};
		this->indicesCount = 108;
		this->indicesSize = 108 * sizeof(unsigned int);
	}
};