//
// Created by faris on 4/21/2020.
//

#ifndef FINALPROJECT_SQUARE_H
#define FINALPROJECT_SQUARE_H

#include <Box2D/Box2D.h>
#include <vector>
#include <cinder/gl/gl.h>
#include <mylibrary/Shape.h>
using namespace ci;

class square : public Shape{

 public:
  square::square();
  square(b2World* world, const vec2 &pos);
    b2Body* m_body;
    int sid;

};

#endif //FINALPROJECT_SQUARE_H
