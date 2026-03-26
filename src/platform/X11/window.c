#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "window.h"
#include <stdio.h>
#include <err.h>
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void CreateWindow(FrameWindow *window, uint32_t *framebuffer){
  
  window->dp = XOpenDisplay(NULL);

  if(window->dp == NULL){
    errx(1, "Can't Open Display:67");
  }
  window->scr = DefaultScreen(window->dp);
  window->root = RootWindow(window->dp, window->scr);

  if(!XMatchVisualInfo(window->dp, window->scr, 24, TrueColor, &window->vinfo)){
    errx(1, "No 32bit True Color available");
  }

  window->attrs.colormap = XCreateColormap(window->dp, RootWindow(window->dp, window->scr), window->vinfo.visual, AllocNone);
  window->attrs.background_pixel = 0;
  window->attrs.border_pixel = 0;
  window->win = XCreateWindow(window->dp, window->root, POSX, POSY, window->width, window->height, BORDER, window->vinfo.depth, InputOutput, window->vinfo.visual, CWColormap | CWBackPixel | CWBorderPixel, &window->attrs);

  window->gc = XCreateGC(window->dp, window->win, 0, NULL);

  
  window->WM_DELETE_WINDOW = XInternAtom(window->dp, "WM_DELETE_WINDOW", False);
  XSetWMProtocols(window->dp, window->win, &window->WM_DELETE_WINDOW, 1);
  XSelectInput(window->dp, window->win, ExposureMask | KeyPressMask);
  XMapWindow(window->dp, window->win);
  XFlush(window->dp);

  window->ximage = XCreateImage(window->dp, window->vinfo.visual, window->vinfo.depth, ZPixmap, 0, (char*)framebuffer, window->width, window->height, 32, 0);
}
//void UpdateWindow(int width, int height, Display* dp, Window win, GC gc, XImage *ximage, XEvent ev, Atom *WM_DELETE_WINDOW){ 
void UpdateWindow(FrameWindow *window){
    while (XPending(window->dp)){
      XEvent ev;
      XNextEvent(window->dp, &ev);

      if(ev.type == ClientMessage){
        if((Atom)ev.xclient.data.l[0] ==  window->WM_DELETE_WINDOW) {
          window->windowShouldClose = 1;
        }
      }
      if(ev.type == Expose){
        XPutImage(window->dp, window->win, window->gc, window->ximage, 0,0,0,0, window->width, window->height);
        XFlush(window->dp);
      }
    }
    XPutImage(window->dp, window->win, window->gc, window->ximage, 0,0,0,0, window->width, window->height);
    XFlush(window->dp);
  }
