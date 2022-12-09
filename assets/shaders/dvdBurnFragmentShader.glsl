#version 460 core

in vec2 vTextureCoords;
in vec4 vColor;

out vec4 fragColor;

uniform sampler2D uTexture;
uniform vec4 uColor;
uniform float uTime;
uniform bool uDestroyed;
uniform float uStartTime;
uniform float uDuration;

vec2 uv = vTextureCoords;
vec4 ash = vec4(0.05, 0.05, 0.05, 1.0);
vec4 fire = vec4(0.72, 0.17, 0.07, 1.0);
int OCTAVES = 6;

float rand(vec2 coord){
	return fract(sin(dot(coord, vec2(12.9898, 78.233)))* 43758.5453123);
}
float noise(vec2 coord){
	vec2 wholePart = floor(coord);
	vec2 decimalPart = fract(coord);

	// 4 corners of a rectangle surrounding our point
	float a = rand(wholePart);
	float b = rand(wholePart + vec2(1.0, 0.0));
	float c = rand(wholePart + vec2(0.0, 1.0));
	float d = rand(wholePart + vec2(1.0, 1.0));

	vec2 cubic = decimalPart * decimalPart * (3.0 - 2.0 * decimalPart);

	return mix(a, b, cubic.x) + (c - a) * cubic.y * (1.0 - cubic.x) + (d - b) * cubic.x * cubic.y;
}
float fbm(vec2 coord){
	float value = 0.0;
	float scale = 0.5;
	for(int i = 0; i < OCTAVES; i++){
		value += noise(coord) * scale;
		coord *= 2.0;
		scale *= 0.5;
	}
	return value;
}
vec4 burn(vec4 originalColor, vec2 uv, float time) {
	vec4 newColor = originalColor; // value that will be returned
	float noise = fbm(uv);
	float thickness = 0.1;
	float outerEdge = (time - uStartTime) / uDuration;
	float innerEdge = outerEdge + thickness;
	
	// fade-in to the orange/black gradient
	if (noise < innerEdge) {
		float gradientFactor = (innerEdge - noise) / thickness;
		gradientFactor = clamp(gradientFactor, 0.0, 1.0);
		vec4 fireGradient = mix(fire, ash, gradientFactor);
		
		float innerFade = (innerEdge - noise) / 0.02;
		innerFade = clamp(innerFade, 0.0, 1.0);
		
		newColor = mix(newColor, fireGradient, innerFade);
	}
	// fade-out of the black at the end of the gradient
	if (noise < outerEdge) {
		newColor.a = 1.0 - (outerEdge - noise) / 0.03;
		newColor.a = clamp(newColor.a, 0.0, 1.0);
	}
	newColor.a *= originalColor.a;
	return newColor;
}

void main(){
    vec4 texColor = texture(uTexture, uv) * uColor;
	if(!uDestroyed){
		fragColor = texColor;
	}
	else{
		fragColor = burn(texColor, uv, uTime);
	}
}