#pragma once

#include "GLData.hpp"
#include "ResourceManager.hpp"
#include "GameObjectManager.hpp"
#include "Renderer.hpp"
#include "Triangle.hpp"
#include "Quad.hpp"
#include "Cube.hpp"
#include "SkyboxPrimitive.hpp"
#include "Camera.hpp"
#include <FastNoise/FastNoise.h>
#define FASTNOISE_USE_SHARED_PTR 1
class Game {  
private:
    Game(GLFWwindow* window, unsigned int width, unsigned int height);
    ~Game();

    std::string workingDirectory;
    GLFWwindow* window;
    irrklang::ISoundEngine* soundEngine;
    std::string windowTitle;
    static Game* instance;
    bool* keys;
    int keysSize = 1024;
    unsigned int width, height;
    Camera* camera;
    float lastX, lastY;
    bool firstMouse;
    float t;
    
    
public:
    
    static Game* getInstance(GLFWwindow* window, unsigned int width, unsigned int height);
    static Game* getInstance();
    void updateWindowSize(int width, int height);
    void initKeys();
    void initVariables();
    void initResources();
    void start();
    void processInput(float dt);
    void update(float dt);
    void render(float dt);
    void clear();

    inline GLFWwindow* getWindow() {
        return this->window;
    }

    inline float getLastX() {
        return this->lastX;
    }
    inline float getLastY() {
        return this->lastY;
    }
    inline bool getFirstMouse() {
        return this->firstMouse;
    }
    inline bool* getKeys() {
        return this->keys;
    }
    inline unsigned int getWidth() {
        return this->width;
    }
    inline unsigned int getHeight() {
        return this->height;
    }
    inline Camera* getCamera() {
        return this->camera;
    }

    inline void setLastX(float lastX) {
        this->lastX = lastX;
    }
    inline void setLastY(float lastY) {
        this->lastY = lastY;
    }
    inline void setFirstMouse(bool firstMouse) {
        this->firstMouse = firstMouse;
    }
    inline void setWidth(float width) {
        this->width = width;
    }
    inline void setHeight(float height) {
        this->height = height;
    }
};