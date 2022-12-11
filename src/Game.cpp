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
	this->camera = new Camera(glm::vec3(0.0f, 0.0f, 3.0f));
	OtherCube* cube = new OtherCube();

	Mesh* lightMesh = ResourceManager::getInstance()->addMesh(*cube, "lightMesh", 0, 3, 1, 3, 2, 2, 3, 3, false);
	Mesh* cubeMesh = ResourceManager::getInstance()->addMesh(*cube, "cubeMesh", 0, 3, 1, 3, 2, 2, 3, 3, false);
	Mesh* groundMesh = ResourceManager::getInstance()->addMesh(*cube, "groundMesh", 0, 3, 1, 3, 2, 2, 3, 3, false);

	Shader* lightShader = ResourceManager::getInstance()->addShader(workingDirectory + "\\assets\\shaders\\lightVertexShader.glsl", workingDirectory + "\\assets\\shaders\\lightFragmentShader.glsl", "lightShader");
	Shader* cubeShader = ResourceManager::getInstance()->addShader(workingDirectory + "\\assets\\shaders\\cubeLightingVertexShader.glsl", workingDirectory + "\\assets\\shaders\\cubeLightingFragmentShader.glsl", "cubeShader");
	Shader* groundShader = ResourceManager::getInstance()->addShader(workingDirectory + "\\assets\\shaders\\cubeLightingVertexShader.glsl", workingDirectory + "\\assets\\shaders\\cubeLightingFragmentShader.glsl", "groundShader");

	Material* cubeMaterial = ResourceManager::getInstance()->addMaterial("cubeMaterial", glm::vec3(0.6f, 0.6f, 0.6f), glm::vec3(0.6f, 0.6f, 0.6f), glm::vec3(0.5f, 0.5f, 0.5f), 32);
	Material* groundMaterial = ResourceManager::getInstance()->addMaterial("groundMaterial", glm::vec3(0.2f, 0.2f, 0.2f), glm::vec3(0.6f, 0.6f, 0.6f), glm::vec3(0.5f, 0.5f, 0.5f), 32);

	Light* light = ResourceManager::getInstance()->addLight("light", glm::vec3(2.5f, 2.5f, 2.5f), glm::vec3(0.2f, 0.2f, 0.2f), glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(1.0f, 1.0f, 1.0f));

	glm::mat4 view = this->camera->getViewMatrix();
	glm::mat4 projection = glm::perspective(glm::radians(this->camera->getZoom()), (float)this->width / (float)this->height, 0.1f, 100.0f);
	
	lightShader->setVector3f("uLightColor", glm::vec3(1.0f, 1.0f, 1.0f), true);

	cubeShader->setVector3f("uViewPos", this->camera->getPosition(), true);

	cubeShader->setVector3f("uCubeColor", glm::vec3(1.0f, 0.5f, 0.31f), true);

	groundShader->setVector3f("uViewPos", this->camera->getPosition(), true);

	groundShader->setVector3f("uCubeColor", glm::vec3(0.2f, 0.2f, 0.6f), true);
	
	Texture2D* cubeTexture = ResourceManager::getInstance()->addTexture2D(workingDirectory + "\\assets\\textures\\dvdLogo.png", true, "cubeTexture");

	ResourceManager::getInstance()->addDrawData("lightDrawData", *lightMesh, *lightShader, *cubeMaterial, *light, *cubeTexture);
	ResourceManager::getInstance()->addDrawData("cubeDrawData", *cubeMesh, *cubeShader, *cubeMaterial, *light, *cubeTexture);
	ResourceManager::getInstance()->addDrawData("groundDrawData", *groundMesh, *groundShader, *groundMaterial, *light, *cubeTexture);

	GameObjectManager::getInstance()->addGameObject("lightGameObject", "light", *lightMesh, *lightShader, *cubeMaterial, *light, *cubeTexture, 2.5f, 2.5f, 2.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, false);
	GameObjectManager::getInstance()->addGameObject("cubeGameObject", "cube", *cubeMesh, *cubeShader, *cubeMaterial, *light, *cubeTexture, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, false);
	GameObjectManager::getInstance()->addGameObject("groundGameObject", "ground", *groundMesh, *groundShader, *groundMaterial, *light, *cubeTexture, 0.0f, -1.5f, 0.0f, 1.0f, 1.0f, 1.0f, 200.0f, 1.0f, 200.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, false);

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
	if (this->keys[GLFW_KEY_R]) {
		//glfwSetCursorPos(this->window, this->width / 2, this->height / 2);
	}
}
void Game::update(float dt) {
	Renderer::getInstance()->colorBackground(glm::vec4(0.1f, 0.1f, 0.1f, 1.0f));
	
	GameObject* light = GameObjectManager::getInstance()->getGameObjectByTag("light");
	Renderer::getInstance()->draw(*light, *this->camera, this->width, this->height, true, false, false);

	GameObject* cube = GameObjectManager::getInstance()->getGameObjectByTag("cube");
	cube->getDrawData()->getShader()->setVector3f("uViewPos", this->camera->getPosition(), true);
	cube->updateDrawData();

	Renderer::getInstance()->draw(*cube, *this->camera, this->width, this->height, true, false, false);

	GameObject* ground = GameObjectManager::getInstance()->getGameObjectByTag("ground");
	ground->getDrawData()->getShader()->setVector3f("uViewPos", this->camera->getPosition(), true);
	ground->updateDrawData();

	Renderer::getInstance()->draw(*ground, *this->camera, this->width, this->height, true, false, false);
}
void Game::clear() {
	delete[] this->keys;
	delete this->soundEngine;
}