#version 460 core

in vec4 vColor;
in vec2 vTextureCoords;
in vec3 vNormal;
in vec3 vFragPos;

out vec4 fragColor;

uniform float uTime;
uniform vec3 uViewPos;
uniform vec3 uCubeColor;

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
    vec3 ambient = uLight.ambient * texture(uMaterial.diffuse, vTextureCoords).rgb;
  	
    vec3 norm = normalize(vNormal);
    vec3 lightDir = normalize(uLight.position - vFragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = uLight.diffuse * diff * texture(uMaterial.diffuse, vTextureCoords).rgb;  
    
    vec3 viewDir = normalize(uViewPos - vFragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), uMaterial.shininess);
    vec3 specular = uLight.specular * spec * texture(uMaterial.specular, vTextureCoords).rgb;  
        
    vec3 result = ambient + diffuse + specular;
    fragColor = vec4(result, 1.0);
}