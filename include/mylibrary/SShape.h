//
// Created by faris on 4/26/2020.
//

#ifndef FINALPROJECT_SSHAPE_H
#define FINALPROJECT_SSHAPE_H

#include <Box2D/Box2D.h>
#include <vector>
#include <cinder/gl/gl.h>
#include <mylibrary/Shape.h>
using namespace ci;

class SShape : public Shape {

 public:
  SShape(b2World* world,const vec2 &pos);
  b2Body* m_body;
  int SSid;

};


#endif  // FINALPROJECT_LSHAPE_H
