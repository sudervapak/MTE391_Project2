/*In this project, the `Transform` class is used to manage the position, rotation and scale of the objects in the project in their coordinates in the window.
 It is used to determine the position of an object in the scene, rotate it and size it. This class creates the model matrix of an object and determines the object's location in the scene.
 This class allows animation and user interaction by updating the positions of objects. It also allows objects to dynamically move, rotate or change size by reacting to keyboard input from the user.
 Shortly, this  class is used to regulate the movement and appearance of objects in the scene and simplifies the process of locating objects in the scene  in a basic graphics application.
 */

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
