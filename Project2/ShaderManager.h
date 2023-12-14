#pragma once
#include <SDL.h>
#include <GL/glew.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>
#include <stdexcept>

std::string get_file_contents(const char* filename);

class ShaderManager
{
private:
    GLuint shaderProgram;
    GLuint vertexShader;
    GLuint fragmentShader;

public:
    ShaderManager(const char* vertexFile , const char* fragmentFile);

    void run();

    ~ShaderManager();

    GLuint getProgramId();
};

