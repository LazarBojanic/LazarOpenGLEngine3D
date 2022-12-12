#version 460 core

in vec4 vColor;
in vec2 vTextureCoords;
in vec3 vNormal;

out vec4 fragColor;

uniform float uTime;
uniform vec3 uLightColor;

void main(){
    fragColor = vec4(uLightColor, 1.0);
}