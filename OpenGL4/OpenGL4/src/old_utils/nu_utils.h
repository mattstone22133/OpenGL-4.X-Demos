#pragma once
#include<glad/glad.h> //include opengl headers, so should be before anything that uses those headers (such as GLFW)
#include<GLFW/glfw3.h>
#include <stb_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void verifyShaderCompiled(const char* shadername, GLuint shader);

void verifyShaderLink(GLuint shaderProgram);

GLFWwindow* init_window(int width, int height);
GLFWwindow* init_window_4_6(int width, int height);

GLuint textureLoader(const char* relative_filepath, int texture_unit = -1, bool useGammaCorrection = false);