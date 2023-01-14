#version 460 core


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

in vec3 vNormal;
in vec3 vFragPos;
in vec2 vTextureCoords;
in vec3 vTangentLightPos;
in vec3 vTangentViewPos;
in vec3 vTangentFragPos;

void main(){
    vec3 normal = texture(backpackNormal, vTextureCoords).rgb;
    normal = normalize(normal * 2.0 - 1.0);
    vec3 color = texture(backpackDiffuse, vTextureCoords).rgb;
    vec3 ambient = 0.1 * color;
    vec3 lightDir = normalize(vTangentLightPos - vTangentFragPos);
    float diff = max(dot(lightDir, normal), 0.0);
    vec3 diffuse = diff * color;
    vec3 viewDir = normalize(vTangentViewPos - vTangentFragPos);
    vec3 reflectDir = reflect(-lightDir, normal);
    vec3 halfwayDir = normalize(lightDir + viewDir);  
    float spec = pow(max(dot(normal, halfwayDir), 0.0), uMaterial.shininess);
    vec3 specular = uLight.specular * spec * texture(backpackSpecular, vTextureCoords).rgb;  

    fragColor = vec4(ambient + diffuse + specular, 1.0);
}