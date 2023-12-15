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


    Vertex vertices[] = {
            Vertex(glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 1.0f)),
            Vertex(glm::vec3(0.5f, -0.5f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.0f, 1.0f)),
            Vertex(glm::vec3(0.5f, 0.5f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 0.0f)),
            Vertex(glm::vec3(-0.5f, 0.5f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)),
    };

    Transform* transform = new Transform();

    SDLManager* sdlManager = new SDLManager();



    // Create a new shader manager from the heap
    ShaderManager* myShader = new ShaderManager("/Users/emirhankilic/Desktop/3.1/mte391/project/MTE391_Project2/Project2/Shaders/default.vert", "/Users/emirhankilic/Desktop/3.1/mte391/project/MTE391_Project2/Project2/Shaders/default.frag");



    BufferManager* rectangleBuffer = new BufferManager(vertices, 4);

    TextureManager* textureManager = new TextureManager();
    textureManager->loadTexture("/Users/emirhankilic/Desktop/3.1/mte391/project/MTE391_Project2/Project2/Shaders/cat.jpg");
    textureManager->bindTexture(0);

    GLuint tex0Uni = glGetUniformLocation(myShader->getProgramId(), "tex0");
    myShader->run();
    glUniform1i(tex0Uni, 0);


    // Main loop
    glm::vec3 offset = glm::vec3(0.0f, 0.0f, 0.0f);
    float speed = 0.01f; // Movement speed
    bool running = true;
    while (running) {

        sdlManager->handleEvents(&running, transform);

        // Clear the screen
        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw the rectangle
        GLint modelLoc = glGetUniformLocation(myShader->getProgramId(), "model");

        glm::mat4 model = transform->GetModelMatrix();
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

        textureManager->bindTexture(0);


        rectangleBuffer->BindVAO();
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
        glBindVertexArray(0);

        // Swap buffers
        sdlManager->swap();
    }

    // Clean up
    delete myShader;
    delete rectangleBuffer;
    delete sdlManager;

    return 0;
}
