#include "GameObject3D.hpp"

GameObject3D::GameObject3D(){
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
	this->scale = 1.0f;
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

GameObject3D::GameObject3D(std::string name, std::string tag, DrawData& drawData, float positionX, float positionY, float positionZ, float sizeX, float sizeY, float sizeZ, float scale, float rotationX, float rotationY, float rotationZ, float speedX, float speedY, float speedZ, bool isHit){
	HRESULT guidResult = CoCreateGuid(&this->id);
	this->name = name;
	this->tag = tag;
	this->drawData = new DrawData(drawData);
	this->positionX = positionX;
	this->positionY = positionY;
	this->positionZ = positionZ;
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	this->sizeZ = sizeZ;
	this->scale = scale;
	this->scaledSizeX = this->sizeX * this->scale;
	this->scaledSizeY = this->sizeY * this->scale;
	this->scaledSizeZ = this->sizeZ * this->scale;
	this->rotationX = rotationX;
	this->rotationY = rotationY;
	this->rotationZ = rotationZ;
	this->speedX = speedX;
	this->speedY = speedY;
	this->speedZ = speedZ;
	this->isHit = isHit;
}

GameObject3D::~GameObject3D(){
	delete this->drawData;
}
