#version 460 core
layout (location = 0) in vec3 iPos;
layout (location = 1) in vec3 iColor;
layout (location = 2) in vec2 iTextureCoords;
layout (location = 3) in vec3 iNormal;

out vec4 vColor;
out vec2 vTextureCoords;
out vec3 vNormal;

uniform mat4 uModel;
uniform mat4 uView;
uniform mat4 uProjection;

void main(){
    gl_Position = uProjection *  uView * uModel * vec4(iPos, 1.0);
    vColor = vec4(iColor, 1.0);
    vTextureCoords = iTextureCoords;
    vNormal = iNormal;
}