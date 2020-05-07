//
// Created by faris on 5/4/2020.
//

#include "mylibrary/Ground.h"
#include <Box2D/Box2D.h>

Ground::Ground(b2World* world, int height, int width) {
  b2BodyDef groundBodyDef;
  groundBodyDef.position.Set(0.0f, height);
  groundBodyDef.type = b2_staticBody;
  b2Body* groundBody;
  groundBody = world->CreateBody(&groundBodyDef);

  b2PolygonShape groundBox;
  groundBox.SetAsBox(width, 10.0f);
  groundBody->CreateFixture(&groundBox, 0.0f);
  GetShapeType = -2;
  groundBody->SetUserData(this);
}