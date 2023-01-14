#include "ResourceManager.hpp"

ResourceManager* ResourceManager::instance;

ResourceManager::ResourceManager() {
    this->modelList = new std::vector<Model*>();
    this->meshList = new std::vector<Mesh*>();
    this->shaderList = new std::vector<Shader*>();
    this->materialList = new std::vector<Material*>();
    this->lightList = new std::vector<Light*>();
    this->textureList = new std::vector<Texture*>();
    this->drawDataList = new std::vector<DrawData*>();
    this->cubeMapList = new std::vector<CubeMap*>();
    this->skyboxList = new std::vector<Skybox*>();
}
ResourceManager::~ResourceManager() {
    
}
ResourceManager* ResourceManager::getInstance() {
    if (!instance) {
        instance = new ResourceManager();
    }
    return instance;
}
Model* ResourceManager::addModel(std::string path, std::string name) {
    Model* model = new Model(name, path);
    if (std::find(this->modelList->begin(), this->modelList->end(), model) == this->modelList->end()) {
        this->modelList->push_back(model);
        return model;
    }
    return nullptr;
}
Mesh* ResourceManager::addMesh(Primitive* primitive, Model* model, std::string name, int positionAttributeNumber, int positionDimensions, int colorAttributeNumber, int colorDimensions, int textureAttributeNumber, int textureDimensions, unsigned int normalAttributeNumber, unsigned int normalDimensions){
    Mesh* mesh = new Mesh(primitive, model, name, positionAttributeNumber, positionDimensions, colorAttributeNumber, colorDimensions, textureAttributeNumber, textureDimensions, normalAttributeNumber, normalDimensions);
    if (std::find(this->meshList->begin(), this->meshList->end(), mesh) == this->meshList->end()) {
        this->meshList->push_back(mesh);
        return mesh;
    }
    return nullptr;
}
Mesh* ResourceManager::addSkyboxMesh(Primitive* primitive, std::string name, int positionAttributeNumber, int positionDimensions) {
    Mesh* mesh = new Mesh(primitive, name, positionAttributeNumber, positionDimensions);
    if (std::find(this->meshList->begin(), this->meshList->end(), mesh) == this->meshList->end()) {
        this->meshList->push_back(mesh);
        return mesh;
    }
    return nullptr;
}

Shader* ResourceManager::addShader(std::string vertexShaderPath, std::string fragmentShaderPath, std::string name){
    Shader* shader = new Shader(vertexShaderPath, fragmentShaderPath, name);
    if (std::find(this->shaderList->begin(), this->shaderList->end(), shader) == this->shaderList->end()) {
        this->shaderList->push_back(shader);
        return shader;
    }
    return nullptr;
}

Material* ResourceManager::addMaterial(std::string name, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float shininess) {
    Material* material = new Material(name, ambient, diffuse, specular, shininess);
    if (std::find(this->materialList->begin(), this->materialList->end(), material) == this->materialList->end()) {
        this->materialList->push_back(material);
        return material;
    }
    return nullptr;
}

Light* ResourceManager::addLight(std::string name, glm::vec3 position, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular) {
    Light* light = new Light(name, position, ambient, diffuse, specular);
    if (std::find(this->lightList->begin(), this->lightList->end(), light) == this->lightList->end()) {
        this->lightList->push_back(light);
        return light;
    }
    return nullptr;
}

Texture* ResourceManager::addTexture(std::string texturePath, std::string name, std::string type){
    Texture* texture = new Texture(texturePath, name, type);
    if (std::find(this->textureList->begin(), this->textureList->end(), texture) == this->textureList->end()) {
        this->textureList->push_back(texture);
        return texture;
    }
    return nullptr;
}

CubeMap* ResourceManager::addCubeMap(std::vector<std::string>* facePaths, std::string name) {
    CubeMap* cubeMap = new CubeMap(facePaths, name);
    if (std::find(this->cubeMapList->begin(), this->cubeMapList->end(), cubeMap) == this->cubeMapList->end()) {
        this->cubeMapList->push_back(cubeMap);
        return cubeMap;
    }
    return nullptr;
}

