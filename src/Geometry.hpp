#pragma once

#include "GLData.hpp"
#include "Texture.hpp"
#include "GeometryVertex.hpp"
#include "GeometryTexture.hpp"
#include "VertexBuffer.hpp"
#include "VertexArray.hpp"


class Geometry {
private:
    std::vector<GeometryVertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<GeometryTexture> textures;

    VertexArray* vertexArray;
    VertexBuffer* vertexBuffer;

public:
    Geometry(std::vector<GeometryVertex> vertices, std::vector<unsigned int> indices, std::vector<GeometryTexture> textures);
    ~Geometry();
    void generate();
    inline std::vector<GeometryVertex> getVertices() {
        return this->vertices;
    }
    inline std::vector<unsigned int> getIndices() {
        return this->indices;
    }
    inline std::vector<GeometryTexture> getTextures() {
        return this->textures;
    }
    inline VertexArray* getVertexArray() {
        return this->vertexArray;
    }
    inline VertexBuffer* getVertexBuffer() {
        return this->vertexBuffer;
    }
};