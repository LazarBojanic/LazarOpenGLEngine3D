#pragma once

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "Geometry.hpp"
#include "Texture.hpp"
#include "GLData.hpp"

class Model {
private:
	std::string name;
	std::string directory;
	std::vector<Geometry*>* geometries;
	std::vector<Texture*>* texturesLoaded;
	bool gammaCorrection;
public:
	Model(std::string name, std::string path);
	~Model();
	void loadModel(std::string path);
	void processNode(aiNode* node, const aiScene* scene);
	Geometry* processMesh(aiMesh* mesh, const aiScene* scene);
	std::vector<Texture*>* loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);

	inline std::string getName() {
		return this->name;
	}
	inline std::string getDirectory() {
		return this->directory;
	}
	inline std::vector<Geometry*>* getGeometries() {
		return this->geometries;
	}
	inline std::vector<Texture*>* getTexturesLoaded() {
		return this->texturesLoaded;
	}
	inline bool getGammaCorrection() {
		return this->gammaCorrection;
	}
};