#version 460 core

in vec4 vColor;
in vec2 vTextureCoords;
in vec3 vNormal;
in vec3 vFragPos;

out vec4 fragColor;

uniform vec3 uViewPos;
uniform vec3 uCubeColor;

uniform sampler2D backpackAo;
uniform sampler2D backpackDiffuse;
uniform sampler2D backpackNormal;
uniform sampler2D backpackRoughness;
uniform sampler2D backpackSpecular;


struct Material {
    sampler2D diffuse;
    sampler2D specular;
    float     shininess;
}; 

struct Light {
    vec3 position;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform Material uMaterial;
uniform Light uLight;

void main(){
    fragColor = texture(backpackDiffuse, vTextureCoords);
}