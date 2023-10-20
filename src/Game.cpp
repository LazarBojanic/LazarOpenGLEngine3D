#include "Game.hpp"

Game* Game::instance;

Game::Game(GLFWwindow* window, unsigned int width, unsigned int height) {
	this->workingDirectory = std::filesystem::current_path().generic_string();
	this->window = window;
	this->width = width;
	this->height = height;
	this->keys = new bool[1024];
	initKeys();
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
	Quad* quad = new Quad(true);
	Cube* cube = new Cube(true);

	Mesh* lightMesh = ResourceManager::getInstance()->addMesh(cube, nullptr, "lightMesh", 0, 3, 1, 3, 2, 2, 3, 3);
	Mesh* cubeMesh = ResourceManager::getInstance()->addMesh(cube, nullptr, "cubeMesh", 0, 3, 1, 3, 2, 2, 3, 3);
	Mesh* waterMesh = ResourceManager::getInstance()->addMesh(quad, nullptr, "waterMesh", 0, 3, 1, 3, 2, 2, 3, 3);

	Shader* lightShader = ResourceManager::getInstance()->addShader(workingDirectory + "\\assets\\shaders\\lightVertexShader.glsl", workingDirectory + "\\assets\\shaders\\lightFragmentShader.glsl", "lightShader");
	Shader* cubeShader = ResourceManager::getInstance()->addShader(workingDirectory + "\\assets\\shaders\\cubeLightingVertexShader.glsl", workingDirectory + "\\assets\\shaders\\cubeLightingFragmentShader.glsl", "cubeShader");
	Shader* groundShader = ResourceManager::getInstance()->addShader(workingDirectory + "\\assets\\shaders\\cubeLightingVertexShader.glsl", workingDirectory + "\\assets\\shaders\\cubeLightingFragmentShader.glsl", "groundShader");
	Shader* boxShader = ResourceManager::getInstance()->addShader(workingDirectory + "\\assets\\shaders\\cubeLightingVertexShader.glsl", workingDirectory + "\\assets\\shaders\\cubeLightingTexturedFragmentShader.glsl", "boxShader");
	Shader* waterShader = ResourceManager::getInstance()->addShader(workingDirectory + "\\assets\\shaders\\quadVertexShader.glsl", workingDirectory + "\\assets\\shaders\\quadFragmentShader.glsl", "waterShader");

	Material* waterMaterial = ResourceManager::getInstance()->addMaterial("waterMaterial", glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), 32);
	Material* cubeMaterial = ResourceManager::getInstance()->addMaterial("cubeMaterial", glm::vec3(0.2f, 0.2f, 0.2f), glm::vec3(0.8f, 0.8f, 0.8f), glm::vec3(0.8f, 0.8f, 0.8f), 32);

	Light* light = ResourceManager::getInstance()->addLight("light", glm::vec3(40.0f, 40.0f, 40.0f), glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.5f, 0.5f, 0.5f));

	lightShader->setVector3f("uLightColor", glm::vec3(1.0f, 1.0f, 1.0f), true);
	lightShader->setVector3f("uLightPos", light->position, true);

	cubeShader->setVector3f("uCubeColor", glm::vec3(1.0f, 0.5f, 0.31f), true);
	groundShader->setVector3f("uCubeColor", glm::vec3(0.2f, 0.2f, 0.6f), true);
	
	Texture* waterNormal = ResourceManager::getInstance()->addTexture(workingDirectory + "\\assets\\textures\\waterNormal.png", "waterNormal", "normal");

	Texture* boxDiffuse = ResourceManager::getInstance()->addTexture(workingDirectory + "\\assets\\textures\\boxDiffuse.png", "boxDiffuse", "diffuse");
	Texture* boxSpecular = ResourceManager::getInstance()->addTexture(workingDirectory + "\\assets\\textures\\boxSpecular.png", "boxSpecular", "specular");

	std::vector<Texture*>* boxTextureList = new std::vector<Texture*>();
	boxTextureList->push_back(boxDiffuse);
	boxTextureList->push_back(boxSpecular);

	std::vector<Texture*>* waterTextureList = new std::vector<Texture*>();
	waterTextureList->push_back(waterNormal);
	
	DrawData* lightDrawData = ResourceManager::getInstance()->addDrawData("lightDrawData", lightMesh, lightShader, cubeMaterial, light, nullptr);
	DrawData* cubeDrawData = ResourceManager::getInstance()->addDrawData("cubeDrawData", cubeMesh, cubeShader, cubeMaterial, light, nullptr);
	DrawData* boxDrawData = ResourceManager::getInstance()->addDrawData("boxDrawData", cubeMesh, boxShader, cubeMaterial, light, boxTextureList);
	DrawData* waterDrawData = ResourceManager::getInstance()->addDrawData("waterDrawData", waterMesh, waterShader, waterMaterial, light, nullptr);


	GameObjectManager::getInstance()->addGameObject("lightGameObject", "light", *lightDrawData, 2.5f, 35.0f, 2.5f, 1.0f, 1.0f, 1.0f, 10.0f, 10.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, false);
	GameObjectManager::getInstance()->addGameObject("boxGameObject", "box", *boxDrawData, -10.0f, 0.0f, -10.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, false);
	GameObjectManager::getInstance()->addGameObject("waterGameObject", "water", *waterDrawData, 0.0f, -15.0f, 0.0f, 1.0f, 1.0f, 1.0f, 100.0f, 100.0f, 1.0f, 90.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, false);


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
	GameObjectManager::getInstance()->addGameObject("backpackGameObject", "backpack", *backpackDrawData, -5.0f, 2.5f, -5.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, false);

	SkyboxPrimitive* skyboxPrimitive = new SkyboxPrimitive(false);
	Mesh* skyboxMesh = ResourceManager::getInstance()->addSkyboxMesh(skyboxPrimitive, "skyboxMesh", 0, 3);
	Shader* skyboxShader = ResourceManager::getInstance()->addShader(workingDirectory + "\\assets\\shaders\\skyboxVertexShader.glsl", workingDirectory + "\\assets\\shaders\\skyboxFragmentShader.glsl", "skyboxShader");
	std::vector<std::string>* skyboxFacePaths = new std::vector<std::string>();
	skyboxFacePaths->push_back(workingDirectory + "\\assets\\textures\\skybox\\right.jpg");
	skyboxFacePaths->push_back(workingDirectory + "\\assets\\textures\\skybox\\left.jpg");
	skyboxFacePaths->push_back(workingDirectory + "\\assets\\textures\\skybox\\top.jpg");
	skyboxFacePaths->push_back(workingDirectory + "\\assets\\textures\\skybox\\bottom.jpg");
	skyboxFacePaths->push_back(workingDirectory + "\\assets\\textures\\skybox\\front.jpg");
	skyboxFacePaths->push_back(workingDirectory + "\\assets\\textures\\skybox\\back.jpg");
	CubeMap* skyboxCubeMap = ResourceManager::getInstance()->addCubeMap(skyboxFacePaths, "skyboxCubeMap");
	Skybox* skybox = ResourceManager::getInstance()->addSkybox(skyboxMesh, skyboxShader, skyboxCubeMap, "skybox");


	const int lengthX = 75, lengthZ = 75;
	float noiseSize = lengthX * lengthZ;
	float cubeSizeX = 0.5f;
	float cubeSizeY = 10.0f;
	float cubeSizeZ = 0.5f;
	float height = 0.0f;
	float heightMultiplier = 25.0f;
	float posX = 0.0f, posZ = 0.0f;
	auto node = FastNoise::New<FastNoise::FractalFBm>();

	node->SetSource(FastNoise::New<FastNoise::Simplex>());
	node->SetGain(FastNoise::New<FastNoise::Value>());

	float* noise = new float[noiseSize];

	node->GenUniformGrid2D(noise, 0, 0, lengthX, lengthZ, 0.02f, 1337);

	for (int i = 0; i < noiseSize; i++) {
		glm::vec3 color = Util::colorIntToVec3(Util::interpolate(0x633310, 0x06c238, noise[i]));
		Shader* tempShader = ResourceManager::getInstance()->addShader(workingDirectory + "\\assets\\shaders\\cubeLightingVertexShader.glsl", workingDirectory + "\\assets\\shaders\\cubeLightingFragmentShader.glsl" , "cubeNoiseShader");
		cubeDrawData->setShader(*tempShader);
		cubeDrawData->getShader()->setVector3f("uCubeColor", color, true);
		height = noise[i];
		height += 1.0;
		height /= 2.0;
		height *= heightMultiplier;
		GameObjectManager::getInstance()->addGameObject("blockGameObject", "block", *cubeDrawData, posX, height, posZ, 1.0f, 1.0f, 1.0f, cubeSizeX, cubeSizeY, cubeSizeZ, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, false);
		posX += cubeSizeX;
		if (i % lengthZ == 0) {
			posX = 0.0f;
			posZ += cubeSizeZ;
		}
	}
	delete[] noise;
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
	if (this->keys[GLFW_KEY_F]) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
	else {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
}
void Game::update(float dt) {
	float r = 50.0f;
	float lightX = r * glm::cos(t);
	float lightZ = r * glm::sin(t);
	GameObject* lightGameObject = GameObjectManager::getInstance()->getGameObjectByTag("light");
	float oldLightY = lightGameObject->getDrawData()->getLight()->position.y;
;	glm::vec3 newLightPos = glm::vec3(lightX, oldLightY, lightZ);
	std::vector<GameObject*>* gameObjectList = GameObjectManager::getInstance()->getGameObjectList();
	for (int i = 0; i < gameObjectList->size(); i++) {
		gameObjectList->at(i)->getDrawData()->getLight()->position = newLightPos;
	}
	lightGameObject->setPositionX(lightX);
	lightGameObject->setPositionZ(lightZ);
	this->t += dt;
}
void Game::render(float dt) {
	Renderer::getInstance()->colorBackground(glm::vec4(0.1f, 0.1f, 0.1f, 1.0f));
	
	Renderer::getInstance()->drawAll(*this->camera, true);
	Renderer::getInstance()->drawSkybox(*this->camera, "skybox");
}
void Game::clear() {
	delete[] this->keys;
	delete this->soundEngine;
}