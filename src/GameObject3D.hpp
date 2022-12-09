#pragma once

#include "GLData.hpp"
#include "DrawData.hpp"

class GameObject3D {
private:
	GUID id;
	std::string name;
	std::string tag;
	DrawData* drawData;
	float positionX, positionY, positionZ;
	float sizeX, sizeY, sizeZ;
	float scale;
	float scaledSizeX, scaledSizeY, scaledSizeZ;
	float rotationX, rotationY, rotationZ;
	float speedX, speedY, speedZ;
	bool isHit;
public:
	GameObject3D();
	GameObject3D(std::string name, std::string tag, DrawData& drawData, float positionX, float positionY, float positionZ, float sizeX, float sizeY, float sizeZ, float scale, float rotationX, float rotationY, float rotationZ, float speedX, float speedY, float speedZ, bool isHit);
	~GameObject3D();
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
	inline float getScale() {
		return this->scale;
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
		this->scaledSizeX = this->sizeX * this->scale;
	}
	inline void setSizeY(float sizeY) {
		this->sizeY = sizeY;
		this->scaledSizeY = this->sizeY * this->scale;
	}
	inline void setSizeZ(float sizeZ) {
		this->sizeZ = sizeZ;
		this->scaledSizeZ = this->sizeZ * this->scale;
	}
	inline void setScale(float scale) {
		this->scale = scale;
		this->scaledSizeX = this->sizeX * this->scale;
		this->scaledSizeY = this->sizeY * this->scale;
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