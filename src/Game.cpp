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
	glfwSetWindowTitle(this->window, "DVD Game");
	float lastX = this->width / 2.0f;
	float lastY = this->height / 2.0f;
	bool firstMouse = true;
}
void Game::initResources() {
	this->camera = new Camera(glm::vec3(0.0f, 0.0f, 3.0f));
	
	Cube* cube = new Cube();

	Mesh* cubeMesh = ResourceManager::getInstance()->addMesh(*cube, "cubeMesh", 0, 3, 1, 3, 2, 2);
	
	Shader* cubeShader = ResourceManager::getInstance()->addShader(workingDirectory + "\\assets\\shaders\\cubeVertexShader.glsl", workingDirectory + "\\assets\\shaders\\cubeFragmentShader.glsl", "cubeShader");

	glm::mat4 view = this->camera->getViewMatrix();
	glm::mat4 projection = glm::perspective(glm::radians(this->camera->getZoom()), (float)this->width / (float)this->height, 0.1f, 100.0f);
	
	cubeShader->setMatrix4f("uView", view, true);
	cubeShader->setMatrix4f("uProjection", projection, true);
	
	Texture2D* cubeTexture = ResourceManager::getInstance()->addTexture2D(workingDirectory + "\\assets\\textures\\dvdLogo.png", true, "cubeTexture");

	ResourceManager::getInstance()->addDrawData("cubeDrawData", *cubeMesh, *cubeShader, *cubeTexture);

	
	glm::vec3 cubePositions[10] = {
		glm::vec3(0.0f,  0.0f,  0.0f),
		glm::vec3(2.0f,  5.0f, -15.0f),
		glm::vec3(-1.5f, -2.2f, -2.5f),
		glm::vec3(-3.8f, -2.0f, -12.3f),
		glm::vec3(2.4f, -0.4f, -3.5f),
		glm::vec3(-1.7f,  3.0f, -7.5f),
		glm::vec3(1.3f, -2.0f, -2.5f),
		glm::vec3(1.5f,  2.0f, -2.5f),
		glm::vec3(1.5f,  0.2f, -1.5f),
		glm::vec3(-1.3f,  1.0f, -1.5f)
	};

	for (int i = 0; i < 10; i++) {
		GameObjectManager::getInstance()->addGameObject3D("cubeGameObject", "cube", *cubeMesh, *cubeShader, *cubeTexture, cubePositions[i].x, cubePositions[i].z, cubePositions[i].z, 1.0f, 1.0f, 1.0f, 1.0f, 45.0f, 45.0f, 45.0f, 0.0f, 0.0f, 0.0f, false);
	}
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


	/*GameObject3D* cubeGameObject = GameObjectManager::getInstance()->getGameObject3DByName("cubeGameObject");
	cubeGameObject->setRotationX(cubeGameObject->getRotationX() + glm::sin(glfwGetTime()));
	cubeGameObject->setRotationY(cubeGameObject->getRotationY() + glm::sin(glfwGetTime()));
	cubeGameObject->setRotationZ(cubeGameObject->getRotationZ() + glm::sin(glfwGetTime()));*/
	
	std::vector<GameObject3D*>* cubes = GameObjectManager::getInstance()->getGameObjects3DByTag("cube");

	for (int i = 0; i < cubes->size(); i++) {
		Renderer::getInstance()->draw3DUntextured(*cubes->at(i), *this->camera, this->width, this->height, true);
	}
	delete cubes;
}
void Game::clear() {
	delete[] this->keys;
	delete this->soundEngine;
}