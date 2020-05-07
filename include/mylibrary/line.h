//
// Created by faris on 4/26/2020.
//

#ifndef FINALPROJECT_LINE_H
#define FINALPROJECT_LINE_H

#include <Box2D/Box2D.h>
#include <vector>
#include <cinder/gl/gl.h>
#include <mylibrary/Shape.h>
using namespace ci;

class line : public Shape{
 public:
  int liid;
  line(b2World* world, const vec2 &pos);
  b2Body* m_body;
  void SetRemove();
  bool remove = false;
};

#endif  // FINALPROJECT_LINE_H
