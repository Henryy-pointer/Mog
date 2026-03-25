#include "renderer.h"
#include <math.h>

//Get final rotation matrix from a vector
Matrix4x4 get_rotation_matrix(Vec4 *rotation){
  Matrix4x4 Rx = (Matrix4x4){
    .matrix = {
      {1, 0, 0, 0},
      {0, cos(rotation->x), -sin(rotation->x), 0},
      {0, sin(rotation->x), cos(rotation->x), 0},
      {0, 0, 0, 1},
    }
  };

  Matrix4x4 Ry = (Matrix4x4){
    .matrix = {
      {cos(rotation->y), 0, sin(rotation->y), 0},
      {0, 1, 0, 0},
      {-sin(rotation->y), 0, cos(rotation->y), 0},
      {0,0,0,1},
    }
  };
  Matrix4x4 Rz = (Matrix4x4){
    .matrix = {
      {cos(rotation->z), -sin(rotation->z), 0, 0},
      {sin(rotation->z), cos(rotation->z), 0, 0},
      {0, 0, 1, 0},
      {0, 0, 0, 1},
    }
  };
  Matrix4x4 tmp = matrix_multiplication(&Rz, &Ry);
  Matrix4x4 result = matrix_multiplication(&tmp, &Rx);
  return result;
}
//functions that apply transforms to models with matrices, the point is to combine scale, rotation and translation into one matrix
Matrix4x4 transform(Vec4 *scale, Vec4 *rotation, Vec4 *position){

  Matrix4x4 scaleMatrix = (Matrix4x4){
    .matrix = {
      {scale->x, 0, 0, 0},
      {0, scale->y, 0, 0},
      {0, 0, scale->z, 0},
      {0, 0, 0, 1},
    }
  };

  Matrix4x4 rotationMatrix = get_rotation_matrix(rotation);
  Matrix4x4 translateMatrix = (Matrix4x4){
      .matrix = {
        {1, 0, 0, position->x},
        {0, 1, 0, position->y},
        {0, 0, 1, position->z},
        {0, 0, 0, 1},
      }
    };
  
  Matrix4x4 transform_x_rotation = matrix_multiplication(&translateMatrix, &rotationMatrix);
  Matrix4x4 result = matrix_multiplication(&transform_x_rotation, &scaleMatrix);
  return result;
}
