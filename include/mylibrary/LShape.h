//
// Created by faris on 4/26/2020.
//

#ifndef FINALPROJECT_LSHAPE_H
#define FINALPROJECT_LSHAPE_H

#include <Box2D/Box2D.h>
#include <vector>
#include <cinder/gl/gl.h>
#include <mylibrary/Shape.h>

using namespace ci;

class LShape : public Shape{

 public:
  LShape(b2World* world, const vec2 &pos);
  int lid = -89;
  b2Body* m_body;
};


#endif  // FINALPROJECT_LSHAPE_H
