//
// Created by faris on 4/29/2020.
//

#ifndef FINALPROJECT_SIDEWALLRIGHT_H
#define FINALPROJECT_SIDEWALLRIGHT_H
#include <Box2D/Box2D.h>
#include <vector>
#include <cinder/gl/gl.h>
#include <mylibrary/Shape.h>
using namespace ci;
class SideWallRight : public Shape{

 public:
  SideWallRight(b2World* world, float size, float width);
  b2Body* m_body;

};

#endif  // FINALPROJECT_SIDEWALLRIGHT_H
