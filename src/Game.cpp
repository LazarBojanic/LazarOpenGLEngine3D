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
	delete[] this->keys;
	delete this->soundEngine;
	delete this->lightColor;
	delete this->objectColor;
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
	this->lightPos = new glm::vec3(1.2f, 0.0f, 2.0f);
	this->cubePos = new glm::vec3(0.0f, 0.0f, 0.0f);
	this->lightColor = new glm::vec3(1.0f, 1.0f, 1.0f);
	this->objectColor = new glm::vec3(1.0f, 0.5f, 0.31f);

}
void Game::initResources() {
	this->camera = new Camera(glm::vec3(0.0f, 0.0f, 3.0f));
	
	Cube* lightCube = new Cube();
	Cube* cubeCube = new Cube();

	Mesh* lightMesh = ResourceManager::getInstance()->addMesh(*lightCube, "lightMesh", 0, 3, 1, 3, 2, 2, 3, 3);
	Mesh* cubeMesh = ResourceManager::getInstance()->addMesh(*cubeCube, "cubeMesh", 0, 3, 1, 3, 2, 2, 3, 3);
	
	Shader* lightShader = ResourceManager::getInstance()->addShader(workingDirectory + "\\assets\\shaders\\lightVertexShader.glsl", workingDirectory + "\\assets\\shaders\\lightFragmentShader.glsl", "lightShader");
	Shader* cubeShader = ResourceManager::getInstance()->addShader(workingDirectory + "\\assets\\shaders\\cubeVertexShader.glsl", workingDirectory + "\\assets\\shaders\\cubeFragmentShader.glsl", "cubeShader");

	glm::mat4 view = this->camera->getViewMatrix();
	glm::mat4 projection = glm::perspective(glm::radians(this->camera->getZoom()), (float)this->width / (float)this->height, 0.1f, 100.0f);
	
	lightShader->setVector3f("uLightColor", *this->lightColor, true);

	cubeShader->setVector3f("uLightPos", *this->lightPos, true);
	cubeShader->setVector3f("uLightColor", *this->lightColor, true);
	cubeShader->setVector3f("uObjectColor", *this->objectColor, true);
	
	Texture2D* cubeTexture = ResourceManager::getInstance()->addTexture2D(workingDirectory + "\\assets\\textures\\dvdLogo.png", true, "cubeTexture");

	ResourceManager::getInstance()->addDrawData("lightDrawData", *lightMesh, *lightShader, *cubeTexture);
	ResourceManager::getInstance()->addDrawData("cubeDrawData", *cubeMesh, *cubeShader, *cubeTexture);

	GameObjectManager::getInstance()->addGameObject3D("lightGameObject", "light", *lightMesh, *lightShader, *cubeTexture, this->lightPos->x, this->lightPos->y, this->lightPos->z, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, false);
	GameObjectManager::getInstance()->addGameObject3D("cubeGameObject", "cube", *cubeMesh, *cubeShader, *cubeTexture, this->cubePos->x, this->cubePos->y, this->cubePos->z, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, false);

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
	
	GameObject3D* light = GameObjectManager::getInstance()->getGameObject3DByTag("light");
	Renderer::getInstance()->draw3DUntextured(*light, *this->camera, this->width, this->height, true);
	GameObject3D* cube = GameObjectManager::getInstance()->getGameObject3DByTag("cube");
	cube->setPositionZ(cube->getPositionZ() + glm::sin(glfwGetTime()) * dt);
	Renderer::getInstance()->draw3DUntextured(*cube, *this->camera, this->width, this->height, true);
}
void Game::clear() {
	delete[] this->keys;
	delete this->soundEngine;
	delete this->lightColor;
	delete this->objectColor;
}