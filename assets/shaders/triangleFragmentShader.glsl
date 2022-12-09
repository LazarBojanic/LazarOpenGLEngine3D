#version 460 core

in vec4 vColor;
in vec2 vTextureCoords;

out vec4 fragColor;

uniform float uTime;

void main(){
    float red = clamp(sin(uTime), 0.5f, 1.0f);
    float green = 0.0f;
    float blue = clamp(cos(uTime), 0.5f, 1.0f);
    fragColor = vec4(red, green, blue, 1.0f);
}