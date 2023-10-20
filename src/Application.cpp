#include "Application.hpp"

Application::Application(unsigned int width, unsigned int height) {
    this->width = width;
    this->height = height;

    initWindow();
}
Application::~Application() {
    
}

void Application::initGlfw() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
}
void Application::initGlad() {
    gladLoadGL();
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
    Game::getInstance()->updateWindowSize(width, height);
}
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
    if (key >= 0 && key < 1024) {
        if (action == GLFW_PRESS) {
            Game::getInstance()->getKeys()[key] = true;
        }
        else if (action == GLFW_RELEASE) {
            Game::getInstance()->getKeys()[key] = false;
        }
    }
}
void mouse_callback(GLFWwindow* window, double xposIn, double yposIn) {
    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);

    if (Game::getInstance()->getFirstMouse()) {
        Game::getInstance()->setLastX(xpos);
        Game::getInstance()->setLastY(ypos);
        Game::getInstance()->setFirstMouse(false);
    }

    float xoffset = xpos - Game::getInstance()->getLastX();
    float yoffset = Game::getInstance()->getLastY() - ypos;

    Game::getInstance()->setLastX(xpos);
    Game::getInstance()->setLastY(ypos);

    Game::getInstance()->getCamera()->processMouseMovement(xoffset, yoffset, false, Game::getInstance()->getWindow(), Game::getInstance()->getWidth(), Game::getInstance()->getHeight());
}


void scroll_callback(GLFWwindow* window, double xoffset, double yoffset){
    Game::getInstance()->getCamera()->processMouseScroll(static_cast<float>(yoffset));
}
void GLAPIENTRY debugCallback(
    GLenum source,
    GLenum type,
    GLuint id,
    GLenum severity,
    GLsizei length,
    const GLchar* message,
    const void* userParam){
    std::cout << "GL CALLBACK-> Type: " << Util::getDebugMeaning(type) << ", Severity: " << Util::getDebugMeaning(severity) << ", Message: " << message << std::endl;
}
void Application::initWindow() {
    initGlfw();
    this->window = glfwCreateWindow(this->width, this->height, "3D Game", NULL, NULL);
    if (this->window == NULL) {
        std::cout << "Failed to create GLFW window." << std::endl;
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(this->window);
    initGlad();
    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(debugCallback, 0);
    glfwSetKeyCallback(this->window, key_callback);
    glfwSetFramebufferSizeCallback(this->window, framebuffer_size_callback);
    glfwSetCursorPosCallback(this->window, mouse_callback);
    glfwSetScrollCallback(this->window, scroll_callback);
    glfwSwapInterval(1);
    glfwSetWindowPos(this->window, 200, 200);
    glfwSetInputMode(this->window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void Application::run() {
    Game::getInstance(this->window, this->width, this->height)->start();
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;
    while (!glfwWindowShouldClose(this->window)){
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        
        Game::getInstance()->processInput(deltaTime);

        Game::getInstance()->update(deltaTime);

        Game::getInstance()->render(deltaTime);

        glfwPollEvents();
        glfwSwapBuffers(this->window);
    }
    ResourceManager::getInstance()->clear(false);
    GameObjectManager::getInstance()->clear(false);
    Game::getInstance()->clear();
    glfwTerminate();
}