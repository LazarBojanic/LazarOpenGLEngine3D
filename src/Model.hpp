#pragma once

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "Geometry.hpp"
#include "GLData.hpp"

class Model {
private:
	GUID id;
	std::string name;
	std::string directory;
	std::vector<Geometry*>* geometries;
	bool gammaCorrection;
public:
	Model(std::string name, std::string path);
	~Model();
	void loadModel(std::string path);
	void processNode(aiNode* node, const aiScene* scene);
	Geometry* processMesh(aiMesh* mesh, const aiScene* scene);
	inline GUID getId() {
		return this->id;
	}
	inline std::string getName() {
		return this->name;
	}
	inline std::string getDirectory() {
		return this->directory;
	}
	inline std::vector<Geometry*>* getGeometries() {
		return this->geometries;
	}
	inline bool getGammaCorrection() {
		return this->gammaCorrection;
	}
};