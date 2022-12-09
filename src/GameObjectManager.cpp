#include "GameObjectManager.hpp"

GameObjectManager* GameObjectManager::instance;

GameObjectManager::GameObjectManager() {
    this->gameObjectList = new std::vector<GameObject*>();
    this->gameObject3DList = new std::vector<GameObject3D*>();
}

GameObjectManager::~GameObjectManager() {
    delete this->gameObjectList;
    delete this->gameObject3DList;
}

GameObjectManager* GameObjectManager::getInstance() {
    if (!instance) {
        instance = new GameObjectManager();
    }
    return instance;
}

GameObject* GameObjectManager::addGameObject(GameObject* gameObject){
    this->gameObjectList->push_back(gameObject);
    return gameObject;
}


GameObject* GameObjectManager::addGameObject(std::string name, std::string tag, DrawData& drawData, float positionX, float positionY, float sizeX, float sizeY, float scale, float rotation, float speedX, float speedY, bool isHit) {
    GameObject* gameObject = new GameObject(name, tag, drawData, positionX, positionY, sizeX, sizeY, scale, rotation, speedX, speedY, isHit);
    this->gameObjectList->push_back(gameObject);
    return gameObject;
}

GameObject* GameObjectManager::addGameObject(std::string name, std::string tag, Mesh& mesh, Shader& shader, Texture2D& texture2D,
    float positionX, float positionY, float sizeX, float sizeY, float scale, float rotation, float speedX, float speedY, bool isHit){
    DrawData* drawData = new DrawData(name + "DrawData", mesh, shader, texture2D);
    GameObject* gameObject = new GameObject(name, tag, *drawData, positionX, positionY, sizeX, sizeY, scale, rotation, speedX, speedY, isHit);
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
GameObject* GameObjectManager::getGameObjectByTag(std::string tag){
    for (int i = 0; i < this->gameObjectList->size(); i++) {
        if (this->gameObjectList->at(i)->getTag() == (tag)) {
            return this->gameObjectList->at(i);
        }
    }
    return nullptr;
}
std::vector<GameObject*>* GameObjectManager::getGameObjectsByTag(std::string tag){
    std::vector<GameObject*>* result = new std::vector<GameObject*>();
    for (int i = 0; i < this->gameObjectList->size(); i++) {
        if (this->gameObjectList->at(i)->getTag() == tag) {
            result->push_back(this->gameObjectList->at(i));
        }
    }
    return result;
}
void GameObjectManager::removeGameObject(GameObject* gameObject){
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
    delete this->gameObject3DList;
    if (reinitialize) {
        this->gameObjectList = new std::vector<GameObject*>();
        this->gameObject3DList = new std::vector<GameObject3D*>();

    }
}







GameObject3D* GameObjectManager::addGameObject3D(GameObject3D* gameObject3D) {
    this->gameObject3DList->push_back(gameObject3D);
    return gameObject3D;
}

GameObject3D* GameObjectManager::addGameObject3D(std::string name, std::string tag, DrawData& drawData, float positionX, float positionY, float positionZ, float sizeX, float sizeY, float sizeZ, float scale, float rotationX, float rotationY, float rotationZ, float speedX, float speedY, float speedZ, bool isHit) {
    GameObject3D* gameObject3D = new GameObject3D(name, tag, drawData, positionX, positionY, positionZ, sizeX, sizeY, sizeZ, scale, rotationX, rotationY, rotationZ, speedX, speedY, speedZ, isHit);
    this->gameObject3DList->push_back(gameObject3D);
    return gameObject3D;
}

GameObject3D* GameObjectManager::addGameObject3D(std::string name, std::string tag, Mesh& mesh, Shader& shader, Texture2D& texture2D, float positionX, float positionY, float positionZ, float sizeX, float sizeY, float sizeZ, float scale, float rotationX, float rotationY, float rotationZ, float speedX, float speedY, float speedZ, bool isHit) {
    DrawData* drawData = new DrawData(name + "DrawData", mesh, shader, texture2D);
    GameObject3D* gameObject3D = new GameObject3D(name, tag, *drawData, positionX, positionY, positionZ, sizeX, sizeY, sizeZ, scale, rotationX, rotationY, rotationZ, speedX, speedY, speedZ, isHit);
    this->gameObject3DList->push_back(gameObject3D);
    return gameObject3D;
}

GameObject3D* GameObjectManager::getGameObject3DByName(std::string name) {
    for (int i = 0; i < this->gameObject3DList->size(); i++) {
        if (this->gameObject3DList->at(i)->getName() == name) {
            return this->gameObject3DList->at(i);
        }
    }
    return nullptr;
}
GameObject3D* GameObjectManager::getGameObject3DByTag(std::string tag) {
    for (int i = 0; i < this->gameObject3DList->size(); i++) {
        if (this->gameObject3DList->at(i)->getTag() == (tag)) {
            return this->gameObject3DList->at(i);
        }
    }
    return nullptr;
}
std::vector<GameObject3D*>* GameObjectManager::getGameObjects3DByTag(std::string tag) {
    std::vector<GameObject3D*>* result = new std::vector<GameObject3D*>();
    for (int i = 0; i < this->gameObject3DList->size(); i++) {
        if (this->gameObject3DList->at(i)->getTag() == tag) {
            result->push_back(this->gameObject3DList->at(i));
        }
    }
    return result;
}
void GameObjectManager::removeGameObject3D(GameObject3D* gameObject3D) {
    std::vector<GameObject3D*>* tempGameObject3DList = new std::vector<GameObject3D*>();
    for (int i = 0; i < this->gameObject3DList->size(); i++) {
        if (this->gameObject3DList->at(i)->getId() != gameObject3D->getId()) {
            tempGameObject3DList->push_back(this->gameObject3DList->at(i));
        }
    }
    delete this->gameObject3DList;
    this->gameObject3DList = tempGameObject3DList;
}