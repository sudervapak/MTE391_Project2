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

