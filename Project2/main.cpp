#include <SDL.h>
#include <GL/glew.h>
#include <iostream>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "ShaderManager.h"
#include "BufferManager.h"
#include "Vertex.h"
#include "SDLmanager.h"
#include "Transform.h"
#include <glm/gtc/type_ptr.hpp>
#include <SDL_image.h>
#include "TextureManager.h"
#include "Renderer.h"

int main(int argc, char* argv[]) {
    // First Rectangle
    Vertex vertices1[] = {
            Vertex(glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 1.0f)),
            Vertex(glm::vec3(0.5f, -0.5f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.0f, 1.0f)),
            Vertex(glm::vec3(0.5f, 0.5f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 0.0f)),
            Vertex(glm::vec3(-0.5f, 0.5f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)),
    };

    // Second Rectangle
    Vertex vertices2[] = {
            Vertex(glm::vec3(-0.25f, -0.25f, 0.0f), glm::vec3(0.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)),
            Vertex(glm::vec3(0.25f, -0.25f, 0.0f), glm::vec3(1.0f, 0.0f, 1.0f), glm::vec2(0.0f, 1.0f)),
            Vertex(glm::vec3(0.25f, 0.25f, 0.0f), glm::vec3(1.0f, 1.0f, 0.0f), glm::vec2(0.0f, 0.0f)),
            Vertex(glm::vec3(-0.25f, 0.25f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec2(1.0f, 0.0f)),
    };

    Transform* transform1 = new Transform();
    Transform* transform2 = new Transform();

    SDLManager* sdlManager = new SDLManager();

    BufferManager* rectangleBuffer1 = new BufferManager(vertices1, 4);
    BufferManager* rectangleBuffer2 = new BufferManager(vertices2, 4);

    TextureManager* textureManager1 = new TextureManager();
    textureManager1->loadTexture("./Shaders/cat.jpg");
    //textureManager1->loadTexture("/Users/emirhankilic/Desktop/3.1/mte391/project/MTE391_Project2/Project2/Shaders/cat.jpg");// Replace with the actual path to the first texture
    textureManager1->bindTexture(0);

    TextureManager* textureManager2 = new TextureManager();
    //textureManager2->loadTexture("/Users/emirhankilic/Desktop/3.1/mte391/project/MTE391_Project2/Project2/Shaders/cat2.jpg");  // Replace with the actual path to the second texture
    textureManager2->loadTexture("./Shaders/cat2.jpg");
    textureManager2->bindTexture(1);

    // Create a renderer instance and initialize it
    Renderer* renderer = new Renderer();
    renderer->init();

    // Main loop
    float speed = 0.01f; // Movement speed
    bool running = true;
    while (running) {
        sdlManager->handleEvents(&running, transform1, transform2);

        // Clear the screen
        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw the first rectangle using the renderer
        renderer->render(transform1, rectangleBuffer1, textureManager1);

        // Draw the second rectangle using the renderer
        renderer->render(transform2, rectangleBuffer2, textureManager2);

        // Swap buffers
        sdlManager->swap();
    }

    // Clean up
    delete renderer;

    return 0;
}
