#version 460 core

in vec2 vTextureCoords;
in vec4 vColor;

out vec4 fragColor;

uniform sampler2D uTexture;
uniform vec4 uColor;

void main(){
    fragColor = texture(uTexture, vTextureCoords) * uColor;
}