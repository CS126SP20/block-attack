//
// Created by faris on 4/29/2020.
//

#include "mylibrary/SideWallRight.h"
#include <string>
SideWallRight::SideWallRight(b2World *world, float size, float width) {
  b2BodyDef sideWallRightDef;
  sideWallRightDef.type = b2_staticBody;
  sideWallRightDef.position.Set(size,width);
  m_body = world->CreateBody(&sideWallRightDef);
  b2PolygonShape sideWallRight;
  sideWallRight.SetAsBox(10.0f, size);
  m_body->CreateFixture(&sideWallRight, 0.0f);
  GetShapeType = -1;
  m_body->SetUserData(this);

}
