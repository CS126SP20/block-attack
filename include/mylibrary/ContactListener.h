//
// Created by faris on 5/5/2020.
//

#ifndef FINALPROJECT_CONTACTLISTENER_H
#define FINALPROJECT_CONTACTLISTENER_H
#include <Box2D/Box2D.h>
#include <mylibrary/square.h>
#include <mylibrary/engine.h>
namespace myapp {
class ContactListener : public b2ContactListener {
 public:
  void BeginContact(b2Contact* contact) override;
  std::vector<b2Body*> toDestroy;
  int id_fixtureA = -1;
  int id_fixtureB = -1;

  };
}  // namespace game
#endif  // FINALPROJECT_CONTACTLISTENER_H
