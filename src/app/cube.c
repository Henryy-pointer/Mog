#include "Scene.h"
#include "Scenes.h"
#include "renderer.h"
#include <stdint.h>
#include <stdio.h>

/*typedef struct {
  Vec4 scale;
  Vec4 rotation;
  Vec4 position;
  Vec4 v1;
  Vec4 v2;
  Vec4 v3;
  Vec4 v4;
  Vec4 v5;
  Vec4 v6;
  Vec4 v7;
  Vec4 v8;
}CubeModel;*/

Camera myCamera;

Model myCube;
Vec4 vec;

float a = 0.5;

const uint32_t GREEN = 0x0000FF00;
void CubeSceneInit(){
  /*myCube = (CubeModel){
    .scale.vec4 = {1,1,1,1},
    .rotation.vec4 = {0,0,0,1},
    .position.vec4 = {0,0,5,1},
    .v1.vec4 = {1,1,-1, 1},
    .v2.vec4 = {1,-1,-1, 1},
    .v3.vec4 = {1,1,1,1},
    .v4.vec4 = {1,-1,1,1},
    .v5.vec4 = {-1,1,-1, 1},
    .v6.vec4 = {-1,-1,-1, 1},
    .v7.vec4 = {-1,1,1,1},
    .v8.vec4 = {-1,-1,1,1},
  };*/

  myCamera = (Camera){
    .FOV = 1.39f,
    .pos.vec4 = {5,0,5,1},
    .target.vec4 = {0,0,0,1},
    .up.vec4 = {0,1,0,0},
    .far = 100.0f,
    .near= 0.1f,
  };
  
  myCube = (Model){
    .scale = {1.25,1.25,1.25},
    .rotation = {a,a,a},
    .position = {0,0,0},
    .vertices = {
      {1,1,-1,1},
      {1,-1,-1,1},
      {1,1,1,1},
      {1,-1,1,1},
      {-1,1,-1,1},
      {-1,-1,-1,1},
      {-1,1,1,1},
      {-1,-1,1,1}},
    .edges = {
      {0,1}, {1,3}, {3,2}, {2,0},
      {4,5},{5,7},{7,6},{6,4},
      {0,4}, {1,5}, {2,6},{3,7},
    },
  };
  /*vec = (Vec4){1,1,1,1};
  Vec4 scale = (Vec4){1,1,1,1};
  Vec4 rotation = (Vec4){0,0,0,1};
  Vec4 position = (Vec4){50,10,0,1};
  Matrix4x4 transformM = transform(&scale, &rotation, &position);

  vec_x_matrix_affine(&vec, &transformM);
  Matrix4x4 view = lookAt(&myCamera);
  vec_x_matrix_affine(&vec, &view);
  Matrix4x4 projection = get_projection_matrix(&myCamera);
  vec_x_matrix_projective(&vec, &projection);*/

}

void CubeSceneUpdate(){
  a += 0.05;
  myCube.rotation = (Vec4){a,a,a};
  //printf("a: %f\n", a);
}

void CubeSceneDraw(uint32_t *framebuffer){
  for(int i = 0; i < WIDTH * HEIGHT; i++){
    framebuffer[i] = 0x00000000;
  }

  //framebuffer[ndc_to_index(&vec)] = 0x0000FF00;
  draw_model_wireframe(&myCube, &myCamera, framebuffer, GREEN);

}

void CubeSceneEnd(){

}

Scene Cube = {
  .id = 1,
  .SceneInit = CubeSceneInit,
  .SceneUpdate = CubeSceneUpdate,
  .SceneDraw = CubeSceneDraw,
  .SceneEnd = CubeSceneEnd,
};
