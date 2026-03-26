#ifndef RENDERER_H
#define RENDERER_H
//#define DEBUG

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
  float far;
  float near;
}Camera;

//Model type
typedef struct {
  Vec4 scale;
  Vec4 rotation;
  Vec4 position;
  Vec4 vertices[8];
  int edges[12][2];
}Model;

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

//get model matrix functions
Matrix4x4 get_rotation_matrix(Vec4 *rotation);
Matrix4x4 transform(Vec4 *scale, Vec4 *rotation, Vec4 *position);

//BIG PROJECTION MATRIX (DECRYPTED FROM THE EVIL WIKIPEDIA)
Matrix4x4 get_projection_matrix(Camera *camera);


//WE ARE FINALLY IN 2D SPACE NIGGERSSSSSSSSS, HERE COMES THE RASTERIZER
void perspective_divide(Vec4 *vec);
Vec4 viewport_transform(Vec4 *vec);

int ndc_to_index(Vec4 *vec);
Vec4 ndc_to_2d_screen(Vec4 *vec);

//framebuffer functions
void plot(int x, int y, uint32_t *framebuffer, uint32_t color);
//model rendering functions
void draw_vertex(Vec4 *vertex, Matrix4x4 *mvp, uint32_t *framebuffer);
Vec4 project_vertex(Vec4 *vertex, Matrix4x4 *mvp);
void draw_model_vertices(Model *model, Camera *camera, uint32_t *framebuffer);
void drawLine(int x0, int y0, int x1, int y1, uint32_t *framebuffer, uint32_t color);
void draw_model_wireframe(Model *model, Camera *camera, uint32_t *framebuffer, uint32_t color);
#endif
