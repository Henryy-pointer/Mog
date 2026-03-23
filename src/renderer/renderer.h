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

// Vector * Matrix Functions 
void vec_x_matrix_affine(Vec4 *vec, Matrix4x4 *matrix);
void vec_x_matrix_projective(Vec4 *vec, Matrix4x4 *matrix);

// Matrix arithmetic functions
Matrix4x4 matrix_addition(Matrix4x4 *matrix1, Matrix4x4 *matrix2);
Matrix4x4 matrix_subtraction(Matrix4x4 *matrix1, Matrix4x4 *matrix2);
Matrix4x4 matrix_multiplication(Matrix4x4 *matrix1, Matrix4x4 *matrix2);

#endif
