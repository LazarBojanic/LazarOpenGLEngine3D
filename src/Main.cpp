#include "Application.hpp"

int main() {
	Application* application = new Application(1280, 720);
	application->run();
	return 0;
}