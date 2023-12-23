/* In this project, the BufferManager class was used to manage the vertex data of the object in OpenGL and to ensure that these data are effectively transmitted to the graphics card during the rendering process.
 In the project, it allows drawing on the screen by keeping the vertex data of 2D objects and transmitting this data to OpenGL.
 BufferManager is used with the Renderer class to optimize the rendering process of objects and organize the vertex data in the graphics card's memory.
 The VAO (Vertex Array Object) and VBO (Vertex Buffer Object) objects it creates store vertex data such as positions, colors and other properties of the objects.
 This class manages the use of Vertex Buffer Object (VBO), a widely used technique in graphics programming, and thus ensures that objects in the project are rendered properly.
 Overall, the BufferManager class ensures that 2D objects are displayed correctly on the screen by organizing and optimizing the transmission of data to OpenGL.*/

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

