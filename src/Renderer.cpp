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

void Renderer::draw(GameObject& gameObject, Camera& camera, bool scaled, bool indexed, bool textured){
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
    if (textured) {
        gameObject.getDrawData()->getShader()->setInt("uMaterial.diffuse", 0, true);
        gameObject.getDrawData()->getTexture()->bind(0);
    }
    gameObject.getDrawData()->getShader()->setMatrix4f("uModel", model, true);
    gameObject.getDrawData()->getShader()->setMatrix4f("uView", view, true);
    gameObject.getDrawData()->getShader()->setMatrix4f("uProjection", projection, true);
    gameObject.getDrawData()->getShader()->setVector3f("uViewPos", camera.getPosition(), true);
    gameObject.updateDrawData();
    if (indexed) {
        glDrawElements(GL_TRIANGLES, gameObject.getDrawData()->getMesh()->getPrimitive()->getIndicesCount(), GL_UNSIGNED_INT, 0);
    }
    else {
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }
    gameObject.getDrawData()->getMesh()->getVertexArray()->unbind();
}
void Renderer::drawAll(Camera& camera, bool scaled, bool indexed, bool textured) {
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
        if (textured) {
            gameObjectList->at(i)->getDrawData()->getShader()->setInt("uMaterial.diffuse", 0, true);
            gameObjectList->at(i)->getDrawData()->getTexture()->bind(0);
        }
        gameObjectList->at(i)->getDrawData()->getShader()->setMatrix4f("uModel", model, true);
        gameObjectList->at(i)->getDrawData()->getShader()->setMatrix4f("uView", view, true);
        gameObjectList->at(i)->getDrawData()->getShader()->setMatrix4f("uProjection", projection, true);
        gameObjectList->at(i)->getDrawData()->getShader()->setVector3f("uViewPos", camera.getPosition(), true);
        gameObjectList->at(i)->updateDrawData();
        if (indexed) {
            glDrawElements(GL_TRIANGLES, gameObjectList->at(i)->getDrawData()->getMesh()->getPrimitive()->getIndicesCount(), GL_UNSIGNED_INT, 0);
        }
        else {
            glDrawArrays(GL_TRIANGLES, 0, 36);
        }
        gameObjectList->at(i)->getDrawData()->getMesh()->getVertexArray()->unbind();
    }

}
void Renderer::colorBackground(glm::vec4 color) {
    glClearColor(color.x, color.y, color.z, color.w);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}