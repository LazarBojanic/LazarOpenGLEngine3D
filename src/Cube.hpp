#pragma once

#include "Primitive.hpp"

class Cube : public Primitive {
public:
	Cube(bool indexed) {
		this->indexed = indexed;
		if (this->indexed) {
			this->data = new float[264] {
		   //positions             colors              uvs              normals
			//Down
			-0.5f, -0.5f, -0.5f,   1.0f, 1.0f, 0.0f,   0.0f,  0.0f,   0.0f, -1.0f,  0.0f,		//LDB
			 0.5f, -0.5f, -0.5f,   0.0f, 0.0f, 1.0f,   1.0f,  0.0f,   0.0f, -1.0f,  0.0f,		//RDB
			-0.5f, -0.5f,  0.5f,   1.0f, 0.0f, 0.0f,   0.0f,  1.0f,   0.0f, -1.0f,  0.0f,		//LDF
			 0.5f, -0.5f,  0.5f,   0.0f, 1.0f, 0.0f,   1.0f,  1.0f,   0.0f, -1.0f,  0.0f,		//RDF
			//Front				   				 	 			    
			-0.5f, -0.5f,  0.5f,   1.0f, 0.0f, 0.0f,   0.0f,  0.0f,   0.0f,  0.0f,  1.0f,		//LDF
			 0.5f, -0.5f,  0.5f,   0.0f, 1.0f, 0.0f,   1.0f,  0.0f,   0.0f,  0.0f,  1.0f,		//RDF
			-0.5f,  0.5f,  0.5f,   0.0f, 1.0f, 1.0f,   0.0f,  1.0f,   0.0f,  0.0f,  1.0f,		//LUF
			 0.5f,  0.5f,  0.5f,   1.0f, 0.0f, 1.0f,   1.0f,  1.0f,   0.0f,  0.0f,  1.0f,		//RUF
			//Right				   				      			    
			 0.5f, -0.5f, -0.5f,   0.0f, 0.0f, 1.0f,   0.0f,  0.0f,   1.0f,  0.0f,  0.0f,		//RDB
			 0.5f,  0.5f, -0.5f,   0.0f, 0.0f, 0.0f,   1.0f,  0.0f,   1.0f,  0.0f,  0.0f,		//RUB
			 0.5f, -0.5f,  0.5f,   0.0f, 1.0f, 0.0f,   0.0f,  1.0f,   1.0f,  0.0f,  0.0f,		//RDF
			 0.5f,  0.5f,  0.5f,   1.0f, 0.0f, 1.0f,   1.0f,  1.0f,   1.0f,  0.0f,  0.0f,		//RUF
			//Back				   				      			    
			-0.5f, -0.5f, -0.5f,   1.0f, 1.0f, 0.0f,   0.0f,  0.0f,   0.0f,  0.0f, -1.0f,		//LDB
			 0.5f, -0.5f, -0.5f,   0.0f, 0.0f, 1.0f,   1.0f,  0.0f,   0.0f,  0.0f, -1.0f,	    //RDB
			-0.5f,  0.5f, -0.5f,   1.0f, 1.0f, 1.0f,   0.0f,  1.0f,   0.0f,  0.0f, -1.0f,		//LUB
			 0.5f,  0.5f, -0.5f,   0.0f, 0.0f, 0.0f,   1.0f,  1.0f,   0.0f,  0.0f, -1.0f,		//RUB
			//Left				   				      
			-0.5f, -0.5f, -0.5f,   1.0f, 1.0f, 0.0f,   0.0f,  0.0f,  -1.0f,  0.0f,  0.0f,		//LDB
			-0.5f,  0.5f, -0.5f,   1.0f, 1.0f, 1.0f,   1.0f,  0.0f,  -1.0f,  0.0f,  0.0f,		//LUB
			-0.5f, -0.5f,  0.5f,   1.0f, 0.0f, 0.0f,   0.0f,  1.0f,  -1.0f,  0.0f,  0.0f, 		//LDF
			-0.5f,  0.5f,  0.5f,   0.0f, 1.0f, 1.0f,   1.0f,  1.0f,  -1.0f,  0.0f,  0.0f,		//LUF
			//Up				   				      
			-0.5f,  0.5f, -0.5f,   1.0f, 1.0f, 1.0f,   0.0f,  0.0f,   0.0f,  1.0f,  0.0f,		//LUB
			 0.5f,  0.5f, -0.5f,   0.0f, 0.0f, 0.0f,   1.0f,  0.0f,   0.0f,  1.0f,  0.0f,		//RUB		
			-0.5f,  0.5f,  0.5f,   0.0f, 1.0f, 1.0f,   0.0f,  1.0f,   0.0f,  1.0f,  0.0f,		//LUF
			 0.5f,  0.5f,  0.5f,   1.0f, 0.0f, 1.0f,   1.0f,  1.0f,   0.0f,  1.0f,  0.0f		//RUF
			};
			this->unindexedVertexCount = 0;
			this->dataCount = 264;
			this->dataSize = 264 * sizeof(float);
			
			this->indices = new unsigned int[36] {
					//Down
					0, 1, 2,
					1, 2, 3,
					//Front
					4, 5, 6,
					5, 6, 7,
					//Right
					8, 9, 10,
					9, 10, 11,
					//Back
					12, 13, 14,
					13, 14, 15,
					//Left
					16, 17, 18,
					17, 18, 19,
					//Up
					20, 21, 22,
					21, 22, 23
			};
			this->indicesCount = 36;
			this->indicesSize = 36 * sizeof(unsigned int);
		}
		else {
			this->data = new float[396] {
			   //positions              colors                 uvs              normals
			    -0.5f, -0.5f, -0.5f,    1.0f, 1.0f, 0.0f,    0.0f,  0.0f,     0.0f,  0.0f, -1.0f,
				 0.5f, -0.5f, -0.5f,    0.0f, 0.0f, 1.0f,	 1.0f,  0.0f,     0.0f,  0.0f, -1.0f,
				 0.5f,  0.5f, -0.5f,    0.0f, 0.0f, 0.0f,	 1.0f,  1.0f,     0.0f,  0.0f, -1.0f,
				 0.5f,  0.5f, -0.5f,    0.0f, 0.0f, 0.0f,    1.0f,  1.0f,     0.0f,  0.0f, -1.0f,
				-0.5f,  0.5f, -0.5f,    1.0f, 1.0f, 1.0f,    0.0f,  1.0f,     0.0f,  0.0f, -1.0f,
				-0.5f, -0.5f, -0.5f,    1.0f, 1.0f, 0.0f,    0.0f,  0.0f,     0.0f,  0.0f, -1.0f,
									    	    	   		    		        
				-0.5f, -0.5f,  0.5f,    1.0f, 0.0f, 0.0f,    0.0f,  0.0f,     0.0f,  0.0f,  1.0f,
				 0.5f, -0.5f,  0.5f,    0.0f, 1.0f, 0.0f,    1.0f,  0.0f,     0.0f,  0.0f,  1.0f,
				 0.5f,  0.5f,  0.5f,    1.0f, 0.0f, 1.0f,    1.0f,  1.0f,     0.0f,  0.0f,  1.0f,
				 0.5f,  0.5f,  0.5f,    1.0f, 0.0f, 1.0f,    1.0f,  1.0f,     0.0f,  0.0f,  1.0f,
				-0.5f,  0.5f,  0.5f,    0.0f, 1.0f, 1.0f,    0.0f,  1.0f,     0.0f,  0.0f,  1.0f,
				-0.5f, -0.5f,  0.5f,    1.0f, 0.0f, 0.0f,    0.0f,  0.0f,     0.0f,  0.0f,  1.0f,
									    	    	   		    		        	    
				-0.5f,  0.5f,  0.5f,	0.0f, 1.0f, 1.0f,    1.0f,  0.0f,    -1.0f,  0.0f,  0.0f,
				-0.5f,  0.5f, -0.5f,    1.0f, 1.0f, 1.0f,    1.0f,  1.0f,	 -1.0f,  0.0f,  0.0f,
				-0.5f, -0.5f, -0.5f,    1.0f, 1.0f, 0.0f,    0.0f,  1.0f,	 -1.0f,  0.0f,  0.0f,
				-0.5f, -0.5f, -0.5f,    1.0f, 1.0f, 0.0f,    0.0f,  1.0f,	 -1.0f,  0.0f,  0.0f,
				-0.5f, -0.5f,  0.5f,    1.0f, 0.0f, 0.0f,    0.0f,  0.0f,	 -1.0f,  0.0f,  0.0f,
				-0.5f,  0.5f,  0.5f,	0.0f, 1.0f, 1.0f,    1.0f,  0.0f,    -1.0f,  0.0f,  0.0f,
									    	    	   		    		        	    
				 0.5f,  0.5f,  0.5f,    1.0f, 0.0f, 1.0f,    1.0f,  0.0f,     1.0f,  0.0f,  0.0f,
				 0.5f,  0.5f, -0.5f,    0.0f, 0.0f, 0.0f,    1.0f,  1.0f,     1.0f,  0.0f,  0.0f,
				 0.5f, -0.5f, -0.5f,    0.0f, 0.0f, 1.0f,    0.0f,  1.0f,     1.0f,  0.0f,  0.0f,
				 0.5f, -0.5f, -0.5f,    0.0f, 0.0f, 1.0f,    0.0f,  1.0f,     1.0f,  0.0f,  0.0f,
				 0.5f, -0.5f,  0.5f,    0.0f, 1.0f, 0.0f,    0.0f,  0.0f,     1.0f,  0.0f,  0.0f,
				 0.5f,  0.5f,  0.5f,    1.0f, 0.0f, 1.0f,    1.0f,  0.0f,     1.0f,  0.0f,  0.0f,
									    	    	   		    		        	    
				-0.5f, -0.5f, -0.5f,    1.0f, 1.0f, 0.0f,    0.0f,  1.0f,     0.0f, -1.0f,  0.0f,
				 0.5f, -0.5f, -0.5f,    0.0f, 0.0f, 1.0f,    1.0f,  1.0f,     0.0f, -1.0f,  0.0f,
				 0.5f, -0.5f,  0.5f,    0.0f, 1.0f, 0.0f,    1.0f,  0.0f,     0.0f, -1.0f,  0.0f,
				 0.5f, -0.5f,  0.5f,    0.0f, 1.0f, 0.0f,    1.0f,  0.0f,     0.0f, -1.0f,  0.0f,
				-0.5f, -0.5f,  0.5f,    1.0f, 0.0f, 0.0f,    0.0f,  0.0f,     0.0f, -1.0f,  0.0f,
				-0.5f, -0.5f, -0.5f,    1.0f, 1.0f, 0.0f,    0.0f,  1.0f,     0.0f, -1.0f,  0.0f,
									    	    	   		    		        	    
				-0.5f,  0.5f, -0.5f,    1.0f, 1.0f, 1.0f,    0.0f,  1.0f,     0.0f,  1.0f,  0.0f,
				 0.5f,  0.5f, -0.5f,    0.0f, 0.0f, 0.0f,    1.0f,  1.0f,     0.0f,  1.0f,  0.0f,
				 0.5f,  0.5f,  0.5f,    1.0f, 0.0f, 1.0f,    1.0f,  0.0f,     0.0f,  1.0f,  0.0f,
				 0.5f,  0.5f,  0.5f,    1.0f, 0.0f, 1.0f,    1.0f,  0.0f,     0.0f,  1.0f,  0.0f,
				-0.5f,  0.5f,  0.5f,    1.0f, 0.5f, 0.0f,    0.0f,  0.0f,     0.0f,  1.0f,  0.0f,
				-0.5f,  0.5f, -0.5f,    1.0f, 1.0f, 1.0f,    0.0f,  1.0f,     0.0f,  1.0f,  0.0f
			};
			this->unindexedVertexCount = 36;
			this->dataCount = 396;
			this->dataSize = 396 * sizeof(float);

			this->indices = nullptr;
			this->indicesCount = 0;
			this->indicesSize = 0;
		}
	}
};