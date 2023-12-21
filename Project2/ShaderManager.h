#pragma once
#include <SDL.h>
#include <GL/glew.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>
#include <stdexcept>

std::string get_file_contents(const char* filename); // Function to read the contents of a file and return them as a string

class ShaderManager
{
private:
    GLuint shaderProgram;// Shader program ID
    GLuint vertexShader;// Vertex shader ID
    GLuint fragmentShader;// Fragment shader ID

public:
    ShaderManager(const char* vertexFile , const char* fragmentFile);// Constructor that takes file paths for vertex and fragment shaders

    void run();// Function to activate the shader program for rendering

    ~ShaderManager();

    GLuint getProgramId();// Function to get the ID of the shader program
};

