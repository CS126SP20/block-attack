//
// Created by faris on 5/5/2020.
//

#ifndef FINALPROJECT_ENGINE_H
#define FINALPROJECT_ENGINE_H

#include <Box2D/Dynamics/b2World.h>

#include <vector>

#include "Bomb.h"
#include "LShape.h"
#include "SShape.h"
#include "SideWallLeft.h"
#include "SideWallRight.h"
#include "TShape.h"
#include "ZShape.h"
#include "line.h"
#include "square.h"
#include "mylibrary/direction.h"
namespace myapp {
class engine {
  Direction direction;
 public:
  engine();
  engine(b2World* world, std::vector<square*>& mySquare, std::vector<line*>& myLine,
         std::vector<LShape*>& myLShape, std::vector<Bomb*>& myBomb, std::vector<TShape*>& myTShape,
         std::vector<ZShape*>& myZShape, std::vector<SShape*>& mySShape);
  b2World* myWorld;
  std::vector<square*>* myS;
  std::vector<line*>* myL;
  std::vector<LShape*>* myLS;
  std::vector<Bomb*>* myB;
  std::vector<TShape*>* myT;
  std::vector<ZShape*>* myZ;
  std::vector<SShape*>  * mySS;
  b2Body* currentBody;
  Shape* currentShape;
  Shape* ChooseBlock();
  /**
   * Sets the direction based on the key pressed
   * @param direction the direction the user wants to go.
   */
  void SetDirection(const myapp::Direction direction);
  /**
   * Moves the object the given direction
   * @param direction Direction object should move
   */
  void MoveObject(const myapp::Direction direction);

  void RemoveDrawing(std::vector<b2Body*> toDestroy);
};
}

#endif  // FINALPROJECT_ENGINE_H
