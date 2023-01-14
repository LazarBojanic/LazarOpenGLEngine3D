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
	this->t = 0.0f;
}
void Game::initResources() {
	this->camera = new Camera(glm::vec3(0.0f, 0.0f, 3.0f), this->width, this->height, 0.1f, 100.0f);
	Cube* cube = new Cube(false);

	Mesh* lightMesh = ResourceManager::getInstance()->addMesh(cube, nullptr, "lightMesh", 0, 3, 1, 3, 2, 2, 3, 3);
	Mesh* cubeMesh = ResourceManager::getInstance()->addMesh(cube, nullptr, "cubeMesh", 0, 3, 1, 3, 2, 2, 3, 3);
	Mesh* groundMesh = ResourceManager::getInstance()->addMesh(cube, nullptr, "groundMesh", 0, 3, 1, 3, 2, 2, 3, 3);

	Shader* lightShader = ResourceManager::getInstance()->addShader(workingDirectory + "\\assets\\shaders\\lightVertexShader.glsl", workingDirectory + "\\assets\\shaders\\lightFragmentShader.glsl", "lightShader");
	Shader* cubeShader = ResourceManager::getInstance()->addShader(workingDirectory + "\\assets\\shaders\\cubeLightingVertexShader.glsl", workingDirectory + "\\assets\\shaders\\cubeLightingTexturedFragmentShader.glsl", "cubeShader");
	Shader* groundShader = ResourceManager::getInstance()->addShader(workingDirectory + "\\assets\\shaders\\cubeLightingVertexShader.glsl", workingDirectory + "\\assets\\shaders\\cubeLightingFragmentShader.glsl", "groundShader");

	Material* cubeMaterial = ResourceManager::getInstance()->addMaterial("cubeMaterial", glm::vec3(0.1f, 0.1f, 0.1f), glm::vec3(0.2f, 0.2f, 0.2f), glm::vec3(0.2f, 0.2f, 0.2f), 16);
	Material* groundMaterial = ResourceManager::getInstance()->addMaterial("groundMaterial", glm::vec3(0.2f, 0.2f, 0.2f), glm::vec3(0.6f, 0.6f, 0.6f), glm::vec3(0.5f, 0.5f, 0.5f), 32);

	Light* light = ResourceManager::getInstance()->addLight("light", glm::vec3(2.5f, 2.5f, 2.5f), glm::vec3(0.2f, 0.2f, 0.2f), glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(1.0f, 1.0f, 1.0f));

	lightShader->setVector3f("uLightColor", glm::vec3(1.0f, 1.0f, 1.0f), true);
	lightShader->setVector3f("uLightPos", light->position, true);

	cubeShader->setVector3f("uCubeColor", glm::vec3(1.0f, 0.5f, 0.31f), true);
	groundShader->setVector3f("uCubeColor", glm::vec3(0.2f, 0.2f, 0.6f), true);
	
	Texture* cubeDiffuse = ResourceManager::getInstance()->addTexture(workingDirectory + "\\assets\\textures\\cubeDiffuse.png", "cubeDiffuse", "diffuse");
	Texture* cubeSpecular = ResourceManager::getInstance()->addTexture(workingDirectory + "\\assets\\textures\\cubeSpecular.png", "cubeSpecular", "specular");

	std::vector<Texture*>* cubeTextureList = new std::vector<Texture*>();
	cubeTextureList->push_back(cubeDiffuse);
	cubeTextureList->push_back(cubeSpecular);
	
	DrawData* lightDrawData = ResourceManager::getInstance()->addDrawData("lightDrawData", lightMesh, lightShader, cubeMaterial, light, nullptr);
	DrawData* cubeDrawData = ResourceManager::getInstance()->addDrawData("cubeDrawData", cubeMesh, cubeShader, cubeMaterial, light, cubeTextureList);
	DrawData* groundDrawData = ResourceManager::getInstance()->addDrawData("groundDrawData", groundMesh, groundShader, groundMaterial, light, nullptr);


	GameObjectManager::getInstance()->addGameObject("lightGameObject", "light", lightDrawData, 2.5f, 2.5f, 2.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, false);
	GameObjectManager::getInstance()->addGameObject("cubeGameObject", "cube", cubeDrawData, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, false);
	GameObjectManager::getInstance()->addGameObject("groundGameObject", "ground", groundDrawData, 0.0f, -1.5f, 0.0f, 1.0f, 1.0f, 1.0f, 200.0f, 1.0f, 200.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, false);

	Model* backpackModel = ResourceManager::getInstance()->addModel(workingDirectory + "\\assets\\models\\backpack\\backpack.obj", "backpackModel");
	Mesh* backpackMesh = ResourceManager::getInstance()->addMesh(nullptr, backpackModel, "backpackMesh", 0, 3, 1, 3, 2, 2, 3, 3);
	Shader* backpackShader = ResourceManager::getInstance()->addShader(workingDirectory + "\\assets\\shaders\\betterBackpackVertexShader.glsl", workingDirectory + "\\assets\\shaders\\betterBackpackFragmentShader.glsl", "betterBackpackShader");
	Texture* backpackAo = ResourceManager::getInstance()->addTexture(workingDirectory + "\\assets\\models\\backpack\\backpackAo.jpg", "backpackAo", "ao");
	Texture* backpackDiffuse = ResourceManager::getInstance()->addTexture(workingDirectory + "\\assets\\models\\backpack\\backpackDiffuse.jpg", "backpackDiffuse", "diffuse");
	Texture* backpackNormal = ResourceManager::getInstance()->addTexture(workingDirectory + "\\assets\\models\\backpack\\backpackNormal.png", "backpackNormal", "normal");
	Texture* backpackRoughness = ResourceManager::getInstance()->addTexture(workingDirectory + "\\assets\\models\\backpack\\backpackRoughness.jpg", "backpackRoughness", "roughness");
	Texture* backpackSpecular = ResourceManager::getInstance()->addTexture(workingDirectory + "\\assets\\models\\backpack\\backpackSpecular.jpg", "backpackSpecular", "specular");
	std::vector<Texture*>* backpackTextureList = new std::vector<Texture*>();
	backpackTextureList->push_back(backpackAo);
	backpackTextureList->push_back(backpackDiffuse);
	backpackTextureList->push_back(backpackNormal);
	backpackTextureList->push_back(backpackRoughness);
	backpackTextureList->push_back(backpackSpecular);

	DrawData* backpackDrawData = ResourceManager::getInstance()->addDrawData("backpackDrawData", backpackMesh, backpackShader, cubeMaterial, light, backpackTextureList);
	GameObjectManager::getInstance()->addGameObject("backpackGameObject", "backpack", backpackDrawData, 5.0f, 2.5f, 5.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, false);


	/*Model* ironManModel = ResourceManager::getInstance()->addModel(workingDirectory + "\\assets\\models\\ironMan\\ironMan.obj", "ironManModel");
	Mesh* ironManMesh = ResourceManager::getInstance()->addMesh(nullptr, ironManModel, "ironManMesh", 0, 3, 1, 3, 2, 2, 3, 3);
	Shader* ironManShader = ResourceManager::getInstance()->addShader(workingDirectory + "\\assets\\shaders\\ironManVertexShader.glsl", workingDirectory + "\\assets\\shaders\\ironManFragmentShader.glsl", "ironManShader");
	DrawData* ironManDrawData = ResourceManager::getInstance()->addDrawData("ironManDrawData", ironManMesh, ironManShader, cubeMaterial, light, nullptr);
	GameObjectManager::getInstance()->addGameObject("ironManGameObject", "ironMan", ironManDrawData, -10.0f, 5.0f, -10.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, false);*/


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
	GameObject* backpackGameObject = GameObjectManager::getInstance()->getGameObjectByTag("backpack");
	backpackGameObject->setRotationX(backpackGameObject->getRotationX() + 10.0f);
}
void Game::render(float dt) {
	Renderer::getInstance()->colorBackground(glm::vec4(0.1f, 0.1f, 0.1f, 1.0f));
	Renderer::getInstance()->drawAll(*this->camera, true);
}
void Game::clear() {
	delete[] this->keys;
	delete this->soundEngine;
}