#include "Texture.hpp"
#include <stb_image/stb_image.h>

Texture::Texture() {
}

Texture::Texture(std::string textureFilePath, std::string name, std::string type) {
    HRESULT guidResult = CoCreateGuid(&this->id);
    this->name = name;
    this->path = textureFilePath;
    this->type = type;
    this->wrap_S = GL_REPEAT;
    this->wrap_T = GL_REPEAT;
    this->filterMin = GL_LINEAR_MIPMAP_LINEAR;
    this->filterMag = GL_LINEAR;
    glGenTextures(1, &this->textureID);
    int tempWidth, tempHeight, tempNumberOfChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(textureFilePath.c_str(), &tempWidth, &tempHeight, &tempNumberOfChannels, 0);
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
    generate(data);
    stbi_image_free(data);
}
Texture::~Texture() {
}
void Texture::generate(unsigned char* data) {
    glBindTexture(GL_TEXTURE_2D, this->textureID);
    glTexImage2D(GL_TEXTURE_2D, 0, this->format, this->width, this->height, 0, this->format, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, this->wrap_S);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, this->wrap_T);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, this->filterMin);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, this->filterMag);
    unbind();
    
}
void Texture::bind(unsigned int textureChannel) {
    glActiveTexture(GL_TEXTURE0 + textureChannel);
    glBindTexture(GL_TEXTURE_2D, this->textureID);
}
void Texture::unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
}