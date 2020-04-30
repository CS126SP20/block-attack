//
// Created by faris on 4/28/2020.
//
#define DEGTORAD 0.0174532925199432957f

#include "mylibrary/Bomb.h"
#include "cinder/gl/gl.h"
using namespace ci;
Bomb::Bomb(b2World* world, const vec2& pos) {
//  b2Vec2 vertices[3];
//  vertices[0].Set(0.0f, 0.0f);
//  vertices[1].Set(100.0f, 0.0f);
//  vertices[2].Set(0.0f, 100.0f);
  b2BodyDef myBodyDef;
  myBodyDef.type = b2_dynamicBody;
  myBodyDef.position.Set(pos.x, pos.y);
  m_body = world->CreateBody(&myBodyDef);

  b2CircleShape cs;
  cs.m_p.Set(0,0);
  cs.m_radius = 50.0f;
  b2FixtureDef fixtureDef;
  fixtureDef.shape = &cs;
  fixtureDef.density = 1.0f;
  m_body->CreateFixture(&fixtureDef);



}

