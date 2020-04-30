//
// Created by faris on 4/29/2020.
//

#ifndef FINALPROJECT_MULTIPLIER_H
#define FINALPROJECT_MULTIPLIER_H
#include <Box2D/Box2D.h>
#include <vector>
#include <cinder/gl/gl.h>
using namespace ci;

class multiplier {
  const float BOX_SIZE = 10;

public:
  multiplier(b2World* world, const vec2 &pos);
  b2Body* m_body;

};

#endif  // FINALPROJECT_MULTIPLIER_H
