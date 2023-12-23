/* The SDLManager class manages the setup and operation of an SDL window.
 In its constructor, it handles the initialization of SDL, sets up OpenGL attributes, creates an SDL window, and initializes GLEW.
 The destructor is responsible for cleaning up resources, such as the OpenGL context and SDL window.
 The handleEvents method is used to process SDL events, like quitting events and key presses, updating related Transform objects.
 Lastly, the swap method is in charge of swapping the front and back buffers for smooth rendering in a double-buffered setup.
 Essentially, this class streamlines the SDL and OpenGL integration, making it easier to manage windows and events in an OpenGL-based application.
 */

#pragma once
#include <SDL.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <iostream>
#include "Transform.h"


class SDLManager
{
	public:
		SDLManager();//initial Setup
		~SDLManager();//final wrap up
		void handleEvents(bool* running,Transform * transform, Transform* transform1);// keyboard input etc
		SDL_Window* getWindow(); //creating window
		void swap();
	private:
		SDL_Window* window;
		SDL_GLContext context;

};


