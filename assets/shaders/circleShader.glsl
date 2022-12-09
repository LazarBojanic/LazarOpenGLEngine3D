#version 460 core

#define PI 3.14159265359

in vec2 vTextureCoords;
in vec4 vColor;

out vec4 fragColor;

uniform sampler2D uTexture;
uniform vec4 uColor;
uniform float uTime;

uniform vec2 uMouse;
uniform sampler2D texture;

vec2 uv = vTextureCoords;

float circle(vec2 uv, vec2 center, float radius){
  float distFromCenter = distance(center, uv);
  return 1.0 - step(radius, distFromCenter);
}

float circleSmooth(vec2 uv, vec2 center, float radius, float smoothness){
  float distFromCenter = distance(center, uv);
  return 1.0 - smoothstep(radius - smoothness * 0.5, radius + smoothness * 0.5, distFromCenter);
}

void main(){
  float circ = circle(uv, vec2(0.5), 0.35);
  float circsmooth = circleSmooth(uv, vec2(0.5), 0.35, 0.05);

  vec3 color = vec3(circ);
  fragColor = vec4(color, 1.0);
}