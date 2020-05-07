//
// Created by faris on 5/4/2020.
//

#include "mylibrary/Ceiling.h"
#include <Box2D/Box2D.h>

Ceiling::Ceiling(b2World* world, int height, int width) {
  b2BodyDef ceilingBodyDef;
  ceilingBodyDef.position.Set(0.0, -height);
  ceilingBodyDef.type = b2_staticBody;
  b2Body* groundBody;
  groundBody = world->CreateBody(&ceilingBodyDef);

  b2PolygonShape groundBox;
  groundBox.SetAsBox(width, 10.0f);
  groundBody->CreateFixture(&groundBox, 0.0f);
  GetShapeType = -3;
  groundBody->SetUserData(this);
}