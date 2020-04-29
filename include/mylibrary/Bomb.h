//
// Created by faris on 4/28/2020.
//
#include <Box2D/Box2D.h>
#include <vector>
#include <cinder/gl/gl.h>

using namespace ci;
#ifndef FINALPROJECT_NSHAPE_H
#define FINALPROJECT_NSHAPE_H

class Bomb {
 public:
  Bomb(b2World* world, const vec2 &pos);
  b2Body* m_body;
};

#endif  // FINALPROJECT_NSHAPE_H
