#pragma once

#include "GLData.hpp"

class CubeMap {
private:
	GUID id;
	unsigned int cubeMapId;
	std::vector<std::string>* facePaths;
	std::string name;
	unsigned int width;
	unsigned int height;
	unsigned int wrap_S;
	unsigned int wrap_T;
	unsigned int wrap_R;
	unsigned int filterMin;
	unsigned int filterMag;
	GLenum format;
public:
	CubeMap(std::vector<std::string>* facePaths, std::string name);
	~CubeMap();
	void bind(unsigned int textureChannel);
	void unbind();
	void generate(std::vector<std::string>* facePaths);
	inline GUID getId() {
		return this->id;
	}
	inline unsigned int getCubeMapId() {
		return this->cubeMapId;
	}
	inline std::vector<std::string>* getFacePaths() {
		return this->facePaths;
	}
	inline std::string getName() {
		return this->name;
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
	inline unsigned int getWrap_R() {
		return this->wrap_R;
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