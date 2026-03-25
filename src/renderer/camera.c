#include "renderer.h"

Matrix4x4 lookAt(Camera *cam){
  Matrix4x4 result;
  Vec4 forward = vec_normalize(vec_subtraction(&cam->target, &cam->pos));
  Vec4 right = vec_cross_product(&cam->up, &forward);
  Vec4 up = vec_cross_product(&forward,&right);
  result = (Matrix4x4){
    .matrix= {
      {right.x, right.y, right.z, -vec_dot_product(&right,&cam->pos)},
      {up.x, up.y, up.z, -vec_dot_product(&up,&cam->pos)},
      {forward.x, forward.y, forward.z,-vec_dot_product(&forward, &cam->pos)},
      {0,0,0,1},
    }
  };
  return result;
}
