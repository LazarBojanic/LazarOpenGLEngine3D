#define STB_IMAGE_IMPLEMENTATION
#include <stb_image/stb_image.h>
#include "Texture.hpp"

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
unsigned int Texture::loadTextureFromFile(const char* path, const std::string& directory, bool gamma) {
    std::string filename = std::string(path);
    filename = directory + '/' + filename;

    unsigned int textureID;
    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(filename.c_str(), &width, &height, &nrComponents, 0);
    if (data) {
        GLenum format = GL_RGBA;
        if (nrComponents == 1)
            format = GL_RED;
        else if (nrComponents == 3)
            format = GL_RGB;
        else if (nrComponents == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
    }
    else {
        std::cout << "Texture failed to load at path: " << path << std::endl;
        stbi_image_free(data);
    }

    return textureID;
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