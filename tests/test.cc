// Copyright (c) 2020 CS126SP20. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <Box2D/Box2D.h>
#include <mylibrary/Ceiling.h>
#include <mylibrary/LShape.h>
#include <mylibrary/SShape.h>
#include <mylibrary/TShape.h>
#include <mylibrary/ZShape.h>
#include <mylibrary/line.h>
#include <mylibrary/square.h>
#include <mylibrary/engine.h>

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
  int width = 10;
  int height = 10;
  Ceiling ceiling(myWorld, width, height);
  REQUIRE(myWorld->GetBodyList() == ceiling.body);
}
TEST_CASE("lshape-test", "[lshape-test]") {
  b2Vec2 grav(0.0f, 1.0f);
  b2World* myWorld = new b2World(grav);
  LShape lshape(myWorld, vec2(0.0,1.0));
  REQUIRE(myWorld->GetBodyList() == lshape.m_body);
}
TEST_CASE("SShape-Test", "[SShape-Test]") {
  b2Vec2 grav(0.0f, 1.0f);
  b2World* myWorld = new b2World(grav);
  SShape sShape(myWorld, vec2(0.0,1.0));
  REQUIRE(myWorld->GetBodyList() == sShape.m_body);
}
TEST_CASE("square-test", "[square-test]") {
  b2Vec2 grav(0.0f, 1.0f);
  b2World* myWorld = new b2World(grav);
  square square(myWorld, vec2(0.0, 1.0));
  REQUIRE(myWorld->GetBodyList() == square.m_body);
}
TEST_CASE("TShape-Test", "[tshape-test]") {
  b2Vec2 grav(0.0f, 1.0f);
  b2World* myWorld = new b2World(grav);
  TShape tShape(myWorld, vec2(0.0, 1.0));
  REQUIRE(myWorld->GetBodyList() == tShape.m_body);
}
TEST_CASE("ZShape-Test", "[zshape-test]") {
  b2Vec2 grav(0.0f, 1.0f);
  b2World* myWorld = new b2World(grav);
  ZShape zShape(myWorld, vec2(0.0, 1.0));
  REQUIRE(myWorld->GetBodyList() == zShape.m_body);
}