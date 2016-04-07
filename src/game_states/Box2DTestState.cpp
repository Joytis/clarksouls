//
// Created by Clark Burton Chambers on 4/7/16.
//

#include "Box2DTestState.hpp"
#include "../Input.hpp"

Box2DTestState::Box2DTestState(StateSystem *system){
    m_stateSystem = system;

    b2Vec2 gravity(GRAVITY);
    try {
        m_world = new b2World(gravity);
        check_mem(m_world);
        b2BodyDef groundBodyDef;
        groundBodyDef.position.Set(0.0f, -10.0f);

        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        bodyDef.position.Set(0.0f, 4.0f);

        groundBody = m_world->CreateBody(&groundBodyDef);
        check_mem(groundBody);

        b2PolygonShape groundBox;
        groundBox.SetAsBox(50.0f, 10.0f);
        groundBody->CreateFixture(&groundBox, 0.0f);


        // Dynamics
        body = m_world->CreateBody(&bodyDef);
        check_mem(body);

        b2PolygonShape dynamicBox;
        dynamicBox.SetAsBox(1.0f, 1.0f);

        b2FixtureDef fixtureDef;
        fixtureDef.density = 1.0f;
        fixtureDef.friction = 0.3f;
        fixtureDef.shape = &dynamicBox;

        body->CreateFixture(&fixtureDef);

    }
    catch(const e_bad_allocation &e)
    {
        delete(m_world);
        // TODO(clark): Maybe test this? This is a test world
        exit(1);
    }


}

void Box2DTestState::begin()
{

}
void Box2DTestState::end()
{

}

void Box2DTestState::update(float deltaTime, Input *input)
{
    // Update b2 world
    m_world->Step(CLSB2_TIME_STEP, CLSB2_VELOCITY_ITTERATIONS, CLSB2_POSITION_ITTERATIONS);
    b2Vec2 position = body->GetPosition();
    float32 angle = body->GetAngle();
    log_info("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);

    // Inputs!
    if (input->States.LightAttack.IsPressed){
        m_stateSystem->PopState();
        m_stateSystem->PushState(GS_CHAR_TEST);
    }
}
void Box2DTestState::render(sf::RenderWindow *window)
{

}