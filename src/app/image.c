#include "Scene.h"
#include "Scenes.h"
#include <stdio.h>
#include <stdlib.h> 
#include <stdint.h>

// Set globals
static FILE *file = NULL;
static uint32_t *file_buffer = NULL;
static size_t file_size = 0;

// Init, Update, Draw and End functions

void ImageSceneInit(){
  file = fopen("output.raw", "rb");
  if(!file){
    perror("Failed to open file!");
    exit(1);
  }
  fseek(file, 0, SEEK_END);
  file_size = ftell(file);
  rewind(file);
  file_buffer = malloc(file_size);
  if(!file_buffer){
    perror("failed to allocate 67 buffer");
    exit(1);
  }

  size_t read = fread(file_buffer, 1, file_size, file);
  fclose(file);

}

void ImageSceneUpdate(){

}

void ImageSceneDraw(uint32_t *framebuffer){
  printf("%08X\n", file_buffer[0]);
   for(int i = 0; i < 800 * 600; i++){
    //file_buffer[i] = (file_buffer[i] << 8);
    framebuffer[i] = file_buffer[i]; 
  }

}

void ImageSceneEnd(){
  free(file_buffer);
  printf("Freed file buffer");
}

// Creating a struct for this specific Scene
Scene ImageScene = {
  .id = 0,
  .SceneInit = ImageSceneInit,
  .SceneUpdate = ImageSceneUpdate,
  .SceneDraw = ImageSceneDraw,
  .SceneEnd = ImageSceneEnd,
};
