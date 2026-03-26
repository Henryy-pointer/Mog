#include "renderer.h"
#include <stdint.h>

void plot(int x, int y, uint32_t *framebuffer, uint32_t color){
  int index = (y * WIDTH)+x;
  if(index >= 0 && index <= WIDTH * HEIGHT){
    framebuffer[index] = color;
  }
}
