#include "Scene.h"
#include "Scenes.h"
#include "renderer.h"
#include <stdio.h>
#include <stdlib.h> 
#include <stdint.h>

// Set globals
static FILE *file = NULL;
static uint32_t *file_buffer = NULL;
static size_t file_size = 0;

Vec4 vector;
Matrix4x4 matrix;
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
  
  /*vector.x = 15; vector.y = 23; vector.z = 67; vector.w = 1;
  matrix = (Matrix4x4){
    .matrix = {
      {1,0,0,100},
      {0,1,0,50},
      {0,0,1,25},
      {0,0,0,1}
    }
  };
  vec_x_matrix_affine(&vector, &matrix);

  printf("%f\n%f\n%f\n%f\n", vector.x, vector.y, vector.z, vector.w);*/

  Matrix4x4 matrix1 = (Matrix4x4){
    .matrix = {
      {1,2,3,4},
      {5,6,7,8},
      {9,10,11,12},
      {13,14,15,16}
    }
  };

  Matrix4x4 matrix2 = (Matrix4x4){
    .matrix = {
      {1,2,3,4},
      {5,6,7,8},
      {9,10,11,12},
      {13,14,15,16}
    }
  };

  Matrix4x4 result = matrix_subtraction(&matrix1, &matrix2);

  printf("%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n", result.m[0], result.m[1], result.m[2], result.m[3], result.m[4], result.m[5], result.m[6], result.m[7], result.m[8], result.m[9], result.m[10], result.m[11], result.m[12], result.m[13], result.m[14], result.m[15]);
}
void ImageSceneUpdate(){

}

void ImageSceneDraw(uint32_t *framebuffer){
  //printf("%08X\n", file_buffer[0]);
   for(int i = 0; i < 800 * 600; i++){
    //file_buffer[i] = big_to_little(file_buffer[i]);
    framebuffer[i] = file_buffer[i]; 
  }

}

void ImageSceneEnd(){
  free(file_buffer);
  printf("Freed file buffer\n");
}

// Creating a struct for this specific Scene
Scene ImageScene = {
  .id = 0,
  .SceneInit = ImageSceneInit,
  .SceneUpdate = ImageSceneUpdate,
  .SceneDraw = ImageSceneDraw,
  .SceneEnd = ImageSceneEnd,
};
