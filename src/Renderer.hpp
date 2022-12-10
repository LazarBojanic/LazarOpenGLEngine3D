#pragma once

#include "GLData.hpp"
#include "GameObject.hpp"
#include "GameObject3D.hpp"
#include "ResourceManager.hpp"
#include "Camera.hpp"

class Renderer {
private:
	Renderer();
	~Renderer();
	static Renderer* instance;

public:
	static Renderer* getInstance();
	void draw(GameObject3D& gameObject3D, Camera& camera, float width, float height, bool scaled, bool indexed, bool textured);
	void colorBackground(glm::vec4 color);
};