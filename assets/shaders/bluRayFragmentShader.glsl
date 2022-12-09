#version 460 core

in vec2 vTextureCoords;
in vec4 vColor;

out vec4 fragColor;

uniform sampler2D uTexture;
uniform vec4 uColor;

void main(){
    //color = vec4(spriteColor, 1.0) * texture(image, texCoords);
    //fragColor = vColor;
    fragColor = texture(uTexture, vTextureCoords) * uColor;
}