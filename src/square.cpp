//
// Created by faris on 4/21/2020.
//

#include "mylibrary/square.h"
#include "cinder/gl/gl.h"

square::square(b2World* world, float size, const vec2 &pos) {
        b2BodyDef myBodyDef;
        myBodyDef.type = b2_dynamicBody;
        myBodyDef.position.Set(pos.x, pos.y);
        m_body = world->CreateBody(&myBodyDef);

        b2PolygonShape dynamicBox;
        dynamicBox.SetAsBox( 40, 40 );
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &dynamicBox;
        fixtureDef.density = 1.0f;
        fixtureDef.friction = 0.3f;
        fixtureDef.restitution = 0.5f; // bounce
        m_body->CreateFixture( &fixtureDef );
}
