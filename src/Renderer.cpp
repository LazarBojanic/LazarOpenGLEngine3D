#include "Renderer.hpp"


Renderer* Renderer::instance;

Renderer::Renderer() {

}
Renderer::~Renderer() {
    
}

Renderer* Renderer::getInstance(){
    if (!instance) {
        instance = new Renderer();
    }
    return instance;
}

void Renderer::draw(GameObject& gameObject, Camera& camera, bool scaled){
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(gameObject.getPositionX(), gameObject.getPositionY(), gameObject.getPositionZ()));
    model = glm::rotate(model, glm::radians(gameObject.getRotationX()), glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, glm::radians(gameObject.getRotationY()), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, glm::radians(gameObject.getRotationZ()), glm::vec3(0.0f, 0.0f, 1.0f));
    if (!scaled) {
        model = glm::scale(model, glm::vec3(gameObject.getSizeX(), gameObject.getSizeY(), gameObject.getSizeZ()));
    }
    else {
        model = glm::scale(model, glm::vec3(gameObject.getScaledSizeX(), gameObject.getScaledSizeY(), gameObject.getScaledSizeZ()));
    }
    glm::mat4 view = camera.getView();
    glm::mat4 projection = camera.getProjection();
    gameObject.getDrawData()->getMesh()->getVertexArray()->bind();

    if (gameObject.getDrawData()->getTexture() != nullptr) {
        gameObject.getDrawData()->getTexture()->bind(0);
    }
    if (gameObject.getDrawData()->getSpecular() != nullptr) {
        gameObject.getDrawData()->getSpecular()->bind(1);
    }
    gameObject.getDrawData()->getShader()->setMatrix4f("uModel", model, true);
    gameObject.getDrawData()->getShader()->setMatrix4f("uView", view, true);
    gameObject.getDrawData()->getShader()->setMatrix4f("uProjection", projection, true);
    gameObject.getDrawData()->getShader()->setVector3f("uViewPos", camera.getPosition(), true);
    gameObject.updateShaderLighting();
    if (gameObject.getDrawData()->getMesh()->getIsIndexed()) {
        glDrawElements(GL_TRIANGLES, gameObject.getDrawData()->getMesh()->getIndicesCount(), GL_UNSIGNED_INT, 0);
    }
    else {
        glDrawArrays(GL_TRIANGLES, 0, gameObject.getDrawData()->getMesh()->getUnindexedVertexCount());
    }
    gameObject.getDrawData()->getMesh()->getVertexArray()->unbind();
}

