#ifndef SCENE_H
#define SCENE_H
#include <stdint.h>

void SceneInit();
void SceneUpdate();
void SceneDraw();
void SceneEnd();

typedef struct {
  int id;
  void(*SceneInit)();
  void(*SceneUpdate)();
  void(*SceneDraw)(uint32_t *framebuffer);
  void(*SceneEnd)();
}Scene;

void SetScene(Scene *scene);
void RunSceneUpdate();
void RunSceneDraw(uint32_t *framebuffer);

#endif
