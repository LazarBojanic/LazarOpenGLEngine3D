#version 460 core

layout(location = 0) in vec3 iPos;
layout(location = 1) in vec3 iNormal;
layout(location = 2) in vec2 iTextureCoords;
layout(location = 3) in vec3 iTangent;
layout(location = 4) in vec3 iBitangent;
layout(location = 5) in vec4 iBoneIds;
layout(location = 6) in vec4 iWeights;

out vec4 vColor;
out vec2 vTextureCoords;
out vec3 vNormal;
out vec3 vFragPos;

uniform mat4 uModel;
uniform mat4 uView;
uniform mat4 uProjection;

void main(){
    vTextureCoords = iTextureCoords;
    vNormal = mat3(transpose(inverse(uModel))) * iNormal; 
    vFragPos = vec3(uModel * vec4(iPos, 1.0));

    gl_Position = uProjection * uView * vec4(vFragPos, 1.0);
}