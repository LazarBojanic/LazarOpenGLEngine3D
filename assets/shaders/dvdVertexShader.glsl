#version 460 core
layout (location = 0) in vec3 iPos;
layout (location = 1) in vec3 iColor;
layout (location = 2) in vec2 iTextureCoords;


out vec4 vColor;
out vec2 vTextureCoords;

uniform mat4 uModelView;
uniform mat4 uProjection;



void main(){
    gl_Position = uProjection * uModelView * vec4(iPos, 1.0f);
    vColor = vec4(iColor, 1.0f);
    vTextureCoords = iTextureCoords;
}