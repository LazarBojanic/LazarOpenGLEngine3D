#include "GameObject.hpp"

GameObject::GameObject(){
	HRESULT guidResult = CoCreateGuid(&this->id);
	this->name = "";
	this->tag = "";
	this->drawData = nullptr;
	this->positionX = 0.0f;
	this->positionY = 0.0f;
	this->sizeX = 0.0f;
	this->sizeY = 0.0f;
	this->scale = 1.0f;
	this->scaledSizeX = this->sizeX * this->scale;
	this->scaledSizeY = this->sizeY * this->scale;
	this->rotation = 0.0f;
	this->speedX = 0.0f;
	this->speedY = 0.0f;
	this->isHit = false;
}

GameObject::GameObject(std::string name, std::string tag, DrawData& drawData, float positionX, float positionY, float sizeX, float sizeY, float scale, float rotation, float speedX, float speedY, bool isHit){
	HRESULT guidResult = CoCreateGuid(&this->id);
	this->name = name;
	this->tag = tag;
	this->drawData = new DrawData(drawData);
	this->positionX = positionX;
	this->positionY = positionY;
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	this->scale = scale;
	this->scaledSizeX = this->sizeX * this->scale;
	this->scaledSizeY = this->sizeY * this->scale;
	this->rotation = rotation;
	this->speedX = speedX;
	this->speedY = speedY;
	this->isHit = isHit;
}

GameObject::~GameObject(){
	delete this->drawData;
}
