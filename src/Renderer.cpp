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

void Renderer::draw(GameObject& gameObject, Camera& camera, float width, float height, bool scaled, bool indexed, bool textured){
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
    glm::mat4 view = camera.getViewMatrix();

    glm::mat4 projection = glm::perspective(glm::radians(camera.getZoom()), width / height, 0.1f, 100.0f);

    gameObject.getDrawData()->getMesh()->getVertexArray()->bind();
    if (textured) {
        gameObject.getDrawData()->getShader()->setInt("uMaterial.diffuse", 0, true);
        gameObject.getDrawData()->getTexture()->bind(0);
    }
    gameObject.getDrawData()->getShader()->setMatrix4f("uModel", model, true);
    gameObject.getDrawData()->getShader()->setMatrix4f("uView", view, true);
    gameObject.getDrawData()->getShader()->setMatrix4f("uProjection", projection, true);
    if (indexed) {
        glDrawElements(GL_TRIANGLES, gameObject.getDrawData()->getMesh()->getPrimitive()->getIndicesCount(), GL_UNSIGNED_INT, 0);
    }
    else {
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }
    gameObject.getDrawData()->getMesh()->getVertexArray()->unbind();

}

void Renderer::colorBackground(glm::vec4 color) {
    glClearColor(color.x, color.y, color.z, color.w);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}