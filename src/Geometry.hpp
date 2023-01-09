#pragma once

#include "GLData.hpp"
#include "Texture.hpp"
#include "GeometryVertex.hpp"
#include "VertexArray.hpp"
#include "VertexBuffer.hpp"

class Geometry {
private:
    std::vector<GeometryVertex*>* vertices;
    std::vector<unsigned int>* indices;
    std::vector<Texture*>* textures;

    VertexArray* vertexArray;
    VertexBuffer* vertexBuffer;

public:
    Geometry(std::vector<GeometryVertex*>* vertices, std::vector<unsigned int>* indices, std::vector<Texture*>* textures);
    ~Geometry();
    void generate();
    inline std::vector<GeometryVertex*>* getVertices() {
        return this->vertices;
    }
    inline std::vector<unsigned int>* getIndices() {
        return this->indices;
    }
    inline std::vector<Texture*>* getTextures() {
        return this->textures;
    }
    inline VertexArray* getVertexArray() {
        return this->vertexArray;
    }
    inline VertexBuffer* getVertexBuffer() {
        return this->vertexBuffer;
    }
};