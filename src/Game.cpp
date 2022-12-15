#include "Game.hpp"

Game* Game::instance;

Game::Game(GLFWwindow* window, unsigned int width, unsigned int height) {
	this->workingDirectory = std::filesystem::current_path().generic_string();
	this->window = window;
	this->gameState = SCREEN_SAVER;
	this->width = width;
	this->height = height;
	this->keys = new bool[1024];
	initKeys();
	this->startTime = glfwGetTime();
	this->soundEngine = irrklang::createIrrKlangDevice();
}
Game::~Game() {
}

Game* Game::getInstance(GLFWwindow* window, unsigned int width, unsigned int height) {
	if (!instance) {
		instance = new Game(window, width, height);
	}
	return instance;
}
void Game::updateWindowSize(int width, int height) {
	this->width = width;
	this->height = height;
}
void Game::initKeys() {
	for (int i = 0; i < this->keysSize; i++) {
		this->keys[i] = false;
	}
}
Game* Game::getInstance() {
	if (!instance) {
		instance = new Game(nullptr, 0, 0);
	}
	return instance;
}

void Game::initVariables() {
	glfwSetWindowTitle(this->window, "3D Game");
	float lastX = this->width / 2.0f;
	float lastY = this->height / 2.0f;
	bool firstMouse = true;
}
void Game::initResources() {
	this->camera = new Camera(glm::vec3(0.0f, 0.0f, 3.0f), this->width, this->height, 0.1f, 100.0f);
	Cube* cube = new Cube(false);

	Mesh* lightMesh = ResourceManager::getInstance()->addMesh(cube, "lightMesh", 0, 3, 1, 3, 2, 2, 3, 3);
	Mesh* cubeMesh = ResourceManager::getInstance()->addMesh(cube, "cubeMesh", 0, 3, 1, 3, 2, 2, 3, 3);
	Mesh* groundMesh = ResourceManager::getInstance()->addMesh(cube, "groundMesh", 0, 3, 1, 3, 2, 2, 3, 3);

	Shader* lightShader = ResourceManager::getInstance()->addShader(workingDirectory + "\\assets\\shaders\\lightVertexShader.glsl", workingDirectory + "\\assets\\shaders\\lightFragmentShader.glsl", "lightShader");
	Shader* cubeShader = ResourceManager::getInstance()->addShader(workingDirectory + "\\assets\\shaders\\cubeLightingVertexShader.glsl", workingDirectory + "\\assets\\shaders\\cubeLightingFragmentShader.glsl", "cubeShader");
	Shader* groundShader = ResourceManager::getInstance()->addShader(workingDirectory + "\\assets\\shaders\\cubeLightingVertexShader.glsl", workingDirectory + "\\assets\\shaders\\cubeLightingFragmentShader.glsl", "groundShader");

	Material* cubeMaterial = ResourceManager::getInstance()->addMaterial("cubeMaterial", glm::vec3(0.6f, 0.6f, 0.6f), glm::vec3(0.6f, 0.6f, 0.6f), glm::vec3(0.5f, 0.5f, 0.5f), 32);
	Material* groundMaterial = ResourceManager::getInstance()->addMaterial("groundMaterial", glm::vec3(0.2f, 0.2f, 0.2f), glm::vec3(0.6f, 0.6f, 0.6f), glm::vec3(0.5f, 0.5f, 0.5f), 32);

	Light* light = ResourceManager::getInstance()->addLight("light", glm::vec3(2.5f, 2.5f, 2.5f), glm::vec3(0.2f, 0.2f, 0.2f), glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(1.0f, 1.0f, 1.0f));

	lightShader->setVector3f("uLightColor", glm::vec3(1.0f, 1.0f, 1.0f), true);
	cubeShader->setVector3f("uCubeColor", glm::vec3(1.0f, 0.5f, 0.31f), true);
	groundShader->setVector3f("uCubeColor", glm::vec3(0.2f, 0.2f, 0.6f), true);
	
	Texture* cubeTexture = ResourceManager::getInstance()->addTexture(workingDirectory + "\\assets\\textures\\dvdLogo.png", true, "cubeTexture");

	DrawData* lightDrawData = ResourceManager::getInstance()->addDrawData("lightDrawData", lightMesh, lightShader, cubeMaterial, light, nullptr);
	DrawData* cubeDrawData = ResourceManager::getInstance()->addDrawData("cubeDrawData", cubeMesh, cubeShader, cubeMaterial, light, nullptr);

	DrawData* groundDrawData = ResourceManager::getInstance()->addDrawData("groundDrawData", groundMesh, groundShader, groundMaterial, light, nullptr);

	GameObjectManager::getInstance()->addGameObject("lightGameObject", "light", lightDrawData, 2.5f, 2.5f, 2.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, false);
	
	for (float i = 0.0f; i < 360.0f; i += 0.1f) {
		GameObject* cube = GameObjectManager::getInstance()->addGameObject("cubeGameObject", "cube", cubeDrawData, glm::cos(i), (int)i % 360, glm::sin(i), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, false);
	}
	
	GameObjectManager::getInstance()->addGameObject("groundGameObject", "ground", groundDrawData, 0.0f, -1.5f, 0.0f, 1.0f, 1.0f, 1.0f, 200.0f, 1.0f, 200.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, false);

}
void Game::start() {
	initVariables();
	initResources();
}
void Game::processInput(float dt) {
	if (this->keys[GLFW_KEY_W]) {
		this->camera->processKeyboard(FORWARD, dt);
	}
	if (this->keys[GLFW_KEY_A]) {
		this->camera->processKeyboard(LEFT, dt);
	}
	if (this->keys[GLFW_KEY_S]) {
		this->camera->processKeyboard(BACKWARD, dt);
	}
	if (this->keys[GLFW_KEY_D]) {
		this->camera->processKeyboard(RIGHT, dt);
	}
}
void Game::update(float dt) {
	Renderer::getInstance()->colorBackground(glm::vec4(0.1f, 0.1f, 0.1f, 1.0f));
	std::vector<GameObject*>* gameObjects = GameObjectManager::getInstance()->getGameObjectsByTag("cube");
	float t = 0.0f;
	for (int i = 0; i < gameObjects->size(); i++) {
		gameObjects->at(i)->getDrawData()->getShader()->setVector3f("uCubeColor", glm::vec3(glm::sin(t), 0.0f, glm::sin(t)), true);
		Renderer::getInstance()->draw(*gameObjects->at(i), *this->camera, true);
		t += 0.1f;
	}
}
void Game::clear() {
	delete[] this->keys;
	delete this->soundEngine;
}