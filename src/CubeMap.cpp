
#include "CubeMap.hpp"
#include <stb_image/stb_image.h>

CubeMap::CubeMap(std::vector<std::string>* facePaths, std::string name) {
    HRESULT guidResult = CoCreateGuid(&this->id);
	glGenTextures(1, &this->cubeMapId);
	glBindTexture(GL_TEXTURE_CUBE_MAP, this->cubeMapId);
    this->name = name;
    this->wrap_S = GL_CLAMP_TO_EDGE;
    this->wrap_T = GL_CLAMP_TO_EDGE;
    this->wrap_R = GL_CLAMP_TO_EDGE;
    this->filterMin = GL_LINEAR;
    this->filterMag = GL_LINEAR;
	generate(facePaths);
}

CubeMap::~CubeMap() {
}

void CubeMap::bind(unsigned int textureChannel) {
	glActiveTexture(GL_TEXTURE0 + textureChannel);
	glBindTexture(GL_TEXTURE_CUBE_MAP, this->cubeMapId);
}

void CubeMap::unbind() {
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
}
void CubeMap::generate(std::vector<std::string>* facePaths) {
    int tempWidth, tempHeight, tempNumberOfChannels;
    for (unsigned int i = 0; i < facePaths->size(); i++) {
        stbi_set_flip_vertically_on_load(false);
        unsigned char* data = stbi_load(facePaths->at(i).c_str(), &tempWidth, &tempHeight, &tempNumberOfChannels, 0);
        if (data) {
            if (tempNumberOfChannels == 1) {
                this->format = GL_RED;
            }
            else if (tempNumberOfChannels == 2) {
                this->format = GL_RG;
            }
            else if (tempNumberOfChannels == 3) {
                this->format = GL_RGB;
            }
            else if (tempNumberOfChannels == 4) {
                this->format = GL_RGBA;
            }
            this->width = tempWidth;
            this->height = tempHeight;
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, this->format, this->width, this->height, 0, this->format, GL_UNSIGNED_BYTE, data);
            glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, this->filterMin);
            glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, this->filterMag);
            glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, this->wrap_S);
            glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, this->wrap_T);
            glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, this->wrap_R);
            stbi_image_free(data);
        }
        else {
            std::cout << "Cubemap texture failed to load at path: " << facePaths->at(i) << std::endl;
            stbi_image_free(data);
        }
    }
}