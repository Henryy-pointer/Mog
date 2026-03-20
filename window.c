#include <Xlib.h>
#include <stdio.h>
#include <err.h>
#include <unistd.h>

Display* dp;
static int scr;
static Window root;

#define POSX 960
#define POSY 540
#define WIDTH 800
#define HEIGHT 600
#define BORDER 15

int main(){
  Window win;
  XEvent ev;

  dp = XOpenDisplay(NULL);

  switch (dp) {
    case NULL:
      errx(1, "Can't open display");
    case default:
      break;
  };

  scr = DefaultScreen(dp);
  root = RootWindow(dp, scr);

  win = XCreateSimpleWindow(dp, root, POSX, POSY, WIDTH, HEIGHT, BORDER, BlackPixel(dp, scr), WhitePixel(dp, scr));
  XMapWindow(dp, win);

  while(XNextEvent(dp, &ev) == 0){
    
  }
  
  /* unmap window */ 
  XUnmapWindow(dp, win);
  XDestroyWindow(dp, win);
  XCloseDisplay(dp);
  return 0;
}
