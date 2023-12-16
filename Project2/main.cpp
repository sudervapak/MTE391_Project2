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
            Vertex(glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(0.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)),
            Vertex(glm::vec3(0.5f, -0.5f, 0.0f), glm::vec3(1.0f, 0.0f, 1.0f), glm::vec2(0.0f, 1.0f)),
            Vertex(glm::vec3(0.5f, 0.5f, 0.0f), glm::vec3(1.0f, 1.0f, 0.0f), glm::vec2(0.0f, 0.0f)),
            Vertex(glm::vec3(-0.5f, 0.5f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec2(1.0f, 0.0f)),
    };

    Transform* transform1 = new Transform();
    Transform* transform2 = new Transform();

    SDLManager* sdlManager = new SDLManager();

    ShaderManager* myShader = new ShaderManager("/Users/emirhankilic/Desktop/3.1/mte391/project/MTE391_Project2/Project2/Shaders/default.vert", "/Users/emirhankilic/Desktop/3.1/mte391/project/MTE391_Project2/Project2/Shaders/default.frag");

    BufferManager* rectangleBuffer1 = new BufferManager(vertices1, 4);
    BufferManager* rectangleBuffer2 = new BufferManager(vertices2, 4);

    TextureManager* textureManager1 = new TextureManager();
    textureManager1->loadTexture("/Users/emirhankilic/Desktop/3.1/mte391/project/MTE391_Project2/Project2/Shaders/cat.jpg");  // Replace with the actual path to the first texture
    textureManager1->bindTexture(0);

    TextureManager* textureManager2 = new TextureManager();
    textureManager2->loadTexture("/Users/emirhankilic/Desktop/3.1/mte391/project/MTE391_Project2/Project2/Shaders/cat2.jpg");  // Replace with the actual path to the second texture
    textureManager2->bindTexture(1);

    // Main loop
    float speed = 0.01f; // Movement speed
    bool running = true;
    while (running) {
        sdlManager->handleEvents(&running, transform1);

        // Clear the screen
        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw the first rectangle
        GLint modelLoc = glGetUniformLocation(myShader->getProgramId(), "model");
        glm::mat4 model1 = transform1->GetModelMatrix();
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model1));
        textureManager1->bindTexture(0);
        rectangleBuffer1->BindVAO();
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
        glBindVertexArray(0);

        // Draw the second rectangle
        modelLoc = glGetUniformLocation(myShader->getProgramId(), "model");
        glm::mat4 model2 = transform2->GetModelMatrix();
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model2));
        textureManager2->bindTexture(0);
        rectangleBuffer2->BindVAO();
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
        glBindVertexArray(0);

        // Swap buffers
        sdlManager->swap();
    }

    // Clean up
    delete myShader;
    delete rectangleBuffer1;
    delete rectangleBuffer2;
    delete sdlManager;

    return 0;
}
