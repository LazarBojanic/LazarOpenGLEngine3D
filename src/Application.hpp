#pragma once

#include "Util.hpp"
#include "Game.hpp"

class Application {
public:
	Application(unsigned int width, unsigned int height);
	~Application();
	unsigned int width;
	unsigned int height;
	GLFWwindow* window;
	void initGlfw();
	void initGlad();
	void initWindow();
	void run();
};