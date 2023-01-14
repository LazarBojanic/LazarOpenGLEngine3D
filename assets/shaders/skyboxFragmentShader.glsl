#version 460 core


out vec4 fragColor;

in vec3 vTextureCoords;

uniform samplerCube uSkybox;

void main(){
    fragColor = texture(uSkybox, vTextureCoords);
}