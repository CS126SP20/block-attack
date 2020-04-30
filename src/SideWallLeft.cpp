//
// Created by faris on 4/29/2020.
//

#include "mylibrary/SideWallLeft.h"

SideWallLeft::SideWallLeft(b2World *world, int size) {
  b2BodyDef sideWallLeftDef;
  sideWallLeftDef.position.Set(0.0f, 0.0f);
  m_body = world->CreateBody(&sideWallLeftDef);
  b2PolygonShape sideWallLeft;
  sideWallLeft.SetAsBox(10.0f, size);
  m_body->CreateFixture(&sideWallLeft, 0.0f);
}
