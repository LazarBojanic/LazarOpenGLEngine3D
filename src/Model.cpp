#include "Model.hpp"

Model::Model(std::string name, std::string path) {
    this->name = name;
    this->geometries = new std::vector<Geometry*>();
	loadModel(path);
}

Model::~Model() {
}

void Model::loadModel(std::string path) {
    Assimp::Importer import;
    const aiScene* scene = import.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);

    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        std::cout << "ERROR::ASSIMP::" << import.GetErrorString() << std::endl;
        return;
    }
    this->directory = path.substr(0, path.find_last_of('/'));

    processNode(scene->mRootNode, scene);
}

void Model::processNode(aiNode* node, const aiScene* scene) {
    for (unsigned int i = 0; i < node->mNumMeshes; i++) {
        aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
        this->geometries->push_back(processMesh(mesh, scene));
    }
    for (unsigned int i = 0; i < node->mNumChildren; i++) {
        processNode(node->mChildren[i], scene);
    }
}

Geometry* Model::processMesh(aiMesh* mesh, const aiScene* scene) {
    std::vector<GeometryVertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<GeometryTexture> textures;
    for (unsigned int i = 0; i < mesh->mNumVertices; i++) {
        GeometryVertex vertex;
        glm::vec3 vector;
        vector.x = mesh->mVertices[i].x;
        vector.y = mesh->mVertices[i].y;
        vector.z = mesh->mVertices[i].z;
        vertex.position = vector;
        if (mesh->HasNormals()) {
            vector.x = mesh->mNormals[i].x;
            vector.y = mesh->mNormals[i].y;
            vector.z = mesh->mNormals[i].z;
            vertex.normal = vector;
        }
        if (mesh->mTextureCoords[0]){
            glm::vec2 vec;

            vec.x = mesh->mTextureCoords[0][i].x;
            vec.y = mesh->mTextureCoords[0][i].y;
            vertex.textureCoords = vec;

            /*vector.x = mesh->mTangents[i].x;
            vector.y = mesh->mTangents[i].y;
            vector.z = mesh->mTangents[i].z;
            vertex.tangent = vector;

            vector.x = mesh->mBitangents[i].x;
            vector.y = mesh->mBitangents[i].y;
            vector.z = mesh->mBitangents[i].z;
            vertex.bitangent = vector;*/
        }
        else {
            vertex.textureCoords = glm::vec2(0.0f, 0.0f);
        }
        
        vertices.push_back(vertex);
    }
    for (unsigned int i = 0; i < mesh->mNumFaces; i++) {
        aiFace face = mesh->mFaces[i];
        for (unsigned int j = 0; j < face.mNumIndices; j++) {
            indices.push_back(face.mIndices[j]);
        }
    }
    aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
    std::vector<GeometryTexture> diffuseMaps = loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
    textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());

    std::vector<GeometryTexture> specularMaps = loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular");
    textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());

    std::vector<GeometryTexture> normalMaps = loadMaterialTextures(material, aiTextureType_HEIGHT, "texture_normal");
    textures.insert(textures.end(), normalMaps.begin(), normalMaps.end());

    std::vector<GeometryTexture> heightMaps = loadMaterialTextures(material, aiTextureType_AMBIENT, "texture_height");
    textures.insert(textures.end(), heightMaps.begin(), heightMaps.end());

    return new Geometry(vertices, indices, textures);
}
std::vector<GeometryTexture> Model::loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName) {
    std::vector<GeometryTexture> textures;
    for (unsigned int i = 0; i < mat->GetTextureCount(type); i++) {
        aiString path;
        mat->GetTexture(type, i, &path);
        bool skip = false;
        for (unsigned int j = 0; j < this->texturesLoaded.size(); j++) {
            if (std::strcmp(this->texturesLoaded.at(j).path.data(), path.C_Str()) == 0) {
                textures.push_back(this->texturesLoaded.at(j));
                skip = true;
                break;
            }
        }
        if (!skip) {
            GeometryTexture texture;
            texture.id = Texture::loadTextureFromFile(path.C_Str(), this->directory, true);
            texture.type = typeName;
            texture.path = path.C_Str();
            textures.push_back(texture);
            this->texturesLoaded.push_back(texture);
        }
    }
    return textures;
}
