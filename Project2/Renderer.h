/*Renderer class provides an interface between the Renderer, ShaderManager, TextureManager and BufferManager classes and integrates these components, giving the ability to display a simple graphics scene.
 The Renderer class is used in the project to render objects using predefined shaders, add textures, and provide simple camera controls.*/

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
