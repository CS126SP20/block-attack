// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include <Box2D/Box2D.h>

using namespace ci;
namespace myapp {

class MyApp : public cinder::app::App {
 public:
  MyApp();
  void setup() override;
  void update() override;
  void draw() override;
  void keyDown(cinder::app::KeyEvent event) override;
  void DrawSquare();
  void DrawLine();
  void DrawLShape();
  void DrawBomb();
  void DrawLeftWall();
  void DrawRightWall();
  void DrawScore();

  void DrawTShape();
  void DrawZShape();
  void DrawSShape();
  void RemoveDrawing();
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
