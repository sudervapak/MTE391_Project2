#include <SDL.h>
#include <GL/glew.h>
#include "Renderer.h"
#include "ShaderManager.h"
#include "TextureManager.h"
#include "Camera.h"

int main(int argc, char* argv[]) {
    // Initialize SDL with video (and optionally other subsystems)
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    // Create an SDL window
    SDL_Window* window = SDL_CreateWindow("OpenGL Game",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800, 600,
        SDL_WINDOW_OPENGL);

    if (!window) {
        SDL_Log("Unable to create window: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Initialize Renderer
    Renderer renderer;
    renderer.Initialize(window);

    // Initialize other components like ShaderManager, TextureManager, Camera
    ShaderManager shaderManager;
    TextureManager textureManager;
    Camera camera;

    // Main game loop
    bool running = true;
    SDL_Event event;
    while (running) {
        // Event handling
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        // Update game logic here (e.g., camera updates)

        // Rendering
        renderer.RenderFrame();

        // Swap the window buffers (double buffering)
        SDL_GL_SwapWindow(window);
    }

    // Cleanup
    renderer.Cleanup();
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
