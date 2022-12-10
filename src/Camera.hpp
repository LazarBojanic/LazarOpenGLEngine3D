#pragma once

#include "GLData.hpp"

enum CameraMovement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

class Camera {
private:
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;
    glm::vec3 right;
    glm::vec3 worldUp;
    float yaw;
    float pitch;
    float movementSpeed;
    float mouseSensitivity;
    float zoom;
public:
    Camera(glm::vec3 position);
    Camera(float positionX, float positionY, float positionZ);
    ~Camera();
    void processMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch, GLFWwindow* window, float width, float height);
    void updateCameraVectors();
    void processKeyboard(CameraMovement direction, float deltaTime);
    void processMouseScroll(float yoffset);
    inline glm::mat4 getViewMatrix(){
        return glm::lookAt(this->position, this->position + this->front, this->up);
    }
    inline glm::vec3 getPosition() {
        return this->position;
    }
    inline glm::vec3 getFront() {
        return this->front;
    }
    inline glm::vec3 getUp() {
        return this->up;
    }
    inline glm::vec3 getRight() {
        return this->right;
    }
    inline glm::vec3 getWorldUp() {
        return this->worldUp;
    }
    inline float getYaw() {
        return this->yaw;
    }
    inline float getPitch() {
        return this->pitch;
    }
    inline float getMovementSpeed() {
        return this->movementSpeed;
    }
    inline float getMouseSensitivity() {
        return this->mouseSensitivity;
    }
    inline float getZoom() {
        return this->zoom;
    }
};