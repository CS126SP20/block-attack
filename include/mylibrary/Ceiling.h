//
// Created by faris on 5/4/2020.
//

#ifndef FINALPROJECT_Ceiling_H
#define FINALPROJECT_Ceiling_H
#include <Box2D/Box2D.h>
#include "string"
#include <mylibrary/Shape.h>
using namespace std;
class Ceiling : public Shape{
 public:
  Ceiling(b2World* world, int height, int width);
};

#endif  // FINALPROJECT_Ceiling_H
