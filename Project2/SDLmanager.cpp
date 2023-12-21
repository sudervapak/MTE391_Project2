#define _CRT_SECURE_NO_WARNINGS

#include "SDLManager.h"

SDLManager::SDLManager() {


    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;

    }

    // Set OpenGL attributes
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    // Create a window
    window = SDL_CreateWindow("PROJECT2", 100, 100,1200, 800, SDL_WINDOW_OPENGL);
    if (window == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();

    }

    // Create OpenGL context
    context = SDL_GL_CreateContext(window);
    if (context == nullptr) {
        std::cerr << "SDL_GL_CreateContext Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();

    }

    // Initialize GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "glewInit Error" << std::endl;
        SDL_GL_DeleteContext(context);
        SDL_DestroyWindow(window);
        SDL_Quit();

    }

}
SDLManager::~SDLManager() {
    
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();

}
// Get the SDL window
SDL_Window*  SDLManager:: getWindow(){

    return window;

}
// Handle SDL events, such as quitting the application or handling key inputs for transformations
void SDLManager::handleEvents(bool * running, Transform* transform, Transform* transform1) {

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            *running = false;
        }
        if (event.type == SDL_KEYDOWN) {
            transform->HandleKeyInput(event.key.keysym.sym);
            transform1->HandleKeyInput1(event.key.keysym.sym);
        }
    }



}

void SDLManager::swap() {

    SDL_GL_SwapWindow(window);// Swap the front and back buffers to update the window display
 }