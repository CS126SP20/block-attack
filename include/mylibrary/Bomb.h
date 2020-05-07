//
// Created by faris on 4/28/2020.
//
#include <Box2D/Box2D.h>
#include <cinder/gl/gl.h>
#include <cinder/app/App.h>

#include <vector>


using namespace ci;
#ifndef FINALPROJECT_NSHAPE_H
#define FINALPROJECT_NSHAPE_H
#include <mylibrary/Shape.h>
class Bomb : public Shape{
  bool m_contacting;
 public:
  Bomb(b2World* world, const vec2 &pos);
  int bid;
  b2Body* m_body;

};

#endif  // FINALPROJECT_NSHAPE_H
