#include "Renderer.h"

Renderer::Renderer() {
    // Constructor
}

Renderer::~Renderer() {
    // Destructor
}

void Renderer::init() {
    // Initialize GLEW or any other initialization logic
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        exit(EXIT_FAILURE);
    }


    // Create and link shaders, set up any other OpenGL configurations
    /*shader = new ShaderManager("/Users/emirhankilic/Desktop/3.1/mte391/project/MTE391_Project2/Project2/Shaders/default.vert",
                               "/Users/emirhankilic/Desktop/3.1/mte391/project/MTE391_Project2/Project2/Shaders/default.frag"); */ //this for macOS

    shader = new ShaderManager("./Shaders/default.vert",
                               "./Shaders/default.frag");   //this is for windows
}

void Renderer::render(Transform* transform, BufferManager* buffer, TextureManager* textureManager) {
    // Set up shader and other OpenGL configurations
    shader->run();

    // Set model matrix
    GLint modelLoc = glGetUniformLocation(shader->getProgramId(), "model");
    glm::mat4 model = transform->GetModelMatrix();
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

    // Bind texture
    textureManager->bindTexture(0);

    // Bind VAO and draw
    buffer->BindVAO();
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    glBindVertexArray(0);
}

