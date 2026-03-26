#include "renderer/renderer.h"
#include "platform/X11/window.h"
#include "Scene.h"
#include "app/Scenes.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

extern Scene *currentScene;
uint32_t *framebuffer;

int main(){
  //framebuffer = malloc(WIDTH * HEIGHT * sizeof(uint32_t));
  uint32_t *framebuffer = malloc(WIDTH * HEIGHT * sizeof(uint32_t));
  FrameWindow window;
  window.width = WIDTH;
  window.height = HEIGHT;
  CreateWindow(&window, framebuffer);
  window.windowShouldClose = 0;
  SetScene(&Cube);
  #ifdef DEBUG
    int counter = 0;
  #endif 

  while(!window.windowShouldClose){
    RunSceneUpdate();
    RunSceneDraw(framebuffer);
    UpdateWindow(&window);
    //printf("frame done\n");
    usleep(16666);
  #ifdef DEBUG
    counter++;
    printf("frame: %i\n", counter);
  #endif
  }
  if(currentScene && currentScene->SceneEnd)currentScene->SceneEnd();
  //Cleanup();
  free(framebuffer);
  printf("freed framebuffer\n");
  return 0;
}
