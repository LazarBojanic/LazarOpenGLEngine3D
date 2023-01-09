#pragma once

#include "GLData.hpp"
#define MAX_BONE_INFLUENCE 4

class GeometryVertex {
public:
    GeometryVertex(
        glm::vec3 position,
        glm::vec3 normal,
        glm::vec2 textureCoords,
        glm::vec3 tangent,
        glm::vec3 bitangent);
    GeometryVertex();
    ~GeometryVertex();
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 textureCoords;
    glm::vec3 tangent;
    glm::vec3 bitangent;
    int boneIds[MAX_BONE_INFLUENCE];
    float weights[MAX_BONE_INFLUENCE];
};