#version 460 core

in vec4 vColor;
in vec2 vTextureCoords;
in vec3 vNormal;
in vec3 vFragPos;

out vec4 fragColor;

uniform vec3 uViewPos;

uniform sampler2D texture_diffuse1;

void main(){
    fragColor = texture(texture_diffuse1, vTextureCoords);
}