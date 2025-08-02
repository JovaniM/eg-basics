#include "Enemy.h"

Enemy::Enemy(std::string name, uint16_t hp, uint16_t power_attack)
    : Character(name, hp, power_attack) {}

std::string Enemy::get_name() const { return name; }

uint16_t Enemy::get_health_points() const { return hp; }

void Enemy::receive_damage(uint16_t damage) { apply_damage(damage); }

void Enemy::attack(Character *character) { do_attack(character); }