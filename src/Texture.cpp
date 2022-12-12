#define STB_IMAGE_IMPLEMENTATION
#include <stb_image/stb_image.h>
#include "Texture.hpp"

Texture::Texture() {
}

Texture::Texture(std::string textureFilePath, bool alpha, std::string name) {
    HRESULT guidResult = CoCreateGuid(&this->id);
    this->name = name;
    this->wrap_S = GL_REPEAT;
    this->wrap_T = GL_REPEAT;
    this->filterMin = GL_LINEAR;
    this->filterMax = GL_LINEAR;
    this->imageFormat = GL_RGB;
    if (alpha) {
        this->imageFormat = GL_RGBA;
    }
    glGenTextures(1, &this->textureID);
    int tempWidth, tempHeight, tempNumberOfChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(textureFilePath.c_str(), &tempWidth, &tempHeight, &tempNumberOfChannels, STBI_rgb_alpha);
    this->width = tempWidth;
    this->height = tempHeight;
    generate(data);
    stbi_image_free(data);
}
Texture::~Texture() {
}
void Texture::generate(unsigned char* data) {
    bind(0);
    glTexImage2D(GL_TEXTURE_2D, 0, this->imageFormat, this->width, this->height, 0, this->imageFormat, GL_UNSIGNED_BYTE, data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, this->wrap_S);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, this->wrap_T);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, this->filterMin);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, this->filterMax);
    unbind();
}
void Texture::bind(unsigned int textureChannel) {
    glActiveTexture(GL_TEXTURE0 + textureChannel);
    glBindTexture(GL_TEXTURE_2D, this->textureID);
}
void Texture::unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
}