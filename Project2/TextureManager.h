/*TextureManager class provides a convenient interface for loading textures.
The constructor initializes the manager, the destructor cleans up resources, loadTexture loads a texture from a file, and bindTexture binds the texture to a specified texture unit.
We used TextureManeger class to provide interface for loading pictures in program. */

#pragma once
#include <GL/glew.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class TextureManager {
public:
    TextureManager();// Constructor to initialize the TextureManager
    ~TextureManager();// Destructor

    GLuint loadTexture(const std::string& filePath);// Load a texture from a file and return its OpenGL texture ID

    void bindTexture(GLuint textureUnit);// Bind the texture to a specific texture unit

private:
    GLuint textureID;// OpenGL texture ID
};


