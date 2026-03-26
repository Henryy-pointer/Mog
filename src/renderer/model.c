#include "renderer.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*void draw_vertex(Vec4 *vertex, Matrix4x4 *modelMatrix, Matrix4x4 *view, Matrix4x4 *projection, uint32_t *framebuffer){
  Vec4 workingVertex;
  workingVertex.x = vertex->x; workingVertex.y = vertex->y; workingVertex.z = vertex->z; workingVertex.w = vertex->w;
  vec_x_matrix_affine(&workingVertex, modelMatrix);
  vec_x_matrix_affine(&workingVertex, view);
  vec_x_matrix_projective(&workingVertex, projection);
  if(workingVertex.x >= -1 && workingVertex.x <= 1 &&
    workingVertex.y >= -1 && workingVertex.y <= 1 &&
    workingVertex.z >= 0 && workingVertex.z <= 1){
        framebuffer[ndc_to_index(&workingVertex)] = 0x0000FF00;
    }
}*/

void draw_vertex(Vec4 *vertex, Matrix4x4 *mvp, uint32_t *framebuffer){
  Vec4 workingVertex;
  workingVertex.x = vertex->x; workingVertex.y = vertex->y; workingVertex.z = vertex->z; workingVertex.w = vertex->w;
  vec_x_matrix_projective(&workingVertex, mvp);
  if(workingVertex.x >= -1 && workingVertex.x <= 1 &&
    workingVertex.y >= -1 && workingVertex.y <= 1 &&
    workingVertex.z >= 0 && workingVertex.z <= 1){
        framebuffer[ndc_to_index(&workingVertex)] = 0x0000FF00;
    }
}

Vec4 project_vertex(Vec4 *vertex, Matrix4x4 *mvp){
  Vec4 workingVertex;
  workingVertex.x = vertex->x; workingVertex.y = vertex->y; workingVertex.z = vertex->z; workingVertex.w = vertex->w;
  vec_x_matrix_projective(&workingVertex, mvp);
  if(workingVertex.x >= -1 && workingVertex.x <= 1 &&
    workingVertex.y >= -1 && workingVertex.y <= 1 &&
    workingVertex.z >= 0 && workingVertex.z <= 1){
        return ndc_to_2d_screen(&workingVertex);
    }
}


void draw_model_vertices(Model *model, Camera *camera, uint32_t *framebuffer){
  Matrix4x4 modelMatrix = transform(&model->scale, &model->rotation, &model->position);
  Matrix4x4 view = lookAt(camera);
  Matrix4x4 projection = get_projection_matrix(camera);

  Matrix4x4 MVP = matrix_multiplication(&projection, &view);
  MVP = matrix_multiplication(&MVP, &modelMatrix);
  int vertex_count = sizeof(model->vertices) / sizeof(model->vertices[0]);
  for(int i = 0; i < vertex_count; i++){
    draw_vertex(&model->vertices[i], &MVP, framebuffer);
  }
}

void drawLine(int x0, int y0, int x1, int y1, uint32_t *framebuffer, uint32_t color){
  int dx = abs(x1 -x0);
  int sx = x0 < x1 ? 1 : -1;
  int dy = -abs(y1 -y0);
  int sy = y0 < y1 ? 1 : -1;
  int error = dx + dy;
  int e2;
  int True = 1;
  while(True){
   plot(x0, y0, framebuffer, color);
   e2 = 2 * error;
   if(e2 >= dy){
     if(x0 == x1) break;
     error = error + dy;
     x0 = x0 + sx;
   }
   if(e2 <= dx){
     if(y0 == y1) break;
     error = error + dx;
     y0 = y0 + sy;
   }
  } 
}


void draw_model_wireframe(Model *model, Camera *camera, uint32_t *framebuffer, uint32_t color){
  Matrix4x4 modelMatrix = transform(&model->scale, &model->rotation, &model->position);
  Matrix4x4 view = lookAt(camera);
  Matrix4x4 projection = get_projection_matrix(camera);

  Matrix4x4 MVP = matrix_multiplication(&projection, &view);
  MVP = matrix_multiplication(&MVP, &modelMatrix);

  int vertex_count = sizeof(model->vertices) / sizeof(model->vertices[0]);
  int edge_count = 12; 
  Vec4 screenPositionOfEachVertex[vertex_count];
  for(int i = 0; i < vertex_count; i++){
    screenPositionOfEachVertex[i] = project_vertex(&model->vertices[i], &MVP);
  }
  for(int i = 0; i < edge_count; i++ ){
    int v0 = model->edges[i][0];
    int v1 = model->edges[i][1];

    int x0 = screenPositionOfEachVertex[v0].x;
    int y0 = screenPositionOfEachVertex[v0].y;
    int x1 = screenPositionOfEachVertex[v1].x;
    int y1 = screenPositionOfEachVertex[v1].y;

    drawLine(x0, y0, x1, y1, framebuffer, color);
  }
}
