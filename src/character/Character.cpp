#include "Character.h"

Character::Character(std::string name, uint16_t hp, uint16_t power_attack)
    : name{name}, hp{hp}, power_attack{power_attack} {}

void Character::apply_damage(uint16_t damage) {
  if (hp < damage) {
    hp = 0;
  } else {
    hp -= damage;
  }
}

void Character::do_attack(Character *character) {
  character->receive_damage(power_attack);
  std::cout << name << " attacks " << character->get_name() << "! "
            << character->get_name()
            << " HP: " << character->get_health_points() << std::endl;
}