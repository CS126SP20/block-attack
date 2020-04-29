//
// Created by faris on 4/21/2020.
//

#ifndef FINALPROJECT_SQUARE_H
#define FINALPROJECT_SQUARE_H

#include <Box2D/Box2D.h>
#include <vector>
#include <cinder/gl/gl.h>

using namespace ci;

class square {
    const float BOX_SIZE = 10;

 public:
    square(b2World* world, const vec2 &pos);
    b2Body* m_body;

};

#endif //FINALPROJECT_SQUARE_H
