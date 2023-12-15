#pragma once
#include <GL/glew.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class TextureManager {
public:
    TextureManager();
    ~TextureManager();

    GLuint loadTexture(const std::string& filePath);

    void bindTexture(GLuint textureUnit);

private:
    GLuint textureID;
};


