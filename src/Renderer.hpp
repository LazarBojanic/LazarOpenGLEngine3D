#pragma once

#include "GLData.hpp"
#include "GameObject.hpp"
#include "GameObjectManager.hpp"
#include "ResourceManager.hpp"
#include "Camera.hpp"

class Renderer {
private:
	Renderer();
	~Renderer();
	static Renderer* instance;

public:
	static Renderer* getInstance();
	void draw(GameObject& gameObject, Camera& camera, bool scaled);
	void drawAll(Camera& camera, bool scaled);
	void drawModel(GameObject& gameObject, Camera& camera, bool scaled);
	void colorBackground(glm::vec4 color);
};