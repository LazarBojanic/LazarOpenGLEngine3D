#pragma once

#include "GLData.hpp"
#include "DrawData.hpp"

class GameObject {
private:
	GUID id;
	std::string name;
	std::string tag;
	DrawData* drawData;
	float positionX, positionY;
	float sizeX, sizeY;
	float scale;
	float scaledSizeX, scaledSizeY;
	float rotation;
	float speedX, speedY;
	bool isHit;
public:
	GameObject();
	GameObject(std::string name, std::string tag, DrawData& drawData, float positionX, float positionY, float sizeX, float sizeY, float scale, float rotation, float speedX, float speedY, bool isHit);
	~GameObject();
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
	inline float getSizeX() {
		return this->sizeX;
	}
	inline float getSizeY() {
		return this->sizeY;
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
	inline float getRotation() {
		return this->rotation;
	}
	inline float getSpeedX() {
		return this->speedX;
	}
	inline float getSpeedY() {
		return this->speedY;
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
	inline void setSizeX(float sizeX) {
		this->sizeX = sizeX;
		this->scaledSizeX = this->sizeX * this->scale;
	}
	inline void setSizeY(float sizeY) {
		this->sizeY = sizeY;
		this->scaledSizeY = this->sizeY * this->scale;
	}
	inline void setScale(float scale) {
		this->scale = scale;
		this->scaledSizeX = this->sizeX * this->scale;
		this->scaledSizeY = this->sizeY * this->scale;
	}
	inline void setRotation(float rotation) {
		this->rotation = rotation;
	}
	inline void setSpeedX(float speedX) {
		this->speedX = speedX;
	}
	inline void setSpeedY(float speedY){
		this->speedY = speedY;
	}
	inline void setIsHit(bool isHit) {
		this->isHit = isHit;
	}
};