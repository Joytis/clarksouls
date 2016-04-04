//
// Created by Clark Burton Chambers on 4/4/16.
//

#ifndef CLARKSOULS_PLAYER_HPP
#define CLARKSOULS_PLAYER_HPP

#include "Includes.hpp"

enum PlayerState {
    IDLE, WALKING, RUNNING, JUMPING,
    LIGHT_ATTACK, HEAVY_ATTACK
};

class Player {
private:

    int m_health;
    int m_height;
    int m_width;

    float m_speed;
    float m_xpos;
    float m_ypos;

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
    ~Player();

    // Returns current health (m_health) of player
    int getHealth();

    void SetHealth(int newhp);

    void SetTexture(TextureManager *texman, std::string key);

    // Error prone:
    // Exceptions:
    //      e_unhandled_state: The state in the player is unhandled.
    void HandleInput(Input *input);

    void Move();

    void update();

    void render();

};


#endif //CLARKSOULS_PLAYER_HPP
