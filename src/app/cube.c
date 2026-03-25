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

Vec4 vec;

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
    .pos.vec4 = {99,0,0,1},
    .target.vec4 = {0,0,0,1},
    .up.vec4 = {0,1,0,0},
    .far = 100.0f,
    .near= 0.1f,
  };
  vec = (Vec4){1,1,1,1};
  Vec4 scale = (Vec4){1,1,1,1};
  Vec4 rotation = (Vec4){0,0,0,1};
  Vec4 position = (Vec4){0,0,0,1};
  Matrix4x4 transformM = transform(&scale, &rotation, &position);

  vec_x_matrix_affine(&vec, &transformM);
  Matrix4x4 view = lookAt(&myCamera);
  vec_x_matrix_affine(&vec, &view);
  Matrix4x4 projection = get_projection_matrix(&myCamera, &vec);
  vec_x_matrix_projective(&vec, &projection);

}

void CubeSceneUpdate(){


}

void CubeSceneDraw(uint32_t *framebuffer){
  for(int i = 0; i < WIDTH * HEIGHT; i++){
    framebuffer[i] = 0x00000000;
  }

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
