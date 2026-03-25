#include "renderer.h"

int ndc_to_index(Vec4 *vec){
  int x = (int)((vec->x + 1) * 0.5f * (float)WIDTH);
  int y = (int)((1.0 - vec->y) * 0.5f * (float)HEIGHT);
  return (y * WIDTH)+x;
}

void perspective_divide(Vec4 *vec){
  if (vec->w <= 0.001f) return;
  float w_inv = 1 / vec->w;
  vec->x *= w_inv;
  vec->y *= w_inv;
  vec->z *= w_inv;
  vec->w = 1.0f;
 }

Vec4 viewport_transform(Vec4 *vec){
  int x = (int)((vec->x + 1) * 0.5f * WIDTH);
  int y = (int)((vec->y - 1) * 0.5f * HEIGHT);
  float depth = vec->z;
  Vec4 result = (Vec4){
    .x = x,
    .y = y,
    .z = depth,
    .w = 1,
  };
  return result;
}
