//
// Created by Clark Burton Chambers on 4/4/16.
//

#include "Player.hpp"

Player::Player() {


    m_health = 5;
    m_height = 100;
    m_width = 100;

    m_speed = 50;
    m_xpos = 100.0f;
    m_ypos = 100.0f;

    // Animation and logical state
    m_state = IDLE;

}

void Player::SetTexture(TextureManager *texman, std::string key)
{
    try {
        m_sprite.setTexture(*texman->GetTexture(key));
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

    // Handling a ton of input
    switch(m_state) {
        case IDLE:
            break;
        case WALKING:
            break;
        case RUNNING:
            break;
        case JUMPING:
            break;
        case LIGHT_ATTACK:
            break;
        case HEAVY_ATTACK:
            break;
        default:
            sentinel(e_unhandled_state, "Unhandled state")

    }
}

void Player::Move() {

}

void Player::update() {

}

void Player::render() {

}


