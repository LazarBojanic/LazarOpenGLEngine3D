#pragma once

#define MIN_RAND 100
#define MAX_RAND 256

#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <functional>
#include <array>

#include <windows.h>
#include <filesystem>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <irrKlang/irrKlang.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define PI 3.141592

class GLData {
public:
	static float* copyFloatArray(float* source, unsigned int sourceSize) {
		float* result = new float[sourceSize];
		for (unsigned int i = 0; i < sourceSize; i++) {
			result[i] = source[i];
		}
		return result;
	}
	static unsigned int* copyUnsignedIntArray(unsigned int* source, unsigned int sourceSize) {
		unsigned int* result = new unsigned int[sourceSize];
		for (unsigned int i = 0; i < sourceSize; i++) {
			result[i] = source[i];
		}
		return result;
	}
	static std::string listToString(std::vector<glm::vec2>* list) {
		std::string result = "";
		for (int i = 0; i < list->size(); i++) {
			result += "Enemy X:" + std::to_string(list->at(i).x) + "Enemy Y:" + std::to_string(list->at(i).y) + "\n";
		}
		return result;
	}
};