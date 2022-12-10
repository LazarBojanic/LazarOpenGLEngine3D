#pragma once

#include "GLData.hpp"
#include "GameObject.hpp"
#include "ResourceManager.hpp"
#include "Camera.hpp"

class Renderer {
private:
	Renderer();
	~Renderer();
	static Renderer* instance;

public:
	static Renderer* getInstance();
	void draw(GameObject& gameObject, Camera& camera, float width, float height, bool scaled, bool indexed, bool textured);
	void colorBackground(glm::vec4 color);
};