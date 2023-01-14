#include "GameObject.hpp"

GameObject::GameObject(){
	HRESULT guidResult = CoCreateGuid(&this->id);
	this->name = "";
	this->tag = "";
	this->drawData = nullptr;
	this->positionX = 0.0f;
	this->positionY = 0.0f;
	this->positionZ = 0.0f;
	this->sizeX = 1.0f;
	this->sizeY = 1.0f;
	this->sizeZ = 1.0f;
	this->scaleX = 1.0f;
	this->scaleY = 1.0f;
	this->scaleZ = 1.0f;
	this->scaledSizeX = 1.0f;
	this->scaledSizeY = 1.0f;
	this->scaledSizeZ = 1.0f;
	this->rotationX = 0.0f;
	this->rotationY = 0.0f;
	this->rotationZ = 0.0f;
	this->speedX = 0.0f;
	this->speedY = 0.0f;
	this->speedZ = 0.0f;
	this->isHit = false;
}

GameObject::GameObject(std::string name, std::string tag, DrawData* drawData, float positionX, float positionY, float positionZ, float sizeX, float sizeY, float sizeZ, float scaleX, float scaleY, float scaleZ, float rotationX, float rotationY, float rotationZ, float speedX, float speedY, float speedZ, bool isHit){
	HRESULT guidResult = CoCreateGuid(&this->id);
	this->name = name;
	this->tag = tag;
	this->drawData = new DrawData(*drawData);
	this->positionX = positionX;
	this->positionY = positionY;
	this->positionZ = positionZ;
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	this->sizeZ = sizeZ;
	this->scaleX = scaleX;
	this->scaleY = scaleY;
	this->scaleZ = scaleZ;
	this->scaledSizeX = this->sizeX * this->scaleX;
	this->scaledSizeY = this->sizeY * this->scaleY;
	this->scaledSizeZ = this->sizeZ * this->scaleZ;
	this->rotationX = rotationX;
	this->rotationY = rotationY;
	this->rotationZ = rotationZ;
	this->speedX = speedX;
	this->speedY = speedY;
	this->speedZ = speedZ;
	this->isHit = isHit;
}

GameObject::~GameObject(){
	delete this->drawData;
}

void GameObject::updateShader() {
	if (this->drawData->getShader() != nullptr && this->drawData->getLight() != nullptr) {
		this->drawData->getShader()->setFloat("uTime", glfwGetTime(), true);
		this->drawData->getShader()->setVector3f("uLightPos", this->drawData->getLight()->position, true);
		this->drawData->getShader()->setVector3f("uLight.position", this->drawData->getLight()->position, true);
		this->drawData->getShader()->setVector3f("uLight.ambient", this->drawData->getLight()->ambient, true);
		this->drawData->getShader()->setVector3f("uLight.diffuse", this->drawData->getLight()->diffuse, true);
		this->drawData->getShader()->setVector3f("uLight.specular", this->drawData->getLight()->specular, true);
		if (this->drawData->getMaterial() != nullptr) {
			this->drawData->getShader()->setVector3f("uMaterial.ambient", this->drawData->getMaterial()->ambient, true);
			this->drawData->getShader()->setVector3f("uMaterial.diffuse", this->drawData->getMaterial()->diffuse, true);
			this->drawData->getShader()->setVector3f("uMaterial.specular", this->drawData->getMaterial()->specular, true);
			this->drawData->getShader()->setFloat("uMaterial.shininess", this->drawData->getMaterial()->shininess, true);
		}
		if (this->drawData->getTextureList() != nullptr) {
			for (int i = 0; i < this->drawData->getTextureList()->size(); i++) {
				this->drawData->getShader()->setInt(this->drawData->getTextureList()->at(i)->getName(), i, true);
			}
		}
	}
}