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

void Renderer::draw(GameObject3D& gameObject3D, Camera& camera, float width, float height, bool scaled, bool indexed, bool textured){
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
    if (textured) {
        gameObject3D.getDrawData()->getTexture2D()->bind(0);
    }
    gameObject3D.getDrawData()->getShader()->setMatrix4f("uModel", model, true);
    gameObject3D.getDrawData()->getShader()->setMatrix4f("uView", view, true);
    gameObject3D.getDrawData()->getShader()->setMatrix4f("uProjection", projection, true);
    if (indexed) {
        glDrawElements(GL_TRIANGLES, gameObject3D.getDrawData()->getMesh()->getPrimitive()->getIndicesCount(), GL_UNSIGNED_INT, 0);
    }
    else {
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }
    gameObject3D.getDrawData()->getMesh()->getVertexArray()->unbind();

}

void Renderer::colorBackground(glm::vec4 color) {
    glClearColor(color.x, color.y, color.z, color.w);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}