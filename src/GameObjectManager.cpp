#include "GameObjectManager.hpp"

GameObjectManager* GameObjectManager::instance;

GameObjectManager::GameObjectManager() {
    this->gameObjectList = new std::vector<GameObject*>();
}

GameObjectManager::~GameObjectManager() {
    delete this->gameObjectList;
}

GameObjectManager* GameObjectManager::getInstance() {
    if (!instance) {
        instance = new GameObjectManager();
    }
    return instance;
}

GameObject* GameObjectManager::addGameObject(GameObject* gameObject) {
    this->gameObjectList->push_back(gameObject);
    return gameObject;
}

GameObject* GameObjectManager::addGameObject(std::string name, std::string tag, DrawData* drawData, float positionX, float positionY, float positionZ, float sizeX, float sizeY, float sizeZ, float scaleX, float scaleY, float scaleZ, float rotationX, float rotationY, float rotationZ, float speedX, float speedY, float speedZ, bool isHit) {
    DrawData* gameObjectDrawData = new DrawData(*drawData);
    GameObject* gameObject = new GameObject(name, tag, gameObjectDrawData, positionX, positionY, positionZ, sizeX, sizeY, sizeZ, scaleX, scaleY, scaleZ, rotationX, rotationY, rotationZ, speedX, speedY, speedZ, isHit);
    this->gameObjectList->push_back(gameObject);
    return gameObject;
}

GameObject* GameObjectManager::addGameObject(std::string name, std::string tag, Mesh* mesh, Shader* shader, Material* material, Light* light, Texture* texture, float positionX, float positionY, float positionZ, float sizeX, float sizeY, float sizeZ, float scaleX, float scaleY, float scaleZ, float rotationX, float rotationY, float rotationZ, float speedX, float speedY, float speedZ, bool isHit) {
    DrawData* drawData = new DrawData(name + "DrawData", mesh, shader, material, light, texture);
    GameObject* gameObject = new GameObject(name, tag, drawData, positionX, positionY, positionZ, sizeX, sizeY, sizeZ, scaleX, scaleY, scaleZ, rotationX, rotationY, rotationZ, speedX, speedY, speedZ, isHit);
    this->gameObjectList->push_back(gameObject);
    return gameObject;
}

GameObject* GameObjectManager::getGameObjectByName(std::string name) {
    for (int i = 0; i < this->gameObjectList->size(); i++) {
        if (this->gameObjectList->at(i)->getName() == name) {
            return this->gameObjectList->at(i);
        }
    }
    return nullptr;
}
GameObject* GameObjectManager::getGameObjectByTag(std::string tag) {
    for (int i = 0; i < this->gameObjectList->size(); i++) {
        if (this->gameObjectList->at(i)->getTag() == (tag)) {
            return this->gameObjectList->at(i);
        }
    }
    return nullptr;
}
std::vector<GameObject*>* GameObjectManager::getGameObjectsByTag(std::string tag) {
    std::vector<GameObject*>* result = new std::vector<GameObject*>();
    for (int i = 0; i < this->gameObjectList->size(); i++) {
        if (this->gameObjectList->at(i)->getTag() == tag) {
            result->push_back(this->gameObjectList->at(i));
        }
    }
    return result;
}
void GameObjectManager::removeGameObject(GameObject* gameObject) {
    std::vector<GameObject*>* tempGameObjectList = new std::vector<GameObject*>();
    for (int i = 0; i < this->gameObjectList->size(); i++) {
        if (this->gameObjectList->at(i)->getId() != gameObject->getId()) {
            tempGameObjectList->push_back(this->gameObjectList->at(i));
        }
    }
    delete this->gameObjectList;
    this->gameObjectList = tempGameObjectList;
}
void GameObjectManager::clear(bool reinitialize) {
    delete this->gameObjectList;
    if (reinitialize) {
        this->gameObjectList = new std::vector<GameObject*>();
    }
}