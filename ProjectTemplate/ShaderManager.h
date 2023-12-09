#ifndef SHADERMANAGER_H
#define SHADERMANAGER_H

#include <string>
#include <GL/glew.h>

// ShaderManager class handles the loading, compiling, and using of shaders.
class ShaderManager {
public:
    // Loads and compiles a shader from file paths for vertex and fragment shaders.
    GLuint LoadShader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);

    // Uses a shader program for rendering.
    void UseShader(GLuint shaderProgram);

    // Deletes a shader program to free resources.
    void DeleteShader(GLuint shaderProgram);
};

#endif // SHADERMANAGER_H
