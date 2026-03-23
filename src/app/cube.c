#include "Scene.h"
#include "Scenes.h"
#include "renderer.h"
#include <stdint.h>

typedef struct {
  Vec4 v1;
  Vec4 v2;
  Vec4 v3;
  Vec4 v4;
  Vec4 v5;
  Vec4 v6;
  Vec4 v7;
  Vec4 v8;
}CubeModel;

CubeModel myCube;

void CubeSceneInit(){
  myCube = (CubeModel){
    .v1.vec4 = {1,1,-1, 1},
    .v2.vec4 = {1,-1,-1, 1},
    .v3.vec4 = {1,1,1,1},
    .v4.vec4 = {1,-1,1,1},
    .v5.vec4 = {-1,1,-1, 1},
    .v6.vec4 = {-1,-1,-1, 1},
    .v7.vec4 = {-1,1,1,1},
    .v8.vec4 = {-1,-1,1,1},
  };

  Camera myCamera = (Camera){
    .FOV = 80,
    .pos.vec4 = {4,0,0,1},
    .target.vec4 = {0,0,0,1},
    .up.vec4 = {0,1,0,0},
  };
}

void CubeSceneUpdate(){
  
}

void CubeSceneDraw(uint32_t *framebuffer){

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
