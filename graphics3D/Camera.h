#pragma once

#include "Gizmos.h"
#include <glm/glm.hpp>
#include <glm/ext.hpp>

class Camera
{
public:
   Camera();
   ~Camera();

public:
   virtual void update(float deltaTime) = 0;
   virtual void draw();

   void setPerspective(float FOV, float aspectRatio, float near = 0.1f, float far = 1000.f);
   void setLookAt(glm::vec3 from, glm::vec3 to, glm::vec3 up = { 0,1,0 });
   void setPosition(glm::vec3 position);

   glm::mat4 getProjectionView();

protected:
   glm::vec3 m_position; // location of the camera in worldspace
   glm::vec3 m_direction; // directional normal indicating 

   // camera transforms
   glm::mat4 m_viewMatrix;
   glm::mat4 m_projectionMatrix;
   glm::mat4 m_projectionView;


   void updateProjectionView();
};