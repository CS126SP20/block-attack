//
// Created by faris on 4/21/2020.
//

#include "mylibrary/LShape.h"
#include "mylibrary/Shape.h"
#include "cinder/gl/gl.h"
#include <string>
LShape::LShape(b2World* world, const vec2& pos) {
//  b2Vec2 vertices[3];
//  vertices[0].Set(0.0f, 0.0f);
//  vertices[1].Set(100.0f, 0.0f);
//  vertices[2].Set(0.0f, 100.0f);
  b2BodyDef myBodyDef;
  myBodyDef.type = b2_dynamicBody;
  myBodyDef.position.Set(pos.x, pos.y);
  m_body = world->CreateBody(&myBodyDef);
  GetShapeType = 4;
  lid = myapp::id++ + 500;
  m_body->SetUserData(this);
  b2PolygonShape dynamicBox;
  dynamicBox.SetAsBox(25, 75);
  b2FixtureDef fixtureDef;
  fixtureDef.shape = &dynamicBox;
  fixtureDef.density = 10.0f;
  fixtureDef.friction = 0.0f;
  fixtureDef.restitution = 0.0f;// bounce

  b2PolygonShape dynBox;
  dynBox.SetAsBox(25,25,b2Vec2(50,50),0);
  b2FixtureDef fixture;
  fixture.shape = &dynBox;
  fixture.density = 1.0f;
  fixtureDef.friction = 0.0f;
  fixtureDef.restitution = 0.0f;// bounce

  m_body->CreateFixture(&fixtureDef);
  m_body->CreateFixture(&fixture);
}


