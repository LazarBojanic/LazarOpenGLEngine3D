#version 460 core

in vec4 vColor;
in vec2 vTextureCoords;

out vec4 fragColor;

uniform float uTime;
uniform vec4 uColor;

void main(){
    fragColor = uColor;
}