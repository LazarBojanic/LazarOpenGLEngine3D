#version 460 core

layout(location = 0) in vec3 iPos;

out vec3 vTextureCoords;
uniform mat4 uView;
uniform mat4 uProjection;

void main(){
    vTextureCoords = iPos;
    vec4 pos = uProjection * uView * vec4(iPos, 1.0);
    gl_Position = pos.xyww;
}