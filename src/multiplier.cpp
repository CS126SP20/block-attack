//
// Created by faris on 4/29/2020.
//

#include "mylibrary/multiplier.h"
multiplier::multiplier(b2World *world, const vec2 &pos) {
    b2Vec2 vertices[3];
  vertices[0].Set(0.0f, 0.0f);
  vertices[1].Set(100.0f, 0.0f);
  vertices[2].Set(0.0f, 100.0f);
  b2BodyDef myBodyDef;
  myBodyDef.type = b2_dynamicBody;
  myBodyDef.position.Set(pos.x, pos.y);
  m_body = world->CreateBody(&myBodyDef);

  b2PolygonShape ps;
  ps.Set(vertices, 3);
  b2FixtureDef fixtureDef;
  fixtureDef.shape = &ps;
  fixtureDef.density = 1.0f;
  m_body->CreateFixture(&fixtureDef);

}