void Renderer::drawAll(Camera& camera, bool scaled) {
    std::vector<GameObject*>* gameObjectList = GameObjectManager::getInstance()->getGameObjectList();
    for (int i = 0; i < gameObjectList->size(); i++) {
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(gameObjectList->at(i)->getPositionX(), gameObjectList->at(i)->getPositionY(), gameObjectList->at(i)->getPositionZ()));
        model = glm::rotate(model, glm::radians(gameObjectList->at(i)->getRotationX()), glm::vec3(1.0f, 0.0f, 0.0f));
        model = glm::rotate(model, glm::radians(gameObjectList->at(i)->getRotationY()), glm::vec3(0.0f, 1.0f, 0.0f));
        model = glm::rotate(model, glm::radians(gameObjectList->at(i)->getRotationZ()), glm::vec3(0.0f, 0.0f, 1.0f));
        if (!scaled) {
            model = glm::scale(model, glm::vec3(gameObjectList->at(i)->getSizeX(), gameObjectList->at(i)->getSizeY(), gameObjectList->at(i)->getSizeZ()));
        }
        else {
            model = glm::scale(model, glm::vec3(gameObjectList->at(i)->getScaledSizeX(), gameObjectList->at(i)->getScaledSizeY(), gameObjectList->at(i)->getScaledSizeZ()));
        }
        glm::mat4 view = camera.getView();
        glm::mat4 projection = camera.getProjection();
        gameObjectList->at(i)->getDrawData()->getMesh()->getVertexArray()->bind();
        if (gameObjectList->at(i)->getDrawData()->getTexture() != nullptr) {
            gameObjectList->at(i)->getDrawData()->getShader()->setInt("uMaterial.diffuse", 0, true);
            gameObjectList->at(i)->getDrawData()->getTexture()->bind(0);
        }
        gameObjectList->at(i)->getDrawData()->getShader()->setMatrix4f("uModel", model, true);
        gameObjectList->at(i)->getDrawData()->getShader()->setMatrix4f("uView", view, true);
        gameObjectList->at(i)->getDrawData()->getShader()->setMatrix4f("uProjection", projection, true);
        gameObjectList->at(i)->getDrawData()->getShader()->setVector3f("uViewPos", camera.getPosition(), true);
        gameObjectList->at(i)->updateShaderLighting();
        if (gameObjectList->at(i)->getDrawData()->getMesh()->getIsIndexed()) {
            glDrawElements(GL_TRIANGLES, gameObjectList->at(i)->getDrawData()->getMesh()->getIndicesCount(), GL_UNSIGNED_INT, 0);
        }
        else {
            glDrawArrays(GL_TRIANGLES, 0, gameObjectList->at(i)->getDrawData()->getMesh()->getUnindexedVertexCount());
        }
        gameObjectList->at(i)->getDrawData()->getMesh()->getVertexArray()->unbind();
    }

}
void Renderer::drawModel(GameObject& gameObject, Camera& camera, bool scaled) {
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(gameObject.getPositionX(), gameObject.getPositionY(), gameObject.getPositionZ()));
    model = glm::rotate(model, glm::radians(gameObject.getRotationX()), glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, glm::radians(gameObject.getRotationY()), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, glm::radians(gameObject.getRotationZ()), glm::vec3(0.0f, 0.0f, 1.0f));
    if (!scaled) {
        model = glm::scale(model, glm::vec3(gameObject.getSizeX(), gameObject.getSizeY(), gameObject.getSizeZ()));
    }
    else {
        model = glm::scale(model, glm::vec3(gameObject.getScaledSizeX(), gameObject.getScaledSizeY(), gameObject.getScaledSizeZ()));
    }
    glm::mat4 view = camera.getView();
    glm::mat4 projection = camera.getProjection();

    gameObject.getDrawData()->getShader()->setMatrix4f("uModel", model, true);
    gameObject.getDrawData()->getShader()->setMatrix4f("uView", view, true);
    gameObject.getDrawData()->getShader()->setMatrix4f("uProjection", projection, true);
    gameObject.getDrawData()->getShader()->setVector3f("uViewPos", camera.getPosition(), true);
    gameObject.updateShaderLighting();

    for (int i = 0; i < gameObject.getDrawData()->getMesh()->getModel()->getGeometries()->size(); i++) {

        gameObject.getDrawData()->getMesh()->getModel()->getGeometries()->at(i)->getVertexArray()->bind();

        unsigned int diffuseNr = 1;
        unsigned int specularNr = 1;
        unsigned int normalNr = 1;
        unsigned int heightNr = 1;

        std::cout << gameObject.getDrawData()->getMesh()->getModel()->getGeometries()->size() << std::endl;
        for (int j = 0; j < gameObject.getDrawData()->getMesh()->getModel()->getGeometries()->at(i)->getTextures().size(); j++) {
            std::string number;
            std::string name = gameObject.getDrawData()->getMesh()->getModel()->getGeometries()->at(i)->getTextures().at(j).type;
            std::cout << name << std::endl;
            if (name == "texture_diffuse") {
                number = std::to_string(diffuseNr++);
            }
            else if (name == "texture_specular") {
                number = std::to_string(specularNr++);
            }
            else if (name == "texture_normal") {
                number = std::to_string(normalNr++);
            }
            else if (name == "texture_height") {
                number = std::to_string(heightNr++);
            }
            gameObject.getDrawData()->getShader()->setInt((name + number).c_str(), i, true);

            glActiveTexture(GL_TEXTURE0 + j);
            glBindTexture(GL_TEXTURE_2D, gameObject.getDrawData()->getMesh()->getModel()->getGeometries()->at(i)->getTextures().at(j).id);

            glDrawElements(GL_TRIANGLES, gameObject.getDrawData()->getMesh()->getModel()->getGeometries()->at(i)->getIndices().size(), GL_UNSIGNED_INT, 0);
        }
    }
}
void Renderer::colorBackground(glm::vec4 color) {
    glClearColor(color.x, color.y, color.z, color.w);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}