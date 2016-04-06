//
// Created by Clark Burton Chambers on 4/4/16.
//

#include "Player.hpp"
#include "Includes.hpp"
#include "Input.hpp"


// Forward declerations
float Accel(float velocity, float accel, float deltaTime);

//--------------------------------
// Class Definitions!
//--------------------------------

Player::Player() {


    m_health = 5;
    m_height = 100.0f;
    m_width = 100.0f;

    m_speed = PLAYER_SPEED;
    x = 100.0f;
    y = 100.0f;

    // init to 0
    m_velocity.velocity = 0.0f;
    m_velocity.horVelocity = 0.0f;
    m_velocity.verVelocity = 0.0f;

    // Animation and logical state
    m_state = IDLE;

}

void Player::SetTexture(TextureManager *texman, std::string key)
{
    try {
        m_sprite.setTexture(*texman->GetTexture(key));
        m_sprite.setScale(m_width/m_sprite.getLocalBounds().width,
                          m_height/m_sprite.getLocalBounds().height);
    }
    catch (const e_manager_obj_dne &e) {
        // TODO(clark): Handle this?
        try {
            m_sprite.setTexture(*texman->GetTexture("error"));
        }
        catch (const e_manager_obj_dne &e) {
            // TODO(clark): Handle this or just break?
            exit(1);
        }

    }

}

void Player::HandleInput(Input *input) {

}

void Player::move() {
    x += m_velocity.horVelocity;
    y += m_velocity.verVelocity;

    // :O
    if(x > PLAYER_MAX_WIDTH)
    {
        x = PLAYER_MAX_WIDTH;
        m_velocity.horVelocity = 0;
    }
    else if (x < 0.0f)
    {
        x = 0.0f;
        m_velocity.horVelocity = 0;
    }

    // :D
    if(y > PLAYER_MAX_HEIGHT)
    {
        y = PLAYER_MAX_HEIGHT;
        m_velocity.verVelocity = 0;
    }
    else if(y < 0)
    {
        y = 0;
        m_velocity.verVelocity = 0;
    }


    m_sprite.setPosition(x, y);
}

void Player::jump()
{
    m_velocity.verVelocity = PLAYER_JUMP_VELOCITY;
}

void Player::slow(float deltaTime)
{
    if(m_velocity.horVelocity > 0)
    {
        m_velocity.horVelocity = Accel(m_velocity.horVelocity, -PLAYER_HOR_DECEL, deltaTime);
        if(m_velocity.horVelocity < 0) m_velocity.horVelocity = 0;
    }

    else {
        m_velocity.horVelocity = Accel(m_velocity.horVelocity, PLAYER_HOR_DECEL, deltaTime);
        if(m_velocity.horVelocity > 0) m_velocity.horVelocity = 0;
    }

}

void Player::lightattack()
{
    m_state = LIGHT_ATTACK;
}

void Player::heavyattack()
{
    m_state = HEAVY_ATTACK;
}


void Player::update(float deltaTime, Input *input) {

    // Handling a ton of input

    //------------------------------
    // Horizontal accelleration test
    //------------------------------
//    if(input->States.Right.IsDown)
//    {
//        m_velocity.horVelocity = Accel(m_velocity.horVelocity, PLAYER_HOR_ACCEL, deltaTime);
//    }
//    if(input->States.Left.IsDown)
//    {
//        m_velocity.horVelocity = Accel(m_velocity.horVelocity, -PLAYER_HOR_ACCEL, deltaTime);
//    }

    //------------------------------
    // Jump Accelleration test
    //------------------------------
//    if(input->States.Jump.IsPressed)
//    {
//        m_velocity.verVelocity = PLAYER_JUMP_VELOCITY;
//    }
    m_velocity.verVelocity = Accel(m_velocity.verVelocity, PLAYER_VER_ACCEL, deltaTime);

    try {
        switch (m_state) {
            case IDLE:
                if(input->States.Jump.IsPressed) {
                    jump();
                    m_state = JUMPING;
                }
                if(input->States.Right.IsDown)
                {
                    m_velocity.horVelocity = Accel(m_velocity.horVelocity, PLAYER_HOR_ACCEL, deltaTime);
                    m_state = WALKING;
                }
                if(input->States.Left.IsDown)
                {
                    m_velocity.horVelocity = Accel(m_velocity.horVelocity, -PLAYER_HOR_ACCEL, deltaTime);
                    m_state = WALKING;
                }
                break;

            case WALKING:
                if(input->States.Jump.IsPressed) {
                    jump();
                    m_state = JUMPING;
                }
                if(input->States.Right.IsDown)
                {
                    m_velocity.horVelocity = Accel(m_velocity.horVelocity, PLAYER_HOR_ACCEL, deltaTime);
                    m_state = WALKING;
                }
                if(input->States.Left.IsDown)
                {
                    m_velocity.horVelocity = Accel(m_velocity.horVelocity, -PLAYER_HOR_ACCEL, deltaTime);
                    m_state = WALKING;
                }
                if(!input->States.Left.IsDown && !input->States.Right.IsDown)
                {
                    m_state = SLOWING;
                }
                break;

            case SLOWING:
                if(input->States.Jump.IsPressed) {
                    jump();
                    m_state = JUMPING;
                }
                if(input->States.Right.IsDown || input->States.Left.IsDown)
                {
                    m_state = WALKING;
                }
                if(m_velocity.horVelocity != 0){
                    slow(deltaTime);
                }
                else {
                    m_state = IDLE;
                }
                break;

            case RUNNING:
                break;

            case JUMPING:
                m_state = WALKING;
                break;

            case LIGHT_ATTACK:
                m_state = IDLE;
                break;

            case HEAVY_ATTACK:
                m_state = IDLE;
                break;
            default: sentinel(e_unhandled_state, "Unhandled state")
        }
    }
    catch (const e_unhandled_state &e) {

    }

    move();
}

void Player::render() {

}

//--------------------------------
// Private Helper Functions;
//--------------------------------
// Returns a new velocity
float Accel(float velocity, float accel, float deltaTime)
{
    velocity += accel*deltaTime;
    return velocity;
}


