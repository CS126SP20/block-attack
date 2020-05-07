//
// Created by faris on 5/5/2020.
//

#include "mylibrary/engine.h"

#include <cinder/Rand.h>
#include <mylibrary/ContactListener.h>
#include <mylibrary/Shape.h>
#include <mylibrary/TShape.h>
namespace myapp {
int history = 0;
myapp::engine::engine() = default;
myapp::engine::engine(b2World* world, std::vector<square*>& mySquare,
                      std::vector<line*>& myLine,
                      std::vector<LShape*>& myLShape,
                      std::vector<Bomb*>& myBomb,
                      std::vector<TShape*>& myTShape,
                      std::vector<ZShape*>& myZShape,
                      std::vector<SShape*>& mySShape) {
  myWorld = world;
  myS = &mySquare;
  myL = &myLine;
  myLS = &myLShape;
  myB = &myBomb;
  myT = &myTShape;
  myZ = &myZShape;
  mySS = &mySShape;
}

Shape* myapp::engine::ChooseBlock() {
  if (currentBody != nullptr && currentShape != nullptr &&
      !currentShape->is_collided) {
    currentBody->SetLinearDamping(0.060);
    currentBody->SetAngularDamping(0.060f);
  }

  srand(time(NULL));
  int j = floor(rand() % 10);
  while (history == j) {
    j = floor(rand() % 10);
  }
  Color color;
  switch (j) {
    case 0: {
      color = Color(0, 1, 0);
      break;
    }
    case 1: {
      color = Color(1, 1, 0);
      break;
    }
    case 2: {
      color = Color(0, 1, 1);
      break;
    }
    case 3: {
      color = Color(0, 0, 1);
      break;
    }
    case 4: {
      color = Color(1, 0, 0);
      break;
    }
    case 5: {
      color = Color(1, 0, 1);
      break;
    }
    case 6: {
      color = Color(1, 1, 1);
      break;
    }
    case 7: {
      color = Color(1, 0.5, 1);
      break;
    }
    case 8: {
      color = Color(0.5, 0.5, 1);
      break;
    }
    case 9: {
      color = Color(0.5, 0.5, 0.5);
      break;
    }
  }

  j = floor(rand() % 6);
  while (history == j) {
    j = floor(rand() % 6);
  }
  switch (j) {
    case 0: {
      TShape* tShape = (TShape*)new class TShape(myWorld, vec2(500, 50));
      tShape->color = color;
      myT->push_back(tShape);
      currentShape = tShape;
      currentBody = tShape->m_body;
      return tShape;
    }
    case 1: {
      line* line = new class line(myWorld, vec2(500, 50));
      line->color = color;
      myL->push_back(line);
      currentShape = line;
      currentBody = line->m_body;
      return line;
    }
    case 2: {
      LShape* lShape = (LShape*)new LShape(myWorld, vec2(500, 50));
      lShape->color = color;
      myLS->push_back(lShape);
      currentShape = lShape;
      currentBody = lShape->m_body;
      return lShape;
    }
    case 3: {
      ZShape* zShape = new class ZShape(myWorld, vec2(500, 50));
      zShape->color = color;
      myZ->push_back(zShape);
      currentShape = zShape;
      currentBody = zShape->m_body;
      return zShape;
    }
    case 4: {
      square* square = new class square(myWorld, vec2(500, 50));
      square->color = color;
      myS->push_back(square);
      currentShape = square;
      currentBody = square->m_body;
      return square;
    }
    case 5: {
      SShape* sShape = new class SShape(myWorld, vec2(500, 50));
      sShape->color = color;
      mySS->push_back(sShape);
      currentShape = sShape;
      currentBody = sShape->m_body;
      return sShape;
    }
  }
  history = j;
}
void engine::SetDirection(const Direction di) { MoveObject(di); }
void engine::MoveObject(const Direction di) {
  switch (di) {
    case Direction::kUp: {
      currentBody->SetAngularDamping(0.05f);
      currentBody->SetAngularVelocity(0.09f);
      break;
    }
    case Direction::kDown: {
      currentBody->SetAngularDamping(0.05f);
      currentBody->SetAngularVelocity(-0.09f);
      break;
    }
    case Direction::kRight: {
      b2Vec2 vel = currentBody->GetLinearVelocity();
      vel.x = 10;
      currentBody->SetLinearVelocity(vel);
      break;
    }
    case Direction::kLeft: {
      b2Vec2 vel = currentBody->GetLinearVelocity();
      vel.x = -10;
      currentBody->SetLinearVelocity(vel);
      break;
    }
  }
}

}  // namespace myapp
