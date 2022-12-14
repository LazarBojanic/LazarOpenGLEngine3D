#pragma once

#include "GLData.hpp"
#include "Mesh.hpp"
#include "Shader.hpp"
#include "Material.hpp"
#include "Light.hpp"
#include "Texture.hpp"
#include "GameObject.hpp"

class GameObjectManager{
private:
	GameObjectManager();
	~GameObjectManager();
	static GameObjectManager* instance;
	std::vector<GameObject*>* gameObjectList;
public:
	static GameObjectManager* getInstance();
	void clear(bool reinitialize);
	GameObject* addGameObject(GameObject* gameObject);
	GameObject* addGameObject(std::string name, std::string tag, DrawData* drawData, float positionX, float positionY, float positionZ, float sizeX, float sizeY, float sizeZ, float scaleX, float scaleY, float scaleZ, float rotationX, float rotationY, float rotationZ, float speedX, float speedY, float speedZ, bool isHit);
	GameObject* addGameObject(std::string name, std::string tag, Mesh* mesh, Shader* shader, Material* material, Light* light, Texture* texture, Texture* specular, float positionX, float positionY, float positionZ, float sizeX, float sizeY, float sizeZ, float scaleX, float scaleY, float scaleZ, float rotationX, float rotationY, float rotationZ, float speedX, float speedY, float speedZ, bool isHit);
	GameObject* getGameObjectByName(std::string name);
	GameObject* getGameObjectByTag(std::string tag);
	std::vector<GameObject*>* getGameObjectsByTag(std::string tag);
	void removeGameObject(GameObject* gameObject);
	inline std::vector<GameObject*>* getGameObjectList() {
		return this->gameObjectList;
	}
};

