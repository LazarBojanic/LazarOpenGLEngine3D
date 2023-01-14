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
    gameObject.getDrawData()->getShader()->setMatrix4f("uModel", model, true);
    gameObject.getDrawData()->getShader()->setMatrix4f("uView", view, true);
    gameObject.getDrawData()->getShader()->setMatrix4f("uProjection", projection, true);
    gameObject.getDrawData()->getShader()->setVector3f("uViewPos", camera.getPosition(), true);
    gameObject.updateShader();
    if (gameObject.getDrawData()->getMesh()->getPrimitive() != nullptr && gameObject.getDrawData()->getMesh()->getModel() == nullptr) {
        gameObject.getDrawData()->getMesh()->getVertexArray()->bind();
        if (gameObject.getDrawData()->getTextureList() != nullptr) {
            for (int i = 0; i < gameObject.getDrawData()->getTextureList()->size(); i++) {
                gameObject.getDrawData()->getTextureList()->at(i)->bind(i);
            }
        }
        if (gameObject.getDrawData()->getMesh()->getIsIndexed()) {
            glDrawElements(GL_TRIANGLES, gameObject.getDrawData()->getMesh()->getIndicesCount(), GL_UNSIGNED_INT, 0);
        }
        else {
            glDrawArrays(GL_TRIANGLES, 0, gameObject.getDrawData()->getMesh()->getUnindexedVertexCount());
        }
        gameObject.getDrawData()->getMesh()->getVertexArray()->unbind();
        if (gameObject.getDrawData()->getTextureList() != nullptr) {
            for (int i = 0; i < gameObject.getDrawData()->getTextureList()->size(); i++) {
                gameObject.getDrawData()->getTextureList()->at(i)->bind(i);
            }
        }
    }
    else if (gameObject.getDrawData()->getMesh()->getPrimitive() == nullptr && gameObject.getDrawData()->getMesh()->getModel() != nullptr) {
        for (int i = 0; i < gameObject.getDrawData()->getMesh()->getModel()->getGeometries()->size(); i++) {
            gameObject.getDrawData()->getMesh()->getModel()->getGeometries()->at(i)->getVertexArray()->bind();
            if (gameObject.getDrawData()->getTextureList() != nullptr) {
                for (int j = 0; j < gameObject.getDrawData()->getTextureList()->size(); j++) {
                    gameObject.getDrawData()->getTextureList()->at(j)->bind(j);
                }
            }
            glDrawElements(GL_TRIANGLES, gameObject.getDrawData()->getMesh()->getModel()->getGeometries()->at(i)->getIndices().size(), GL_UNSIGNED_INT, 0);
            if (gameObject.getDrawData()->getTextureList() != nullptr) {
                for (int j = 0; j < gameObject.getDrawData()->getTextureList()->size(); j++) {
                    gameObject.getDrawData()->getTextureList()->at(j)->unbind();
                }
            }
            gameObject.getDrawData()->getMesh()->getModel()->getGeometries()->at(i)->getVertexArray()->unbind();
        }
    }
}

void Renderer::drawAll(Camera& camera, bool scaled) {
    std::vector<GameObject*>* gameObjectList = GameObjectManager::getInstance()->getGameObjectList();
    for (int i = 0; i < gameObjectList->size(); i++) {
        draw(*gameObjectList->at(i), camera, scaled);
    }
}
void Renderer::colorBackground(glm::vec4 color) {
    glClearColor(color.x, color.y, color.z, color.w);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}