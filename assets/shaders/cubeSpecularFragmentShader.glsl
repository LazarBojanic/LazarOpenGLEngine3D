#version 460 core

in vec4 vColor;
in vec2 vTextureCoords;
in vec3 vNormal;
in vec3 vFragPos;

out vec4 fragColor;

uniform float uTime;
uniform float uShininess;
uniform vec3 uViewPos;
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
            
    // specular
    float specularStrength = 0.5;
    vec3 viewDir = normalize(uViewPos - vFragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), uShininess);
    vec3 specular = specularStrength * spec * uLightColor;  
        
    vec3 result = (ambient + diffuse + specular) * uObjectColor;
    fragColor = vec4(result, 1.0);
}