#pragma once
#include <SDL.h>
#include <GL/glew.h>
#include "Vertex.h"
class BufferManager
{

private:
	GLuint VAO;
	GLuint VBO;

public:
	BufferManager(Vertex vertices[], GLuint numOfvertices);// Constructor to initialize the BufferManager with an array of vertices and the number of vertices
	~BufferManager();// Destructor to clean up resources when the BufferManager is no longer needed
	void BindVAO(); // Function to bind the Vertex Array Object (VAO)
};

