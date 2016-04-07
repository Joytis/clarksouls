//
// Created by Clark Burton Chambers on 4/4/16.
//

#ifndef CLARKSOULS_PLAYER_HPP
#define CLARKSOULS_PLAYER_HPP

#include "Includes.hpp"

// TODO(clark): pull these into a config file.
#define PLAYER_SPEED 50.0f

#define PLAYER_MAX_HEIGHT 548.0f
#define PLAYER_MAX_WIDTH 1052.0f
#define PLAYER_HOR_ACCEL 50.0f
#define PLAYER_HOR_DECEL 75.0f
#define PLAYER_VER_ACCEL 9.8f
#define PLAYER_JUMP_VELOCITY -10.0f

enum PlayerState {
    IDLE, WALKING, SLOWING, RUNNING,
    JUMPING, LIGHT_ATTACK, HEAVY_ATTACK
};



class Player {
private:

    int m_health;
    float m_height;
    float m_width;

    float m_speed;
    float x;
    float y;

    Velocity m_velocity;

    sf::Sprite m_sprite;

    // Animation and logical state
    PlayerState m_state;

public:


//------------------------------------
    // Getters and Setters
    //------------------------------------
    const PlayerState &getState() const {
        return m_state;
    }

    const sf::Sprite &getM_sprite() const {
        return m_sprite;
    }

    int getHealth() const {
        return m_health;
    }

    void setHealth(int m_health) {
        Player::m_health = m_health;
    }

    void SetState(const PlayerState &m_state) {
        Player::m_state = m_state;
    }


    //------------------------------------
    // Public Member Functions
    //------------------------------------
    Player();

    // Returns current health (m_health) of player
    int getHealth();

    void SetHealth(int newhp);

    void SetTexture(TextureManager *texman, std::string key);

    // Error prone:
    // Exceptions:
    //      e_unhandled_state: The state in the player is unhandled.
    void HandleInput(Input *input);

    void move();
    void jump();
    void slow(float deltaTime);
    void lightattack();
    void heavyattack();

    void update(float deltaTime, Input *input);

    void render();

};


#endif //CLARKSOULS_PLAYER_HPP
