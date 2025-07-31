#include "player.h"

Player::Player(std::string name, uint16_t hp) : name{name}, hp{hp} {}

std::string Player::get_name() const { return name; }