//
// Created by faris on 4/29/2020.
//

#ifndef FINALPROJECT_SIDEWALLLEFT_H
#define FINALPROJECT_SIDEWALLLEFT_H
#include <Box2D/Box2D.h>
#include <vector>
#include <cinder/gl/gl.h>
#include <mylibrary/Shape.h>
using namespace ci;
class SideWallLeft : public Shape{

 public:
  SideWallLeft(b2World* world, int size);
  b2Body* m_body;


};

#endif  // FINALPROJECT_SIDEWALLLEFT_H
