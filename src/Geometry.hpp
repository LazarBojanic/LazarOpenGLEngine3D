#pragma once

#include "GLData.hpp"
#include "Texture.hpp"
#include "GeometryVertex.hpp"
#include "VertexBuffer.hpp"
#include "VertexArray.hpp"


class Geometry {
private:
    std::vector<GeometryVertex> vertices;
    std::vector<unsigned int> indices;

    VertexArray* vertexArray;
    VertexBuffer* vertexBuffer;

public:
    Geometry(std::vector<GeometryVertex> vertices, std::vector<unsigned int> indices);
    ~Geometry();
    void generate();
    inline std::vector<GeometryVertex> getVertices() {
        return this->vertices;
    }
    inline std::vector<unsigned int> getIndices() {
        return this->indices;
    }
    inline VertexArray* getVertexArray() {
        return this->vertexArray;
    }
    inline VertexBuffer* getVertexBuffer() {
        return this->vertexBuffer;
    }
};