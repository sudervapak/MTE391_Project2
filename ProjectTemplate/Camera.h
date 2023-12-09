#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>

// Camera class handles the camera's position and projection in the scene.
class Camera {
public:
    Camera();

    // Sets the camera's position in the scene.
    void SetPosition(const glm::vec3& position);

    // Sets the camera's projection parameters.
    void SetProjection(float fov, float aspectRatio, float nearPlane, float farPlane);

    // Gets the camera's view matrix for rendering.
    glm::mat4 GetViewMatrix() const;

    // Gets the camera's projection matrix.
    glm::mat4 GetProjectionMatrix() const;

private:
    glm::vec3 position; // The position of the camera in the scene.
    glm::mat4 viewMatrix; // The view matrix representing the camera's orientation.
    glm::mat4 projectionMatrix; // The projection matrix representing the camera's lens.
};

#endif // CAMERA_H
