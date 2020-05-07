//
// Created by faris on 4/21/2020.
//

#include "mylibrary/square.h"
#include "cinder/gl/gl.h"
#include <string>


square::square() {

}
square::square(b2World* world, const vec2& pos) {
//  b2Vec2 vertices[3];
//  vertices[0].Set(0.0f, 0.0f);
//  vertices[1].Set(100.0f, 0.0f);
//  vertices[2].Set(0.0f, 100.0f);
  b2BodyDef myBodyDef;
  myBodyDef.type = b2_dynamicBody;
  myBodyDef.position.Set(pos.x, pos.y);
  m_body = world->CreateBody(&myBodyDef);
  GetShapeType = 0;
  sid = myapp::id++ + 400;
  m_body->SetUserData(this);
  b2PolygonShape dynamicBox;
  dynamicBox.SetAsBox(50, 50);
  b2FixtureDef fixtureDef;
  fixtureDef.shape = &dynamicBox;
  fixtureDef.density = 1.0f;
  fixtureDef.friction = 0.0f;
  fixtureDef.restitution = 0.0f;  // bounce
  m_body->CreateFixture(&fixtureDef);
}

