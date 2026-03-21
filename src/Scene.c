#include "Scene.h"
#include <stdlib.h>
#include <stdint.h>

Scene *currentScene = NULL;

void SetScene(Scene *scene){
  if(currentScene && currentScene->SceneEnd){
    scene->SceneEnd();
  }

  currentScene = scene;

  if(currentScene && currentScene->SceneInit){
    scene->SceneInit();
  }
}

void RunSceneUpdate(){
  if(currentScene && currentScene->SceneUpdate){
    currentScene->SceneUpdate();
  }
}

void RunSceneDraw(uint32_t *framebuffer){
  if(currentScene && currentScene->SceneDraw){
    currentScene->SceneDraw(framebuffer);
  }
}
