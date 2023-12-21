#include "Transform.h"
#include <iostream>

// Constructor for Transform class, initializes position, rotation, scale, model matrix, and update flag
Transform::Transform(const glm::vec3& position,
    const glm::vec3& rotation,
    const glm::vec3& scale) :
    position(position),
    rotation(rotation),
    scale(scale),
    model(glm::mat4(1.0f)),
    needsUpdate(true) {
}

// Handle key input for translation operations for  first object
void Transform::HandleKeyInput(SDL_Keycode key) {
    switch (key) {
    case SDLK_UP:
        Translate(glm::vec3(0.0f, 0.1f, 0.0f));
        break;
    case SDLK_DOWN:
        Translate(glm::vec3(0.0f, -0.1f, -0.0f));
        break;
    case SDLK_LEFT:
        Translate(glm::vec3(-0.1f, 0.0f, 0.0f));
        break;
    case SDLK_RIGHT:
        Translate(glm::vec3(0.1f, 0.0f, 0.0f));
        break;
    case SDLK_t:
        Rotate(glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        break;
    case SDLK_y:
        Rotate(glm::radians(-45.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        break;
    case SDLK_u:
        Rotate(glm::radians(45.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        break;
    case SDLK_i:
        Rotate(glm::radians(-45.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        break;
    case SDLK_o:
        Rotate(glm::radians(45.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        break;
    case SDLK_p:
        Rotate(glm::radians(-45.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        break;

        case SDLK_z:
            Scale(glm::vec3(0.1f, 0.1f, 0.1f));
            break;
        case SDLK_x:
            Scale(glm::vec3(-0.1f, -0.1f, -0.1f));
            break;


    }
}

// Handle key input for translation operations for  second object
void Transform::HandleKeyInput1(SDL_Keycode key) {
    switch (key) {
        case SDLK_w:
            Translate(glm::vec3(0.0f, 0.1f, 0.0f));
            break;
        case SDLK_s:
            Translate(glm::vec3(0.0f, -0.1f, -0.0f));
            break;
        case SDLK_a:
            Translate(glm::vec3(-0.1f, 0.0f, 0.0f));
            break;
        case SDLK_d:
            Translate(glm::vec3(0.1f, 0.0f, 0.0f));
            break;

    }
}
// Translate the object by a specified delta vector
void Transform::Translate(const glm::vec3& delta) {
    
    position += delta;
    needsUpdate= true;
}
// Rotate the object by a specified angle around a specified axis
void Transform::Rotate(float angle, const glm::vec3& axis) {
    
    if (axis.x > 0.0f) rotation.x += angle;
    if (axis.y > 0.0f) rotation.y += angle;
    if (axis.z > 0.0f) rotation.z += angle;
    needsUpdate = true;
}
// Scale the object by a specified delta vector
void Transform::Scale(const glm::vec3& delta) {
	scale += delta;
	needsUpdate = true;
}
// Update the model matrix based on position, rotation, and scale
void Transform::UpdateModelMatrix()  {
    
    model = glm::mat4(1.0f);
    model = glm::translate(model, position);
    model = glm::rotate(model, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::scale(model, scale);
    needsUpdate = false;
}
// Get the model matrix for rendering
const glm::mat4 Transform::GetModelMatrix()  {
    if (needsUpdate) {
		UpdateModelMatrix();
	}

    return model;
}
