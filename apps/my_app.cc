// Copyright (c) 2020 [Your Name]. All rights reserved.

#define DEGTORAD 0.0174533

#include "my_app.h"

#include <cinder/app/App.h>
#include <mylibrary/Bomb.h>
#include <mylibrary/Ceiling.h>
#include <mylibrary/ContactListener.h>
#include <mylibrary/Ground.h>
#include <mylibrary/LShape.h>
#include <mylibrary/SShape.h>
#include <mylibrary/SideWallLeft.h>
#include <mylibrary/SideWallRight.h>
#include <mylibrary/TShape.h>
#include <mylibrary/ZShape.h>
#include <mylibrary/line.h>
#include <mylibrary/square.h>

#include "Box2D/Box2D.h"
#include "cinder/Rand.h"
#include "cinder/audio/Source.h"
#include "cinder/audio/Voice.h"
#include "cinder/gl/gl.h"
namespace myapp {

b2Vec2 gravity(0.0f, 0.3f);
b2World* myWorld = new b2World(gravity);
std::vector<square*> mySquare;
std::vector<line*> myLine;
std::vector<LShape*> myLShape;
std::vector<Bomb*> myBomb;
std::vector<SideWallRight> rightWall;
std::vector<SideWallLeft> leftWall;
std::vector<TShape*> myTShape;
std::vector<SShape*> mySShape;
std::vector<ZShape*> myZShape;
cinder::audio::VoiceRef mVoice;
bool gameOver = false;
bool gameStart = false;
ContactListener contactListener;
engine engine_(myWorld, mySquare, myLine, myLShape, myBomb,
               myTShape, myZShape, mySShape);
Shape* currentShape;
int currentScore;
MyApp::MyApp() {}

void MyApp::setup() {
  Ground* ground = new class Ground(myWorld, getWindowHeight(), getWindowWidth());
  Ceiling* ceiling = new class Ceiling(myWorld, getWindowHeight(), getWindowWidth());
  SideWallLeft* left = new class SideWallLeft(myWorld, getWindowHeight());
  leftWall.push_back(*left);
  SideWallRight *right = new class SideWallRight(myWorld, getWindowHeight(),getWindowWidth());
  rightWall.push_back(*right);
  myWorld->SetContactListener(&contactListener);
  currentShape = engine_.ChooseBlock();
  cinder::audio::SourceFileRef sourceFile = cinder::audio::load
      (loadAsset("bensound-funkyelement.mp3"));
  mVoice = cinder::audio::Voice::create(sourceFile);
  mVoice->start();
  gameStart = true;
}

void MyApp::keyDown(app::KeyEvent event) {
  switch (event.getCode()) {
    case app::KeyEvent::KEY_UP:
    case app::KeyEvent::KEY_w: {
      engine_.SetDirection(Direction::kUp);
      break;
    }
    case app::KeyEvent::KEY_DOWN:
    case app::KeyEvent::KEY_s: {
      engine_.SetDirection(Direction::kDown);
      break;
    }
    case app::KeyEvent::KEY_LEFT:
    case app::KeyEvent::KEY_a: {
      engine_.SetDirection(Direction::kLeft);
      break;
    }
    case app::KeyEvent::KEY_RIGHT:
    case app::KeyEvent::KEY_d: {
      engine_.SetDirection(Direction::kRight);
      break;
    }
  }
}
void MyApp::update() {
  if (currentShape->is_collided) {
    currentShape->is_collided = false;
    currentShape = engine_.ChooseBlock();
  } else if (currentShape->is_collided_end) {
    gameOver = false;
  }
  if (contactListener.toDestroy.size() >= 1) {
    currentScore += 10;
    MyApp::RemoveDrawing();
    myWorld->DestroyBody(contactListener.toDestroy[0]);
    myWorld->DestroyBody(contactListener.toDestroy[1]);
    contactListener.toDestroy.clear();
  }
  for (int i = 0; i < 10; ++i) {
    myWorld->Step(1 / 30.0f, 10, 10);

  }
}
void PrintText(const string& text, const Color& color, const cinder::ivec2& size,
               const cinder::vec2& loc) {
  cinder::gl::color(color);

  auto box = TextBox()
      .alignment(TextBox::CENTER)
      .font(cinder::Font("Arial", 30))
      .size(size)
      .color(color)
      .backgroundColor(ColorA(0, 0, 0, 0))
      .text(text);

  const auto box_size = box.getSize();
  const cinder::vec2 locp = {loc.x - box_size.x / 2, loc.y - box_size.y / 2};
  const auto surface = box.render();
  const auto texture = cinder::gl::Texture::create(surface);
  cinder::gl::draw(texture, locp);
}

void MyApp::draw() {
    gl::clear();
    DrawRightWall();
    DrawLeftWall();
    DrawSquare();
    DrawLine();
    DrawLShape();
    DrawBomb();
    DrawTShape();
    DrawZShape();
    DrawSShape();
    DrawScore();
  if (gameOver) {
    gl::clear();
    const cinder::vec2 center = getWindowCenter();
    const cinder::ivec2 size = {500, 50};
    Color white(1,1,1);
    PrintText("Game over", white, size, center);
    DrawScore();
  }

}
void MyApp::DrawScore() {
  std::stringstream ss;
  ss << "Score: " << currentScore;
  const cinder::ivec2 size = {250, 50};
  const cinder::vec2 loc = {120, 50};
  PrintText(ss.str(), Color::white(), size, loc);
}
void MyApp::DrawLShape() {
  for (const auto& l : myLShape) {
    gl::pushModelMatrix();
    gl::translate(l->m_body->GetPosition().x, l->m_body->GetPosition().y);
    gl::rotate(l->m_body->GetAngle());
    gl::color(l->color);
    PolyLine2f pi;
    pi.push_back(vec2(25, 75));
    pi.push_back(vec2(25, -75));
    pi.push_back(vec2(-25, -75));
    pi.push_back(vec2(-25, 75));
    gl::drawSolid(pi);
    PolyLine2f polyLine2F;
    polyLine2F.push_back(vec2(75, 75));
    polyLine2F.push_back(vec2(0, 75));
    polyLine2F.push_back(vec2(0, 25));
    polyLine2F.push_back(vec2(75, 25));
    gl::drawSolid(polyLine2F);

    gl::color(0, 0, 0);
    gl::begin(GL_LINES);
    gl::lineWidth(5);
    gl::vertex(-25, 25);
    gl::vertex(25, 25);
    gl::vertex(25, 25);
    gl::vertex(25, 75);
    gl::vertex(-25, -25);
    gl::vertex(25, -25);
    gl::end();

    gl::popModelMatrix();
  }
}
void MyApp::DrawSquare() {
  for (const auto& box : mySquare) {
    if (box->MarkForDelete) {
      continue;
    }
    gl::pushModelMatrix();
    gl::translate(box->m_body->GetPosition().x, box->m_body->GetPosition().y);
    gl::rotate(box->m_body->GetAngle());

    gl::color(box->color);

    gl::drawSolidRect(Rectf(-50, -50, 50, 50));

    gl::color(0, 0, 0);
    gl::begin(GL_LINES);
    gl::lineWidth(5);

    gl::vertex(0, 50);
    gl::vertex(0, -50);
    gl::vertex(50, 0);
    gl::vertex(-50, 0);

    gl::end();

    gl::popModelMatrix();
  }
}
void MyApp::DrawLine() {
  for (const auto& line : myLine) {
    if (line->remove) {
      continue;
    }
    gl::pushModelMatrix();
    gl::translate(line->m_body->GetPosition().x, line->m_body->GetPosition().y);
    gl::rotate(line->m_body->GetAngle());

    gl::color(line->color);

    gl::drawSolidRect(Rectf(-100, -25, 100, 25));

    gl::color(0, 0, 0);
    gl::begin(GL_LINES);
    gl::lineWidth(5);
    gl::vertex(0, 25);
    gl::vertex(0, -25);
    gl::vertex(50, 25);
    gl::vertex(50, -25);
    gl::vertex(-50, 25);
    gl::vertex(-50, -25);

    gl::end();

    gl::popModelMatrix();
  }
}
void MyApp::DrawBomb() {
  for (const auto& nShape : myBomb) {
    gl::pushModelMatrix();
    gl::translate(nShape->m_body->GetPosition().x,
                  nShape->m_body->GetPosition().y);
    gl::rotate(nShape->m_body->GetAngle());

    gl::color(nShape->color);
    gl::drawSolidCircle(vec2(0, 0), 50.0f);

    gl::popModelMatrix();
  }
}
void MyApp::DrawLeftWall() {
  gl::pushModelMatrix();
  gl::color(1, 1, 1);

  gl::drawSolidRect(Rectf(-10, getWindowHeight(), 10, -getWindowHeight()));
  gl::popModelMatrix();
}
void MyApp::DrawRightWall() {
  gl::pushModelMatrix();
  gl::translate(rightWall[0].m_body->GetPosition().x,
                rightWall[0].m_body->GetPosition().y);
  gl::color(1, 1, 1);

  gl::drawSolidRect(Rectf(-10, getWindowHeight(), 10, -getWindowHeight()));
  gl::popModelMatrix();
}
void MyApp::DrawTShape() {
  for (const auto& l : myTShape) {
    gl::pushModelMatrix();
    gl::translate(l->m_body->GetPosition().x, l->m_body->GetPosition().y);
    gl::rotate(l->m_body->GetAngle());

    gl::color(l->color);
    PolyLine2f pi;
    pi.push_back(vec2(25, 75));
    pi.push_back(vec2(25, -75));
    pi.push_back(vec2(-25, -75));
    pi.push_back(vec2(-25, 75));
    gl::drawSolid(pi);
    PolyLine2f polyLine2F;
    polyLine2F.push_back(vec2(-75, 75));
    polyLine2F.push_back(vec2(0, 75));
    polyLine2F.push_back(vec2(0, 25));
    polyLine2F.push_back(vec2(-75, 25));
    gl::drawSolid(polyLine2F);

    gl::color(0, 0, 0);
    gl::begin(GL_LINES);
    gl::lineWidth(5);
    gl::vertex(-25, 25);
    gl::vertex(25, 25);
    gl::vertex(-25, 25);
    gl::vertex(-25, 75);
    gl::vertex(-25, -25);
    gl::vertex(25, -25);
    gl::end();

    gl::popModelMatrix();
  }
}
void MyApp::DrawZShape() {
  for (const auto& box : myZShape) {

    gl::pushModelMatrix();
    gl::translate(box->m_body->GetPosition().x, box->m_body->GetPosition().y);
    gl::rotate(box->m_body->GetAngle());
    gl::color(box->color);

    PolyLine2f pi;
    pi.push_back(vec2(25, 50));
    pi.push_back(vec2(25, -50));
    pi.push_back(vec2(-25, -50));
    pi.push_back(vec2(-25, 50));

    gl::drawSolid(pi);
    PolyLine2f polyLine2F;
    polyLine2F.push_back(vec2(-75, 100));
    polyLine2F.push_back(vec2(-25, 100));
    polyLine2F.push_back(vec2(-25, 0));
    polyLine2F.push_back(vec2(-75, 0));
    gl::drawSolid(polyLine2F);

    gl::color(0, 0, 0);
    gl::begin(GL_LINES);
    gl::lineWidth(5);
    gl::vertex(-25, 0);
    gl::vertex(25, 0);
    gl::vertex(-25, 0);
    gl::vertex(-25, 50);
    gl::vertex(-25, 50);
    gl::vertex(-75, 50);
    gl::end();
    gl::popModelMatrix();
  }
}
void MyApp::DrawSShape() {
  for (const auto& box : mySShape) {

    gl::pushModelMatrix();
    gl::translate(box->m_body->GetPosition().x, box->m_body->GetPosition().y);
    gl::rotate(box->m_body->GetAngle());

    gl::color(box->color);

    PolyLine2f pi;
    pi.push_back(vec2(25, 50));
    pi.push_back(vec2(25, -50));
    pi.push_back(vec2(-25, -50));
    pi.push_back(vec2(-25, 50));

    gl::drawSolid(pi);
    PolyLine2f polyLine2F;
    polyLine2F.push_back(vec2(75, 100));
    polyLine2F.push_back(vec2(25, 100));
    polyLine2F.push_back(vec2(25, 0));
    polyLine2F.push_back(vec2(75, 0));
    gl::drawSolid(polyLine2F);

    gl::color(0, 0, 0);
    gl::begin(GL_LINES);
    gl::lineWidth(5);
    gl::vertex(-25, 0);
    gl::vertex(25, 0);
    gl::vertex(25, 0);
    gl::vertex(25, 50);
    gl::vertex(25, 50);
    gl::vertex(75, 50);
    gl::end();
    gl::popModelMatrix();
  }
}
void MyApp::RemoveDrawing() {
  for (int i = 0; i < myLShape.size(); i++) {
    if (myLShape[i]->lid == contactListener.id_fixtureA || myLShape[i]->lid == contactListener.id_fixtureB) {
      std::swap(myLShape[i], myLShape.back());
      myLShape.pop_back();
      i--;
    }
  }
  for (int i = 0; i < mySquare.size(); i++) {
    if (mySquare[i]->sid == contactListener.id_fixtureA || mySquare[i]->sid == contactListener.id_fixtureB) {
      std::swap(mySquare[i], mySquare.back());
      mySquare.pop_back();
      i--;
    }
  }
  for (int i = 0; i < myBomb.size(); i++) {
    if (myBomb[i]->bid == contactListener.id_fixtureA || myBomb[i]->bid == contactListener.id_fixtureB) {
      std::swap(myBomb[i], myBomb.back());
      myBomb.pop_back();
      i--;
    }
  }
  for (int i = 0; i < myTShape.size(); i++){
    int j = myTShape[i]->Tid;
  if (myTShape[i]->Tid == contactListener.id_fixtureA || myTShape[i]->Tid == contactListener.id_fixtureB) {
      std::swap(myTShape[i], myTShape.back());
      myTShape.pop_back();
      i--;
    }
  }
  for (int i = 0; i < myZShape.size(); i++) {
    if (myZShape[i]->Zid == contactListener.id_fixtureA || myZShape[i]->Zid == contactListener.id_fixtureB) {
      std::swap(myZShape[i], myZShape.back());
      myZShape.pop_back();
      i--;
    }
  }
  for (int i = 0; i < mySShape.size(); i++) {
    if (mySShape[i]->SSid == contactListener.id_fixtureB || mySShape[i]->SSid == contactListener.id_fixtureA) {
      std::swap(mySShape[i], mySShape.back());
      mySShape.pop_back();
      i--;
    }
  }
  for (int i = 0; i < myLine.size(); i++) {
    int j = myLine[i]->liid;
    if (myLine[i]->liid == contactListener.id_fixtureB || myLine[i]->liid == contactListener.id_fixtureA) {
      std::swap(myLine[i], myLine.back());
      myLine.pop_back();
      i--;
    }
  }
}
}  // namespace myapp
