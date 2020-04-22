// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <cinder/app/App.h>
#include <mylibrary/square.h>
#include "Box2D/Box2D.h"
#include "cinder/gl/gl.h"


namespace myapp {
using namespace ci;

    const float BOX_SIZE = 10;

    b2World* myWorld;
    std::vector<square> myBox;
    MyApp::MyApp() {}

    void MyApp::setup() {
        b2Vec2 gravity(0.0f, 9.8f);
        myWorld = new b2World(gravity);
        b2BodyDef groundBodyDef;
        groundBodyDef.position.Set(0.0f, getWindowHeight());
        b2Body* groundBody = myWorld->CreateBody(&groundBodyDef);

        b2PolygonShape groundBox;
        groundBox.SetAsBox(getWindowWidth(), 10.0f);
        groundBody->CreateFixture(&groundBox,0.0f);
    }

    void MyApp::mouseDown(cinder::app::MouseEvent event) {
        square square(myWorld, BOX_SIZE, event.getPos());
        myBox.push_back(square);
    }
    void MyApp::update() {
        for( int i = 0; i < 10; ++i ) {
            myWorld->Step( 1 / 30.0f, 10, 10 );
            }
    }

    void MyApp::draw() {
    DrawSquare();
    }
    void MyApp::DrawSquare() {
//        gl::clear();
        gl::color( 1, 0, 0);
        for( const auto &box : myBox ) {
            gl::pushModelMatrix();
            gl::translate( box.m_body->GetPosition().x, box.m_body->GetPosition().y );
            gl::rotate( box.m_body->GetAngle() );

            gl::drawSolidRect( Rectf( -40, -40, 40, 40 ) );

            gl::popModelMatrix();
        }
    }




}  // namespace myapp
