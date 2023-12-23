/*  In the project, the main purpose of the Vertex class is to represent the properties of the vertices of our 2D objects and to include the positions, colors and texture coordinates of these points.
 The Vertex class used in the project provides the basic data structure for creating and rendering 2D graphic objects.
 This class created the graphical side of our project by keeping the properties of the vertices of each object.*/

#pragma once
#include <SDL.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
class Vertex
{
public:
	glm::vec3 position;// Vertex position
	glm::vec3 color;// Color of the vertex
    glm::vec2 texture;// Texture coordinates of the vertex

	Vertex(glm::vec3 pos, glm::vec3 col, glm::vec2 text ) : position(pos), color(col), texture(text){} //vertex object constructor
};

