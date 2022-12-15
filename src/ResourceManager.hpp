#pragma once

#include "GLData.hpp"
#include "DrawData.hpp"
#include "Mesh.hpp"
#include "Shader.hpp"
#include "Material.hpp"
#include "Light.hpp"
#include "Texture.hpp"

class ResourceManager{
private:
	ResourceManager();
	~ResourceManager();
	static ResourceManager* instance;

	std::vector<Mesh*>* meshList;
	std::vector<Shader*>* shaderList;
	std::vector<Material*>* materialList;
	std::vector<Light*>* lightList;
	std::vector<Texture*>* textureList;
	std::vector<DrawData*>* drawDataList;

public:
	static ResourceManager* getInstance();

	Mesh* addMesh(Primitive* primitive, std::string name, int positionAttributeNumber, int positionDimensions, int colorAttributeNumber, int colorDimensions, int textureAttributeNumber, int textureDimensions, unsigned int normalAttributeNumber, unsigned int normalDimensions);
	Shader* addShader(std::string vertexShaderPath, std::string fragmentShaderPath, std::string name);
	Material* addMaterial(std::string name, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float shininess);
	Light* addLight(std::string name, glm::vec3 position, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular);
	Texture* addTexture(std::string texturePath, bool alpha, std::string name);
	DrawData* addDrawData(std::string name, Mesh* mesh, Shader* shader, Material* material, Light* light, Texture* texture);
	
	Mesh* getMeshByName(std::string name);
	Shader* getShaderByName(std::string name);
	Material* getMaterialByName(std::string name);
	Light* getLightByName(std::string name);
	Texture* getTextureByName(std::string name);
	DrawData* getDrawDataByName(std::string name);

	inline std::vector<Mesh*>* getMeshList() {
		return this->meshList;
	}
	inline std::vector<Shader*>* getShaderList() {
		return this->shaderList;
	}
	inline std::vector<Material*>* getMaterialList() {
		return this->materialList;
	}
	inline std::vector<Light*>* getLightList() {
		return this->lightList;
	}
	inline std::vector<Texture*>* getTextureList() {
		return this->textureList;
	}
	inline std::vector<DrawData*>* getDrawDataList() {
		return this->drawDataList;
	}
	void clear(bool reinitialize);
};