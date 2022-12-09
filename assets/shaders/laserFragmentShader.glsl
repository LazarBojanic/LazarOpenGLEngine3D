#version 460 core

in vec2 vTextureCoords;
in vec4 vColor;

out vec4 fragColor;

uniform float uTime;
uniform vec2 uResolution;
uniform sampler2D uTexture;

void main(){
	fragColor = texture(uTexture, vTextureCoords);
}