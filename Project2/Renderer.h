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
    Renderer();
    ~Renderer();

    void init();
    void render(Transform* transform, BufferManager* buffer, TextureManager* textureManager);

private:
    ShaderManager* shader;
};

#endif // RENDERER_H
