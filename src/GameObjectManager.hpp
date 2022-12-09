#pragma once

#include "GLData.hpp"
#include "Mesh.hpp"
#include "Shader.hpp"
#include "Texture2D.hpp"
#include "GameObject.hpp"
#include "GameObject3D.hpp"

class GameObjectManager{
private:
	GameObjectManager();
	~GameObjectManager();
	static GameObjectManager* instance;
	std::vector<GameObject*>* gameObjectList;
	std::vector<GameObject3D*>* gameObject3DList;
public:
	static GameObjectManager* getInstance();
	GameObject* addGameObject(GameObject* gameObject);
	GameObject* addGameObject(std::string name, std::string tag, DrawData& drawData,
		float positionX, float positionY, float sizeX, float sizeY, float scale, float rotation, float speedX, float speedY, bool isHit);
	GameObject* addGameObject(std::string name, std::string tag, Mesh& mesh, Shader& shader, Texture2D& texture2D,
		float positionX, float positionY, float sizeX, float sizeY, float scale, float rotation, float speedX, float speedY, bool isHit);
	GameObject* getGameObjectByName(std::string name);
	GameObject* getGameObjectByTag(std::string tag);
	std::vector<GameObject*>* getGameObjectsByTag(std::string tag);
	void removeGameObject(GameObject* gameObject);
	void clear(bool reinitialize);

	GameObject3D* addGameObject3D(GameObject3D* gameObject);
	GameObject3D* addGameObject3D(std::string name, std::string tag, DrawData& drawData, float positionX, float positionY, float positionZ, float sizeX, float sizeY, float sizeZ, float scale, float rotationX, float rotationY, float rotationZ, float speedX, float speedY, float speedZ, bool isHit);
	GameObject3D* addGameObject3D(std::string name, std::string tag, Mesh& mesh, Shader& shader, Texture2D& texture2D, float positionX, float positionY, float positionZ, float sizeX, float sizeY, float sizeZ, float scale, float rotationX, float rotationY, float rotationZ, float speedX, float speedY, float speedZ, bool isHit);
	GameObject3D* getGameObject3DByName(std::string name);
	GameObject3D* getGameObject3DByTag(std::string tag);
	std::vector<GameObject3D*>* getGameObjects3DByTag(std::string tag);
	void removeGameObject3D(GameObject3D* gameObject);
};

