#include "Camera.hpp"

Camera::Camera(glm::vec3 position) {
    this->position = position;
    this->worldUp = glm::vec3(0.0f, 1.0f, 0.0f);
    this->yaw = -90.0f;
    this->pitch = 0.0f;
    this->front = glm::vec3(0.0f, 0.0f, -1.0f);
    this->movementSpeed = 2.5f;
    this->mouseSensitivity = 0.5f;
    this->zoom = 45.0f;
    this->updateCameraVectors();
}
Camera::Camera(float positionX, float positionY, float positionZ) {
    this->position = glm::vec3(positionX, positionY, positionZ);
    this->worldUp = glm::vec3(0.0f, 1.0f, 0.0f);
    this->yaw = -90.0f;
    this->pitch = 0.0f;
    this->front = glm::vec3(0.0f, 0.0f, -1.0f);
    this->movementSpeed = 2.5f;
    this->mouseSensitivity = 0.5f;
    this->zoom = 45.0f;
    this->updateCameraVectors();
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
    updateCameraVectors();
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
void Camera::updateCameraVectors() {
    glm::vec3 front;
    front.x = cos(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
    front.y = sin(glm::radians(this->pitch));
    front.z = sin(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
    this->front = glm::normalize(front);
    this->right = glm::normalize(glm::cross(this->front, this->worldUp));
    this->up = glm::normalize(glm::cross(this->right, this->front));
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
}
void Camera::processMouseScroll(float yoffset){
    this->zoom -= (float)yoffset;
    if (this->zoom < 1.0f) {
        this->zoom = 1.0f;
    }      
    if (this->zoom > 45.0f) {
        this->zoom = 45.0f;
    }  
}