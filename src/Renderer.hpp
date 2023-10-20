#pragma once

#include "Util.hpp"
#include "GameObject.hpp"
#include "GameObjectManager.hpp"
#include "ResourceManager.hpp"
#include "Camera.hpp"
#include "Skybox.hpp"

class Renderer {
private:
	Renderer();
	~Renderer();
	static Renderer* instance;

public:
	static Renderer* getInstance();
	void draw(GameObject& gameObject, Camera& camera, bool scaled);
	void drawAll(Camera& camera, bool scaled);
	void drawSkybox(Camera& camera, std::string skyboxName);
	void colorBackground(glm::vec4 color);
};