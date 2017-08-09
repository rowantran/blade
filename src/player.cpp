#include "player.h"
#include "settings.h"

#include <iostream>

Player::Player(SDL_Renderer* renderer, float x, float y) :
Entity("data/sprites/player.png", renderer, 9, 150, 25, 717, 32, 49, 30, 200, 200, settings::PLAYER_HEALTH),
dx(0),
dy(0) {}

void Player::moveLeft() {
    dx = -1 * settings::PLAYER_MOVE_SPEED;
}

void Player::moveRight() {
    dx = settings::PLAYER_MOVE_SPEED;
}

void Player::stop() {
    dx = 0;
}

void Player::update(float timeElapsed) {
    AnimatedSprite::update(timeElapsed);
    location.x += dx;
    location.y += dy;
}