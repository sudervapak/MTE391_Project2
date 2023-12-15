#include "TextureManager.h"

TextureManager::TextureManager() {
    glGenTextures(1, &textureID);
}

TextureManager::~TextureManager() {
    glDeleteTextures(1, &textureID);
}

GLuint TextureManager::loadTexture(const std::string& filePath) {
    glBindTexture(GL_TEXTURE_2D, textureID);

    // Load image using SDL_image
    SDL_Surface* surface = IMG_Load(filePath.c_str());
    if (!surface) {
        // Handle error
        std::cerr << "Error loading texture: " << IMG_GetError() << std::endl;
        return 0;
    }

    // Set texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Upload texture data
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface->w, surface->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, surface->pixels);
    glGenerateMipmap(GL_TEXTURE_2D);

    // Clean up
    SDL_FreeSurface(surface);
    glBindTexture(GL_TEXTURE_2D, 0);

    return textureID;
}

void TextureManager::bindTexture(GLuint textureUnit) {
    glActiveTexture(GL_TEXTURE0 + textureUnit);
    glBindTexture(GL_TEXTURE_2D, textureID);
}


