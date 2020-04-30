//
// Created by faris on 4/29/2020.
//

#include "mylibrary/SideWallRight.h"
SideWallRight::SideWallRight(b2World *world, int size) {
  b2BodyDef sideWallRightDef;
  sideWallRightDef.position.Set(size,0.0f);
  m_body = world->CreateBody(&sideWallRightDef);
  b2PolygonShape sideWallRight;
  sideWallRight.SetAsBox(10.0f, size);
  m_body->CreateFixture(&sideWallRight, 0.0f);
}
