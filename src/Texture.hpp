#pragma once

#include "GLData.hpp"

class Texture{
private:
	GUID id;
    std::string name;
	unsigned int textureID;
	unsigned int width;
	unsigned int height;
    unsigned int wrap_S;
    unsigned int wrap_T;
    unsigned int filterMin;
    unsigned int filterMax;
    unsigned int imageFormat;
public:
    Texture();
    Texture(std::string textureFilePath, bool alpha, std::string name);
    ~Texture();
    void generate(unsigned char* data);
    void bind(unsigned int textureChannel);
    void unbind();
	inline GUID getId() {
		return this->id;
	}
	inline std::string getName() {
		return this->name;
	}
	inline unsigned int getTextureID() {
		return this->textureID;
	}
	inline unsigned int getWidth() {
		return this->width;
	}
	inline unsigned int getHeight() {
		return this->height;
	}
	inline unsigned int getWrap_S() {
		return this->wrap_S;
	}
	inline unsigned int getWrap_T() {
		return this->wrap_T;
	}
	inline unsigned int getFilterMin() {
		return this->filterMin;
	}
	inline unsigned int getFilterMax() {
		return this->filterMax;
	}
	inline unsigned int getImageFormat() {
		return this->imageFormat;
	}
};