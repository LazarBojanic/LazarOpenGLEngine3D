#pragma once

#include "GLData.hpp"
#include "DrawData.hpp"
#include "Mesh.hpp"
#include "Shader.hpp"
#include "Model.hpp"
#include "Material.hpp"
#include "Light.hpp"
#include "Texture.hpp"
#include "CubeMap.hpp"
#include "Skybox.hpp"

class ResourceManager{
private:
	ResourceManager();
	~ResourceManager();
	static ResourceManager* instance;

	std::vector<Model*>* modelList;
	std::vector<Mesh*>* meshList;
	std::vector<Shader*>* shaderList;
	std::vector<Material*>* materialList;
	std::vector<Light*>* lightList;
	std::vector<Texture*>* textureList;
	std::vector<DrawData*>* drawDataList;
	std::vector<CubeMap*>* cubeMapList;
	std::vector<Skybox*>* skyboxList;
public:
	static ResourceManager* getInstance();
	Model* addModel(std::string path, std::string name);
	Mesh* addMesh(Primitive* primitive, Model* model, std::string name, int positionAttributeNumber, int positionDimensions, int colorAttributeNumber, int colorDimensions, int textureAttributeNumber, int textureDimensions, unsigned int normalAttributeNumber, unsigned int normalDimensions);
	Mesh* addSkyboxMesh(Primitive* primitive, std::string name, int positionAttributeNumber, int positionDimensions);
	Shader* addShader(std::string vertexShaderPath, std::string fragmentShaderPath, std::string name);
	Material* addMaterial(std::string name, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float shininess);
	Light* addLight(std::string name, glm::vec3 position, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular);
	Texture* addTexture(std::string texturePath, std::string name, std::string type);
	CubeMap* addCubeMap(std::vector<std::string>* facePaths, std::string name);
	Skybox* addSkybox(Mesh* mesh, Shader* shader, CubeMap* cubeMap, std::string name);
	DrawData* addDrawData(std::string name, Mesh* mesh, Shader* shader, Material* material, Light* light, std::vector<Texture*>* textureList);
	
	Model* getModelByName(std::string name);
	Mesh* getMeshByName(std::string name);
	Shader* getShaderByName(std::string name);
	Material* getMaterialByName(std::string name);
	Light* getLightByName(std::string name);
	Texture* getTextureByName(std::string name);
	CubeMap* getCubeMapByName(std::string name);
	Skybox* getSkyboxByName(std::string name);
	DrawData* getDrawDataByName(std::string name);

	inline std::vector<Model*>* getModelList() {
		return this->modelList;
	}
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
	inline std::vector<CubeMap*>* getCubeMapList() {
		return this->cubeMapList;
	}
	inline std::vector<Skybox*>* getSkyboxList() {
		return this->skyboxList;
	}
	inline std::vector<DrawData*>* getDrawDataList() {
		return this->drawDataList;
	}
	void clear(bool reinitialize);
};