#include "Player.h"

Player::Player(const std::string &name, uint16_t hp, uint16_t power_attack)
    : Character(name, hp, power_attack) {}

std::string Player::get_name() const { return name; }

uint16_t Player::get_health_points() const { return hp; }

void Player::receive_damage(uint16_t damage) { apply_damage(damage); }

void Player::attack(Character *character) { do_attack(character); }