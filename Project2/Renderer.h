#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include "ShaderManager.h"
#include "BufferManager.h"
#include "TextureManager.h"
#include "Transform.h"
#include <glm/gtc/type_ptr.hpp>

class Renderer {
public:
    Renderer(); // Constructor to initialize the Renderer
    ~Renderer(); // Destructor

    void init();
    void render(Transform* transform, BufferManager* buffer, TextureManager* textureManager); // Render an object with a given transformation, buffer, and texture

private:
    ShaderManager* shader; //shader manager object
};

#endif // RENDERER_H
