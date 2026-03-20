#include <X11/Xlib.h>
#include <stdio.h>
#include <err.h>
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

Display* dp;
static int scr;
static Window root;

#define POSX 960
#define POSY 540
#define WIDTH 800
#define HEIGHT 600
#define BORDER 15

uint32_t *framebuffer;


void exit(){
  XUnmapWindow(dp, win);
  XDestroyWindow(dp, win);
  XCloseDisplay(dp);
  free(framebuffer);
  framebuffer = NULL;
  return 0;
}

void handle_signal(){
  exit();
}

int main(){

  signal(SIGINT, handle_signal);
  signal(SIGTERM, handle_signal);
  signal(SIGQUIT, handle_signal);
  Window win;
  XEvent ev;

  dp = XOpenDisplay(NULL);

  if(dp == NULL){
    errx(1, "Can't Open Display:67");
  }
  scr = DefaultScreen(dp);
  root = RootWindow(dp, scr);

  win = XCreateSimpleWindow(dp, root, POSX, POSY, WIDTH, HEIGHT, BORDER, BlackPixel(dp, scr), WhitePixel(dp, scr));

  Atom WM_DELETE_WINDOW = XInternAtom(dp, "WM_DELETE_WINDOW", False);
  XMapWindow(dp, win);

  uint32_t *framebuffer = malloc(WIDHT * HEIGHT * sizeof(uint32_t));

  while(1){
    XNextEvent(dp, &ev);

    if(ev.type == ClientMessage){
      if((Atom)ev.xclient.data.l[0] ==  WM_DELETE_WINDOW) {
        exit();
      }
    }
    
  }
  
  /* unmap window */ 
  exit();
  return 0;
}
