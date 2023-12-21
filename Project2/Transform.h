
#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <SDL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Transform {
public:
    // Constructor with default values for position, rotation, and scale
    Transform(const glm::vec3& position = glm::vec3(0.0f),
        const glm::vec3& rotation = glm::vec3(0.0f),
        const glm::vec3& scale = glm::vec3(1.0f));
// Functions to handle key input for translation, rotation, and scaling
    void HandleKeyInput(SDL_Keycode key);
    void HandleKeyInput1(SDL_Keycode key);


    const glm::mat4 GetModelMatrix() ;// Function to get the model matrix for rendering

private:
    // Functions for internal use to perform translation, rotation, and scaling
    void Translate(const glm::vec3& delta);
    void Rotate(float angle, const glm::vec3& axis);
    void Scale(const glm::vec3& delta);
// Member variables representing position, rotation, scale, model matrix, and update flag
    glm::vec3 position;
    glm::vec3 rotation; // Stored as Euler angles
    glm::vec3 scale;
    glm::mat4 model;
    bool needsUpdate;

    void UpdateModelMatrix() ;// Function to update the model matrix based on position, rotation, and scale
};

#endif // TRANSFORM_H
