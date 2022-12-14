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
    glm::mat4 model;
    glm::mat4 view;
    glm::mat4 projection;
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
    Camera(glm::vec3 position, float width, float height, float nearPlane, float farPlane);
    Camera(float positionX, float positionY, float positionZ, float width, float height, float nearPlane, float farPlane);
    ~Camera();
    void processMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch, GLFWwindow* window, float width, float height);
    void updateView();
    void processKeyboard(CameraMovement direction, float deltaTime);
    void processMouseScroll(float yoffset);
    inline glm::mat4 getModel() {
        return this->model;
    }
    inline glm::mat4 getView(){
        return this->view;
    }
    inline glm::mat4 getProjection() {
        return this->projection;
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