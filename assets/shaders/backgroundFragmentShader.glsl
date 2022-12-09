#version 460 core

in vec2 vTextureCoords;
in vec4 vColor;

out vec4 fragColor;

uniform float uTime;
uniform vec2 uResolution;
vec2 uv = vTextureCoords;

float invAr = uResolution.y / uResolution.x;
vec2 center = vec2(0.5,0.5);
float speed = 0.035;

void main(){
    vec3 col = vec4(uv,0.5+0.5*sin(uTime),1.0).xyz;
   
    vec3 texcol;
			
	float x = (center.x-uv.x);
	float y = (center.y-uv.y) *invAr;
		
	//float r = -sqrt(x*x + y*y); //uncoment this line to symmetric ripples
	float r = -(x*x + y*y);
	float z = 1.0 + 0.5*sin((r+uTime*speed)/0.013);
	
	texcol.x = z;
	texcol.y = z;
	texcol.z = z;

	fragColor = vec4(col*texcol,0.2);
}