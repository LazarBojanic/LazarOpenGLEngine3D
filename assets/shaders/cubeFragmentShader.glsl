#version 460 core

in vec4 vColor;
in vec2 vTextureCoords;
in vec3 vNormal;
in vec3 vFragPos;

out vec4 fragColor;

uniform float uTime;
uniform vec3 uLightPos;
uniform vec3 uLightColor;
uniform vec3 uObjectColor;

void main(){
    // ambient
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * uLightColor;
  	
    // diffuse 
    vec3 norm = normalize(vNormal);
    vec3 lightDir = normalize(uLightPos - vFragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * uLightColor;
            
    vec3 result = (diffuse + ambient) * uObjectColor;
    fragColor = vec4(result, 1.0);
}