//
// Created by faris on 5/5/2020.
//

#include "mylibrary/ContactListener.h"

#include <string>

#include "mylibrary/Shape.h"

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
  }
  if (compare == 0 && !userData->is_collided &&
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

  int compare1 = userData1->GetShapeType;
  if (compare1 == 0 && !userData1->is_collided &&
      userData->GetShapeType != -1) {
    static_cast<square *>(userData1)->is_collided = true;

  } else if (compare1 == 1 && !userData1->is_collided &&
             userData->GetShapeType != -1) {
    static_cast<ZShape *>(userData1)->is_collided = true;

  } else if (compare1 == 2 && !userData1->is_collided &&
             userData->GetShapeType != -1) {
    static_cast<TShape *>(userData1)->is_collided = true;
  } else if (compare1 == 3 && !userData1->is_collided &&
             userData->GetShapeType != -1) {
    static_cast<SShape *>(userData1)->is_collided = true;

  } else if (compare1 == 4 && !userData1->is_collided &&
             userData->GetShapeType != -1) {
    static_cast<LShape *>(userData1)->is_collided = true;

  } else if (compare1 == 5 && !userData1->is_collided &&
             userData->GetShapeType != -1) {
    static_cast<line *>(userData1)->is_collided = true;
  }

  if (compare1 == 0 && !userData1->is_collided &&
             userData->GetShapeType == -3) {
    static_cast<square *>(userData1)->is_collided_end = true;
  } else if (compare1 == 1 && !userData1->is_collided &&
             userData->GetShapeType == -3) {
    static_cast<ZShape *>(userData1)->is_collided_end = true;
  } else if (compare1 == 2 && !userData1->is_collided &&
             userData->GetShapeType == -3) {
    static_cast<TShape *>(userData1)->is_collided_end = true;
  } else if (compare1 == 3 && !userData1->is_collided &&
             userData->GetShapeType == -3) {
    static_cast<SShape *>(userData1)->is_collided_end = true;
  } else if (compare1 == 4 && !userData1->is_collided &&
             userData->GetShapeType == -3) {
    static_cast<LShape *>(userData1)->is_collided_end = true;
  } else if (compare1 == 5 && !userData1->is_collided &&
             userData->GetShapeType == -3) {
    static_cast<line *>(userData1)->is_collided_end = true;
  }

  if (compareColor == compareColor1) {
    if (compare == 0 && userData1->GetShapeType != -1) {
      square *userData3 =
          (square *)contact->GetFixtureA()->GetBody()->GetUserData();
      id_fixtureA = (userData3)->sid;
    } else if (compare == 1 && userData1->GetShapeType != -1) {
      ZShape *userData3 =
          (ZShape *)contact->GetFixtureA()->GetBody()->GetUserData();
      id_fixtureA = (userData3)->Zid;
    } else if (compare == 2 && userData1->GetShapeType != -1) {
      TShape *userData3 =
          (TShape *)contact->GetFixtureA()->GetBody()->GetUserData();
      id_fixtureA = (userData3)->Tid;

    } else if (compare == 3 && userData1->GetShapeType != -1) {
      SShape *userData3 =
          (SShape *)contact->GetFixtureA()->GetBody()->GetUserData();
      id_fixtureA = (userData3)->SSid;

    } else if (compare == 4 && userData1->GetShapeType != -1) {
      LShape *userData2 =
          (LShape *)contact->GetFixtureA()->GetBody()->GetUserData();
      id_fixtureA = (userData2)->lid;

    } else if (compare == 5 && userData1->GetShapeType != -1) {
      line *userData3 =
          (line *)contact->GetFixtureA()->GetBody()->GetUserData();
      id_fixtureA = (userData3)->liid;
    }

    if (compare1 == 0 && userData->GetShapeType != -1) {
      square *userData3 =
          (square *)contact->GetFixtureB()->GetBody()->GetUserData();
      id_fixtureB = (userData3)->sid;

    } else if (compare1 == 1 && userData->GetShapeType != -1) {
      ZShape *userData3 =
          (ZShape *)contact->GetFixtureB()->GetBody()->GetUserData();
      id_fixtureB = (userData3)->Zid;

    } else if (compare1 == 2 && userData->GetShapeType != -1) {
      TShape *userData3 =
          (TShape *)contact->GetFixtureB()->GetBody()->GetUserData();
      id_fixtureB = (userData3)->Tid;

    } else if (compare1 == 3 && userData->GetShapeType != -1) {
      SShape *userData3 =
          (SShape *)contact->GetFixtureB()->GetBody()->GetUserData();
      id_fixtureB = (userData3)->SSid;

    } else if (compare1 == 4 && userData->GetShapeType != -1) {
      LShape *userData3 = (LShape *)contact->GetFixtureB()->GetBody()->GetUserData();
      id_fixtureB = (userData3)->lid;

    } else if (compare1 == 5 && userData->GetShapeType != -1) {
      line *userData3 =
          (line *)contact->GetFixtureB()->GetBody()->GetUserData();
      id_fixtureB = (userData3)->liid;
    }

    toDestroy.push_back(contact->GetFixtureA()->GetBody());
    toDestroy.push_back(contact->GetFixtureB()->GetBody());
  }
}
}  // namespace myapp