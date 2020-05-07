// Copyright (c) 2020 CS126SP20. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <Box2D/Box2D.h>
#include <mylibrary/Ceiling.h>
#include <mylibrary/line.h>

#include <catch2/catch.hpp>

TEST_CASE("correct-world-generation-test", "[world-generation-test]") {
  b2Vec2 grav(0.0f, 1.0f);
  b2World* myWorld = new b2World(grav);
  REQUIRE(myWorld->GetGravity() == grav);
}
TEST_CASE("line-test", "[line-test]") {
  b2Vec2 grav(0.0f, 1.0f);
  b2World* myWorld = new b2World(grav);
  line line(myWorld, vec2(0.0, 1.0));
  REQUIRE(myWorld->GetBodyList() == line.m_body);
}
TEST_CASE("ceiling-test", "[ceiling-test]") {
  b2Vec2 grav(0.0f, 1.0f);
  b2World* myWorld = new b2World(grav);
  Ceiling ceiling(myWorld, vec2(0.0, 1.0));

}