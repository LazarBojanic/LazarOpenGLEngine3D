#pragma once

#include "Util.hpp"

class VertexArray {
private:
	unsigned int vaoID;
public:
	VertexArray();
	~VertexArray();
	void bind();
	void unbind();

	unsigned int getVaoID() {
		return this->vaoID;
	}
};