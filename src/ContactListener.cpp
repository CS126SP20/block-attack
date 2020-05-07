//
// Created by faris on 5/5/2020.
//

#include "mylibrary/ContactListener.h"

#include <string>

namespace myapp {

void myapp::ContactListener::BeginContact(b2Contact *contact) {
  Shape *userData = (Shape *)contact->GetFixtureA()->GetBody()->GetUserData();
  Shape *userData1 = (Shape *)contact->GetFixtureB()->GetBody()->GetUserData();
  Color compareColor = userData->color;
  Color compareColor1 = userData1->color;

  int compare = userData->GetShapeType;
  if (compare == 0 && !userData->is_collided && userData1->GetShapeType != -1) {
    static_cast<square *>(userData)->is_collided = true;
  } else if (compare == 1 && !userData->is_collided &&
             userData1->GetShapeType != -1) {
    static_cast<ZShape *>(userData)->is_collided = true;

  } else if (compare == 2 && !userData->is_collided &&
             userData1->GetShapeType != -1) {
    static_cast<TShape *>(userData)->is_collided = true;

  } else if (compare == 3 && !userData->is_collided &&
             userData1->GetShapeType != -1) {
    static_cast<SShape *>(userData)->is_collided = true;

  } else if (compare == 4 && !userData->is_collided &&
             userData1->GetShapeType != -1) {
    static_cast<LShape *>(userData)->is_collided = true;

  } else if (compare == 5 && !userData->is_collided &&
             userData1->GetShapeType != -1) {
    static_cast<line *>(userData)->is_collided = true;
  } else if (compare == 0 && !userData->is_collided &&
             userData1->GetShapeType == -3) {
    static_cast<square *>(userData)->is_collided_end = true;
  } else if (compare == 1 && !userData1->is_collided &&
             userData->GetShapeType == -3) {
    static_cast<ZShape *>(userData1)->is_collided_end = true;
  } else if (compare == 2 && !userData1->is_collided &&
             userData->GetShapeType == -3) {
    static_cast<TShape *>(userData1)->is_collided_end = true;
  } else if (compare == 3 && !userData1->is_collided &&
             userData->GetShapeType == -3) {
    static_cast<SShape *>(userData1)->is_collided_end = true;
  } else if (compare == 4 && !userData1->is_collided &&
             userData->GetShapeType == -3) {
    static_cast<LShape *>(userData1)->is_collided_end = true;
  } else if (compare == 5 && !userData1->is_collided &&
             userData->GetShapeType == -3) {
    static_cast<line *>(userData1)->is_collided_end = true;
  }

  compare = userData1->GetShapeType;
  if (compare == 0 && !userData1->is_collided && userData->GetShapeType != -1) {
    static_cast<square *>(userData1)->is_collided = true;

  } else if (compare == 1 && !userData1->is_collided &&
             userData->GetShapeType != -1) {
    static_cast<ZShape *>(userData1)->is_collided = true;

  } else if (compare == 2 && !userData1->is_collided &&
             userData->GetShapeType != -1) {
    static_cast<TShape *>(userData1)->is_collided = true;
  } else if (compare == 3 && !userData1->is_collided &&
             userData->GetShapeType != -1) {
    static_cast<SShape *>(userData1)->is_collided = true;

  } else if (compare == 4 && !userData1->is_collided &&
             userData->GetShapeType != -1) {
    static_cast<LShape *>(userData1)->is_collided = true;

  } else if (compare == 5 && !userData1->is_collided &&
             userData->GetShapeType != -1) {
    static_cast<line *>(userData1)->is_collided = true;
  } else if (compare == 0 && !userData1->is_collided &&
             userData->GetShapeType == -3) {
    static_cast<square *>(userData1)->is_collided_end = true;
  } else if (compare == 1 && !userData1->is_collided &&
             userData->GetShapeType == -3) {
    static_cast<ZShape *>(userData1)->is_collided_end = true;
  } else if (compare == 2 && !userData1->is_collided &&
             userData->GetShapeType == -3) {
    static_cast<TShape *>(userData1)->is_collided_end = true;
  } else if (compare == 3 && !userData1->is_collided &&
             userData->GetShapeType == -3) {
    static_cast<SShape *>(userData1)->is_collided_end = true;
  } else if (compare == 4 && !userData1->is_collided &&
             userData->GetShapeType == -3) {
    static_cast<LShape *>(userData1)->is_collided_end = true;
  } else if (compare == 5 && !userData1->is_collided &&
             userData->GetShapeType == -3) {
    static_cast<line *>(userData1)->is_collided_end = true;
  }

  if (compareColor == compareColor1) {
    userData->MarkForDelete;
    userData1->MarkForDelete;
    toDestroy.push_back(contact->GetFixtureA()->GetBody());
    toDestroy.push_back(contact->GetFixtureB()->GetBody());
  }
}
}  // namespace myapp
