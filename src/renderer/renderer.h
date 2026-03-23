#ifndef RENDERER_H
#define RENDERER_H

#include <stdint.h>

//screen related declarations
#define WIDTH 800
#define HEIGHT 600

extern uint32_t* framebuffer;

//Matrix and Vector declarations
typedef union {
  struct {
    float x, y, z, w;
  };
  
  float vec4[4];
}Vec4;

typedef union {
  float matrix[4][4];
  float m[16];
}Matrix4x4;

//declare objects like Cameras
typedef struct {
  float FOV;
  Vec4 pos;
  Vec4 target;
  Vec4 up;
}Camera;

// Vector * Matrix Functions 
void vec_x_matrix_affine(Vec4 *vec, Matrix4x4 *matrix);
void vec_x_matrix_projective(Vec4 *vec, Matrix4x4 *matrix);

// Matrix arithmetic functions
Matrix4x4 matrix_addition(Matrix4x4 *matrix1, Matrix4x4 *matrix2);
Matrix4x4 matrix_subtraction(Matrix4x4 *matrix1, Matrix4x4 *matrix2);
Matrix4x4 matrix_multiplication(Matrix4x4 *matrix1, Matrix4x4 *matrix2);

//Vector arithmetic functions
Vec4 vec_subtraction(Vec4 *vec1, Vec4 *vec2);
float vec_magnitude(Vec4 *vec);
Vec4 vec_normalize(Vec4 vec);
Vec4 vec_cross_product(Vec4 *vec1, Vec4 *vec2);
float vec_dot_product(Vec4 *vec1, Vec4 *vec2);

//Camera Matrix function
Matrix4x4 lookAt(Camera *cam);

#endif
