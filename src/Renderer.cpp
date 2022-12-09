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

void Renderer::draw(GameObject& gameObject, bool scaled) {
    glm::mat4 modelView = glm::mat4(1.0f);
    modelView = glm::translate(modelView, glm::vec3(glm::vec2(gameObject.getPositionX(), gameObject.getPositionY()), 0.0f));
    modelView = glm::rotate(modelView, glm::radians(gameObject.getRotation()), glm::vec3(0.0f, 0.0f, 1.0f));
    if (!scaled) {
        modelView = glm::scale(modelView, glm::vec3(glm::vec2(gameObject.getSizeX(), gameObject.getSizeY()), 1.0f));
    }
    else {
        modelView = glm::scale(modelView, glm::vec3(glm::vec2(gameObject.getScaledSizeX(), gameObject.getScaledSizeY()), 1.0f));
    }
    gameObject.getDrawData()->getMesh()->getVertexArray()->bind();
    gameObject.getDrawData()->getTexture2D()->bind(0);
    gameObject.getDrawData()->getShader()->setMatrix4f("uModelView", modelView, true);
    glDrawElements(GL_TRIANGLES, gameObject.getDrawData()->getMesh()->getPrimitive()->getIndicesCount(), GL_UNSIGNED_INT, 0);
    gameObject.getDrawData()->getMesh()->getVertexArray()->unbind();
}
void Renderer::drawUntextured(GameObject& gameObject, bool scaled) {
    glm::mat4 modelView = glm::mat4(1.0f);
    modelView = glm::translate(modelView, glm::vec3(glm::vec2(gameObject.getPositionX(), gameObject.getPositionY()), 0.0f));
    modelView = glm::rotate(modelView, glm::radians(gameObject.getRotation()), glm::vec3(0.0f, 0.0f, 1.0f));
    if (!scaled) {
        modelView = glm::scale(modelView, glm::vec3(glm::vec2(gameObject.getSizeX(), gameObject.getSizeY()), 1.0f));
    }
    else {
        modelView = glm::scale(modelView, glm::vec3(glm::vec2(gameObject.getScaledSizeX(), gameObject.getScaledSizeY()), 1.0f));
    }
    gameObject.getDrawData()->getMesh()->getVertexArray()->bind();
    gameObject.getDrawData()->getShader()->setMatrix4f("uModelView", modelView, true);
    glDrawElements(GL_TRIANGLES, gameObject.getDrawData()->getMesh()->getPrimitive()->getIndicesCount(), GL_UNSIGNED_INT, 0);
    gameObject.getDrawData()->getMesh()->getVertexArray()->unbind();
}

void Renderer::draw3DUntextured(GameObject3D& gameObject3D, Camera& camera, float width, float height, bool scaled){
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(gameObject3D.getPositionX(), gameObject3D.getPositionY(), gameObject3D.getPositionZ()));

    model = glm::rotate(model, glm::radians(gameObject3D.getRotationX()), glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, glm::radians(gameObject3D.getRotationY()), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, glm::radians(gameObject3D.getRotationZ()), glm::vec3(0.0f, 0.0f, 1.0f));

    if (!scaled) {
        model = glm::scale(model, glm::vec3(gameObject3D.getSizeX(), gameObject3D.getSizeY(), gameObject3D.getSizeZ()));
    }
    else {
        model = glm::scale(model, glm::vec3(gameObject3D.getScaledSizeX(), gameObject3D.getScaledSizeY(), gameObject3D.getScaledSizeZ()));
    }
    glm::mat4 view = camera.getViewMatrix();
    glm::mat4 projection = glm::perspective(glm::radians(camera.getZoom()), width / height, 0.1f, 100.0f);

    gameObject3D.getDrawData()->getMesh()->getVertexArray()->bind();
    gameObject3D.getDrawData()->getShader()->setMatrix4f("uModel", model, true);
    gameObject3D.getDrawData()->getShader()->setMatrix4f("uView", view, true);
    gameObject3D.getDrawData()->getShader()->setMatrix4f("uProjection", projection, true);
    glDrawElements(GL_TRIANGLES, gameObject3D.getDrawData()->getMesh()->getPrimitive()->getIndicesCount(), GL_UNSIGNED_INT, 0);
    gameObject3D.getDrawData()->getMesh()->getVertexArray()->unbind();

}

void Renderer::colorBackground(glm::vec4 color) {
    glClearColor(color.x, color.y, color.z, color.w);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}