Skybox* ResourceManager::addSkybox(Mesh* mesh, Shader* shader, CubeMap* cubeMap, std::string name) {
    Skybox* skybox = new Skybox(mesh, shader, cubeMap, name);
    if (std::find(this->skyboxList->begin(), this->skyboxList->end(), skybox) == this->skyboxList->end()) {
        this->skyboxList->push_back(skybox);
        return skybox;
    }
    return nullptr;
}

DrawData* ResourceManager::addDrawData(std::string name, Mesh* mesh, Shader* shader, Material* material, Light* light, std::vector<Texture*>* textureList){
    DrawData* drawData = new DrawData(name, mesh, shader, material, light, textureList);
    if (std::find(this->drawDataList->begin(), this->drawDataList->end(), drawData) == this->drawDataList->end()) {
        this->drawDataList->push_back(drawData);
        return drawData;
    }
    return nullptr;
}

Model* ResourceManager::getModelByName(std::string name) {
    for (int i = 0; i < this->modelList->size(); i++) {
        if (this->modelList->at(i)->getName() == name) {
            return this->modelList->at(i);
        }
    }
    return nullptr;
}

Mesh* ResourceManager::getMeshByName(std::string name){
    for (int i = 0; i < this->meshList->size(); i++) {
        if (this->meshList->at(i)->getName() == name) {
            return this->meshList->at(i);
        }
    }
    return nullptr;
}

Shader* ResourceManager::getShaderByName(std::string name){
    for (int i = 0; i < this->shaderList->size(); i++) {
        if (this->shaderList->at(i)->getName() == name) {
            return this->shaderList->at(i);
        }
    }
    return nullptr;
}
Material* ResourceManager::getMaterialByName(std::string name) {
    for (int i = 0; i < this->materialList->size(); i++) {
        if (this->materialList->at(i)->name == name) {
            return this->materialList->at(i);
        }
    }
    return nullptr;
}
Light* ResourceManager::getLightByName(std::string name) {
    for (int i = 0; i < this->lightList->size(); i++) {
        if (this->lightList->at(i)->name == name) {
            return this->lightList->at(i);
        }
    }
    return nullptr;
}
Texture* ResourceManager::getTextureByName(std::string name) {
    for (int i = 0; i < this->textureList->size(); i++) {
        if (this->textureList->at(i)->getName() == name) {
            return this->textureList->at(i);
        }
    }
    return nullptr;
}
CubeMap* ResourceManager::getCubeMapByName(std::string name) {
    for (int i = 0; i < this->cubeMapList->size(); i++) {
        if (this->cubeMapList->at(i)->getName() == name) {
            return this->cubeMapList->at(i);
        }
    }
    return nullptr;
}
Skybox* ResourceManager::getSkyboxByName(std::string name) {
    for (int i = 0; i < this->skyboxList->size(); i++) {
        if (this->skyboxList->at(i)->getName() == name) {
            return this->skyboxList->at(i);
        }
    }
    return nullptr;
}
DrawData* ResourceManager::getDrawDataByName(std::string name){
    for (int i = 0; i < this->drawDataList->size(); i++) {
        if (this->drawDataList->at(i)->getName() == name) {
            return this->drawDataList->at(i);
        }
    }
    return nullptr;
}
void ResourceManager::clear(bool reinitialize) {
    delete this->meshList;
    delete this->shaderList;
    delete this->materialList;
    delete this->lightList;
    delete this->textureList;
    delete this->cubeMapList;
    delete this->skyboxList;
    delete this->drawDataList;
    if (reinitialize) {
        this->meshList = new std::vector<Mesh*>();
        this->shaderList = new std::vector<Shader*>();
        this->materialList = new std::vector<Material*>();
        this->lightList = new std::vector<Light*>();
        this->textureList = new std::vector<Texture*>();
        this->cubeMapList = new std::vector<CubeMap*>();
        this->skyboxList = new std::vector<Skybox*>();
        this->drawDataList = new std::vector<DrawData*>();
    }
}