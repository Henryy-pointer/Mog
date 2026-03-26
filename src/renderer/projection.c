#include "renderer.h"
#include <math.h>

Matrix4x4 get_projection_matrix(Camera *camera){
  float aspect = (float)WIDTH/(float)HEIGHT;
  float focal_lenght = 1/tan(camera->FOV/2);
  float Znear = /*vec->z * */ camera->near;
  float Zfar = /*vec->z * */ camera->far;

  /*Matrix4x4 projection_matrix = (Matrix4x4){
    .matrix = {
      {focal_lenght * aspect, 0, 0, 0},
      {0, focal_lenght, 0, 0},
      {0, 0, Zfar / (Zfar - Znear), 1},
      {0, 0, -Zfar * Znear / (Zfar - Znear), 0},
    }
  };*/

  Matrix4x4 projection_matrix = (Matrix4x4){
    .matrix = {
      {focal_lenght / aspect, 0, 0, 0},
      {0, focal_lenght, 0, 0},
      {0, 0, Zfar / (Zfar - Znear), (-Zfar * Znear) / (Zfar - Znear)},
      {0, 0, 1, 0},
    }
  };

  return projection_matrix;
}
