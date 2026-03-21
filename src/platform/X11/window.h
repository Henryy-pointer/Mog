#ifndef WINDOW_H
#define WINDOW_H

#include <X11/Xutil.h>
#include <X11/Xlib.h>
#include <stdint.h>

typedef struct {
  Display* dp;
  Window win;
  int width;
  int height;
  int scr;
  Window root;
  XImage *ximage;
  GC gc;
  XVisualInfo vinfo;
  XSetWindowAttributes attrs;
  Atom WM_DELETE_WINDOW;
  int windowShouldClose;
}FrameWindow;

/*Display* dp;
Window win;
static int scr;
static Window root;
XImage *ximage = NULL;
GC gc;
XVisualInfo vinfo;
XSetWindowAttributes attrs;*/

#define POSX 960
#define POSY 540
//#define WIDTH 800
//#define HEIGHT 600
#define BORDER 15

//uint32_t *framebuffer;

void CreateWindow(FrameWindow *window, uint32_t *framebuffer);
//void UpdateWindow(int width, int height, Display* dp, Window win, GC gc, XImage *ximage, XEvent ev, Atom *WM_DELETE_WINDOW);
void UpdateWindow(FrameWindow *window);
#endif
