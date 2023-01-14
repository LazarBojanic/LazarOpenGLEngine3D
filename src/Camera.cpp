#include "Camera.hpp"

Camera::Camera(glm::vec3 position, float width, float height, float nearPlane, float farPlane) {
    this->position = position;
    this->worldUp = glm::vec3(0.0f, 1.0f, 0.0f);
    this->yaw = -90.0f;
    this->pitch = 0.0f;
    this->front = glm::vec3(0.0f, 0.0f, -1.0f);
    this->movementSpeed = 10.0f;
    this->mouseSensitivity = 0.5f;
    this->zoom = 45.0f;
    this->projection = glm::perspective(glm::radians(this->zoom), width / height, nearPlane, farPlane);
    this->updateView();
}
Camera::Camera(float positionX, float positionY, float positionZ, float width, float height, float nearPlane, float farPlane) {
    this->position = glm::vec3(positionX, positionY, positionZ);
    this->worldUp = glm::vec3(0.0f, 1.0f, 0.0f);
    this->yaw = -90.0f;
    this->pitch = 0.0f;
    this->front = glm::vec3(0.0f, 0.0f, -1.0f);
    this->movementSpeed = 10.0f;
    this->mouseSensitivity = 0.5f;
    this->zoom = 45.0f;
    this->projection = glm::perspective(glm::radians(this->zoom), width / height, nearPlane, farPlane);
    this->updateView();
}
Camera::~Camera(){
}
void Camera::processMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch, GLFWwindow* window, float width, float height) {
    xoffset *= this->mouseSensitivity;
    yoffset *= this->mouseSensitivity;
    this->yaw += xoffset;
    this->pitch += yoffset;
    if (constrainPitch) {
        if (this->pitch > 89.0f) {
            this->pitch = 89.0f;
        }
        if (this->pitch < -89.0f) {
            this->pitch = -89.0f;
        }
    }
    updateView();
    double currentCursorX;
    double currentCursorY;
    glfwGetCursorPos(window, &currentCursorX, &currentCursorY);
    if (currentCursorX >= width - 20.0f) {
        glfwSetCursorPos(window, width - 20.0f, currentCursorY);
    }
    if (currentCursorX <= 20.0f) {
        glfwSetCursorPos(window, 20.0f, currentCursorY);
    }
    if (currentCursorY >= height - 20.0f) {
        glfwSetCursorPos(window, currentCursorX, height - 20.0f);
    }
    if (currentCursorY <= 20.0f) {
        glfwSetCursorPos(window, currentCursorX, 20.0f);
    }
}
void Camera::updateView() {
    glm::vec3 front;
    front.x = cos(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
    front.y = sin(glm::radians(this->pitch));
    front.z = sin(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
    this->front = glm::normalize(front);
    this->right = glm::normalize(glm::cross(this->front, this->worldUp));
    this->up = glm::normalize(glm::cross(this->right, this->front));
    this->view = glm::lookAt(this->position, this->position + this->front, this->up);
}
void Camera::processKeyboard(CameraMovement direction, float deltaTime){
    float velocity = this->movementSpeed * deltaTime;
    if (direction == FORWARD) {
        this->position += this->front * velocity;
    }       
    if (direction == BACKWARD) {
        this->position -= this->front * velocity;
    }       
    if (direction == LEFT) {
        this->position -= this->right * velocity;
    }       
    if (direction == RIGHT) {
        this->position += this->right * velocity;
    }
    updateView();
}
void Camera::processMouseScroll(float yoffset){
    this->zoom -= (float)yoffset;
    if (this->zoom < 1.0f) {
        this->zoom = 1.0f;
    }      
    if (this->zoom > 45.0f) {
        this->zoom = 45.0f;
    }
    updateView();
}