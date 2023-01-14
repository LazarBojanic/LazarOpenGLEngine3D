#version 460 core

layout(location = 0) in vec3 iPos;
layout(location = 1) in vec3 iNormal;
layout(location = 2) in vec2 iTextureCoords;
layout(location = 3) in vec3 iTangent;
layout(location = 4) in vec3 iBitangent;
layout(location = 5) in vec4 iBoneIds;
layout(location = 6) in vec4 iWeights;

out vec3 vNormal;
out vec3 vFragPos;
out vec2 vTextureCoords;
out vec3 vTangentLightPos;
out vec3 vTangentViewPos;
out vec3 vTangentFragPos;

uniform mat4 uModel;
uniform mat4 uView;
uniform mat4 uProjection;

uniform vec3 uLightPos;
uniform vec3 uViewPos;

void main(){
    vTextureCoords = iTextureCoords;
    vFragPos = vec3(uModel * vec4(iPos, 1.0));
    vNormal = iNormal;

    mat3 normalMatrix = transpose(inverse(mat3(uModel)));
    vec3 T = normalize(normalMatrix * iTangent);
    vec3 N = normalize(normalMatrix * iNormal);
    T = normalize(T - dot(T, N) * N);
    vec3 B = cross(N, T);
    
    mat3 TBN = transpose(mat3(T, B, N));    
    vTangentLightPos = TBN * uLightPos;
    vTangentViewPos  = TBN * uViewPos;
    vTangentFragPos  = TBN * vFragPos;
        
    gl_Position = uProjection * uView * uModel * vec4(iPos, 1.0);
}