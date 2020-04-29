// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <cinder/app/App.h>
#include <mylibrary/Bomb.h>
#include <mylibrary/LShape.h>
#include <mylibrary/line.h>
#include <mylibrary/square.h>

#include "Box2D/Box2D.h"
#include "cinder/gl/gl.h"

namespace myapp {
using namespace ci;

const float BOX_SIZE = 10;

b2World* myWorld;
std::vector<square> myBox;
std::vector<line> myLine;
std::vector<LShape> myLShape;
std::vector<Bomb> myBomb;
MyApp::MyApp() {}

void MyApp::setup() {
  b2Vec2 gravity(0.0f, 9.8f);
  myWorld = new b2World(gravity);
  b2BodyDef groundBodyDef;
  groundBodyDef.position.Set(0.0f, getWindowHeight());
  b2Body* groundBody = myWorld->CreateBody(&groundBodyDef);

  b2PolygonShape groundBox;
  groundBox.SetAsBox(getWindowWidth(), 10.0f);
  groundBody->CreateFixture(&groundBox, 0.0f);
}

void MyApp::mouseDown(cinder::app::MouseEvent event) {
  LShape lShape(myWorld, event.getPos());
  square square(myWorld, event.getPos());
  line line(myWorld, event.getPos());
  Bomb nShape(myWorld, event.getPos());
//  myLine.push_back(line);
//  myBox.push_back(square);
//  myLShape.push_back(lShape);
  myBomb.push_back(nShape);
}
void MyApp::update() {
  for (int i = 0; i < 10; ++i) {
    myWorld->Step(1 / 30.0f, 10, 10);
  }
}

void MyApp::draw() {
  gl::clear();
  DrawSquare();
  DrawLine();
  DrawLShape();
  DrawBomb();
}
void MyApp::DrawLShape() {
  for (const auto& l : myLShape) {
    gl::pushModelMatrix();
    gl::translate(l.m_body->GetPosition().x, l.m_body->GetPosition().y);
    gl::rotate(l.m_body->GetAngle());

//    gl::drawSolidTriangle(vec2(0, 0), vec2(10.0f, 0.0f), vec2(0.0f, 10.0f));
//    PolyLine2f pi;
//    pi.push_back(vec2(0.0f, 0.0f));
//    pi.push_back(vec2(100.0f, 0.0f));
//    pi.push_back(vec2(0.0f, 100.0f));
//    gl::drawSolid(pi);
    gl::color(0, 0, 1);
    PolyLine2f pi;
    pi.push_back(vec2(25,75));
    pi.push_back(vec2(25,-75));
    pi.push_back(vec2(-25,-75));
    pi.push_back(vec2(-25,75));
    gl::drawSolid(pi);
    PolyLine2f polyLine2F;
    polyLine2F.push_back(vec2(75,75));
    polyLine2F.push_back(vec2(0,75));
    polyLine2F.push_back(vec2(0,25));
    polyLine2F.push_back(vec2(75,25));
    gl::drawSolid(polyLine2F);

    gl::color(0,0,0);
    gl::begin(GL_LINES);
    gl::lineWidth(5);
    gl::vertex(-25,25);
    gl::vertex(25,25);
    gl::vertex(25,25);
    gl::vertex(25, 75);
    gl::vertex(-25,-25);
    gl::vertex(25,-25);
    gl::end();


    gl::popModelMatrix();
  }
}
void MyApp::DrawSquare() {
  for (const auto& box : myBox) {
    gl::pushModelMatrix();
    gl::translate(box.m_body->GetPosition().x, box.m_body->GetPosition().y);
    gl::rotate(box.m_body->GetAngle());

//    gl::drawSolidTriangle(vec2(0, 0), vec2(10.0f, 0.0f), vec2(0.0f, 10.0f));
//    PolyLine2f pi;
//    pi.push_back(vec2(0.0f, 0.0f));
//    pi.push_back(vec2(100.0f, 0.0f));
//    pi.push_back(vec2(0.0f, 100.0f));
//    gl::drawSolid(pi);
    gl::color(1, 1, 1);

    gl::drawSolidRect(Rectf(-50,-50,50,50));

    gl::color(0,0,0);
    gl::begin(GL_LINES);
    gl::lineWidth(5);

    gl::vertex(0, 50);
    gl::vertex(0,-50);
    gl::vertex(50,0);
    gl::vertex(-50,0);

    gl::end();


    gl::popModelMatrix();
  }
}
void MyApp::DrawLine() {
  for (const auto& line : myLine) {
    gl::pushModelMatrix();
    gl::translate(line.m_body->GetPosition().x, line.m_body->GetPosition().y);
    gl::rotate(line.m_body->GetAngle());

//    gl::drawSolidTriangle(vec2(0, 0), vec2(10.0f, 0.0f), vec2(0.0f, 10.0f));
//    PolyLine2f pi;
//    pi.push_back(vec2(0.0f, 0.0f));
//    pi.push_back(vec2(100.0f, 0.0f));
//    pi.push_back(vec2(0.0f, 100.0f));
//    gl::drawSolid(pi);
    gl::color(1, 0, 0);

    gl::drawSolidRect(Rectf(-100,-25,100,25));

    gl::color(0,0,0);
    gl::begin(GL_LINES);
    gl::lineWidth(5);
    gl::vertex(0, 25);
    gl::vertex(0,-25);
    gl::vertex(50,25);
    gl::vertex(50,-25);
    gl::vertex(-50, 25);
    gl::vertex(-50,-25);


    gl::end();


    gl::popModelMatrix();
  }

}
void MyApp::DrawBomb() {
  for (const auto& nShape : myBomb) {
    gl::pushModelMatrix();
    gl::translate(nShape.m_body->GetPosition().x, nShape.m_body->GetPosition().y);
    gl::rotate(nShape.m_body->GetAngle());

//    gl::drawSolidTriangle(vec2(0, 0), vec2(10.0f, 0.0f), vec2(0.0f, 10.0f));
//    PolyLine2f pi;
//    pi.push_back(vec2(0.0f, 0.0f));
//    pi.push_back(vec2(100.0f, 0.0f));
//    pi.push_back(vec2(0.0f, 100.0f));
//    gl::drawSolid(pi);
    gl::color(0, 1, 0);
    gl::drawSolidCircle(vec2(0,0), 50.0f);


    gl::popModelMatrix();
  }

}

}  // namespace myapp
