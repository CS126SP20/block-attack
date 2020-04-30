//
// Created by faris on 4/29/2020.
//

#ifndef FINALPROJECT_SIDEWALLRIGHT_H
#define FINALPROJECT_SIDEWALLRIGHT_H
#include <Box2D/Box2D.h>
#include <vector>
#include <cinder/gl/gl.h>
using namespace ci;
class SideWallRight {
  const float BOX_SIZE = 10;

 public:
  SideWallRight(b2World* world, int size);
  b2Body* m_body;

};

#endif  // FINALPROJECT_SIDEWALLRIGHT_H
