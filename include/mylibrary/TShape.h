//
// Created by faris on 4/26/2020.
//

#ifndef FINALPROJECT_TSHAPE_H
#define FINALPROJECT_TSHAPE_H

#include <Box2D/Box2D.h>
#include <vector>
#include <cinder/gl/gl.h>
#include <mylibrary/Shape.h>
using namespace ci;

class TShape : public Shape{

 public:
  TShape(b2World* world, const vec2 &pos);
  b2Body* m_body;

};


#endif  // FINALPROJECT_TSHAPE_H
