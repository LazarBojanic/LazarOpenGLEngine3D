#pragma once

#include "GLData.hpp"
#include "DrawData.hpp"

class GameObject {
private:
	GUID id;
	std::string name;
	std::string tag;
	DrawData* drawData;
	float positionX, positionY, positionZ;
	float sizeX, sizeY, sizeZ;
	float scaleX, scaleY, scaleZ;
	float scaledSizeX, scaledSizeY, scaledSizeZ;
	float rotationX, rotationY, rotationZ;
	float speedX, speedY, speedZ;
	bool isHit;
public:
	GameObject();
	GameObject(std::string name, std::string tag, DrawData& drawData, float positionX, float positionY, float positionZ, float sizeX, float sizeY, float sizeZ, float scaleX, float scaleY, float scaleZ, float rotationX, float rotationY, float rotationZ, float speedX, float speedY, float speedZ, bool isHit);
	~GameObject();
	void updateDrawData();
	inline GUID getId() {
		return this->id;
	}
	inline std::string getName() {
		return this->name;
	}
	inline std::string getTag() {
		return this->tag;
	}
	inline DrawData* getDrawData() {
		return this->drawData;
	}
	inline float getPositionX() {
		return this->positionX;
	}
	inline float getPositionY() {
		return this->positionY;
	}
	inline float getPositionZ() {
		return this->positionZ;
	}
	inline float getSizeX() {
		return this->sizeX;
	}
	inline float getSizeY() {
		return this->sizeY;
	}
	inline float getSizeZ() {
		return this->sizeZ;
	}
	inline float getScaleX() {
		return this->scaleX;
	}
	inline float getScaleY() {
		return this->scaleY;
	}
	inline float getScaleZ() {
		return this->scaleZ;
	}
	inline float getScaledSizeX() {
		return this->scaledSizeX;
	}
	inline float getScaledSizeY() {
		return this->scaledSizeY;
	}
	inline float getScaledSizeZ() {
		return this->scaledSizeZ;
	}
	inline float getRotationX() {
		return this->rotationX;
	}
	inline float getRotationY() {
		return this->rotationY;
	}
	inline float getRotationZ() {
		return this->rotationZ;
	}
	inline float getSpeedX() {
		return this->speedX;
	}
	inline float getSpeedY() {
		return this->speedY;
	}
	inline float getSpeedZ() {
		return this->speedZ;
	}
	inline bool getIsHit() {
		return this->isHit;
	}

	inline void setName(std::string name) {
		this->name = name;
	}
	inline void setTag(std::string tag) {
		this->tag = tag;
	}
	inline void setPositionX(float positionX) {
		this->positionX = positionX;
	}
	inline void setPositionY(float positionY) {
		this->positionY = positionY;
	}
	inline void setPositionZ(float positionZ) {
		this->positionZ = positionZ;
	}
	inline void setSizeX(float sizeX) {
		this->sizeX = sizeX;
		this->scaledSizeX = this->sizeX * this->scaleX;
	}
	inline void setSizeY(float sizeY) {
		this->sizeY = sizeY;
		this->scaledSizeY = this->sizeY * this->scaleY;
	}
	inline void setSizeZ(float sizeZ) {
		this->sizeZ = sizeZ;
		this->scaledSizeZ = this->sizeZ * this->scaleZ;
	}
	inline void setScaleX(float scaleX) {
		this->scaleX = scaleX;
		this->scaledSizeX = this->sizeX * this->scaleX;
	}
	inline void setScaleY(float scaleY) {
		this->scaleY = scaleY;
		this->scaledSizeY = this->sizeY * this->scaleY;
	}
	inline void setScaleZ(float scaleZ) {
		this->scaleZ = scaleZ;
		this->scaledSizeZ = this->sizeZ * this->scaleZ;
	}
	inline void setRotationX(float rotationX) {
		this->rotationX = rotationX;
	}
	inline void setRotationY(float rotationY) {
		this->rotationY = rotationY;
	}
	inline void setRotationZ(float rotationZ) {
		this->rotationZ = rotationZ;
	}
	inline void setSpeedX(float speedX) {
		this->speedX = speedX;
	}
	inline void setSpeedY(float speedY){
		this->speedY = speedY;
	}
	inline void setSpeedZ(float speedZ) {
		this->speedZ = speedZ;
	}
	inline void setIsHit(bool isHit) {
		this->isHit = isHit;
	}
};