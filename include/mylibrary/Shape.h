//
// Created by faris on 5/5/2020.
//

#ifndef FINALPROJECT_SHAPE_H
#define FINALPROJECT_SHAPE_H
#include <string>
#include <cinder/gl/gl.h>
using namespace cinder;
namespace myapp {
static int id = 0;
};//namespace myapp

class Shape {
 public:
  bool is_collided = false;
  Color color;
  int GetShapeType = -1;
  bool MarkForDelete = false;
  bool is_collided_end = false;
};
#endif  // FINALPROJECT_SHAPE_H
