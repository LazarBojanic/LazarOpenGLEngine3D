#version 460 core


out vec4 fragColor;

in vec3 vTextureCoords;

uniform samplerCube skybox;

void main(){
    fragColor = texture(skybox, vTextureCoords);
}