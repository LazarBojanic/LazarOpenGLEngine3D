#include "Application.hpp"

int main() {
	Application* application = new Application(800, 640);
	application->run();
	return 0;
}