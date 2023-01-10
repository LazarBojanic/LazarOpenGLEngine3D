#pragma once

#include "GLData.hpp"

class Texture{
private:
	GUID id;
	std::string path;
    std::string name;
	std::string type;
	unsigned int textureID;
	unsigned int width;
	unsigned int height;
    unsigned int wrap_S;
    unsigned int wrap_T;
    unsigned int filterMin;
    unsigned int filterMag;
    GLenum format;
public:
    Texture();
    Texture(std::string textureFilePath, std::string name, std::string type);
	static unsigned int loadTextureFromFile(const char* path, const std::string& directory, bool gamma);
    ~Texture();
    void generate(unsigned char* data);
    void bind(unsigned int textureChannel);
    void unbind();
	inline GUID getId() {
		return this->id;
	}
	inline std::string getPath() {
		return this->path;
	}
	inline std::string getName() {
		return this->name;
	}
	inline std::string getType() {
		return this->type;
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
	inline unsigned int getFilterMag() {
		return this->filterMag;
	}
	inline GLenum getFormat() {
		return this->format;
	}
};