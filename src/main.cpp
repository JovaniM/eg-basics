#include "character/Character.h"
#include "character/Enemy.h"
#include "character/Player.h"
#include <iostream>
#include <memory>

Character *simulate_battle(Character *character1, Character *character2) {
  while (character1->get_health_points() > 0 &&
         character2->get_health_points() > 0) {
    character1->attack(character2);
    if (character2->get_health_points() == 0) {
      return character1;
    }
    character2->attack(character1);
    if (character1->get_health_points() == 0) {
      return character2;
    }
  }
  return nullptr;
}

int main() {
  constexpr uint16_t HERO_HP = 100;
  constexpr uint16_t HERO_ATTACK = 30;
  constexpr uint16_t ENEMY_HP = 100;
  constexpr uint16_t ENEMY_ATTACK = 30;
  std::unique_ptr<Character> hero =
      std::make_unique<Player>("Hero", HERO_HP, HERO_ATTACK);
  std::unique_ptr<Character> enemy =
      std::make_unique<Enemy>("Enemy", ENEMY_HP, ENEMY_ATTACK);
  Character *winner = simulate_battle(hero.get(), enemy.get());
  if (winner != nullptr) {
    std::cout << winner->get_name() << " wins!" << std::endl;
  } else {
    std::cout << "None of those character won!" << std::endl;
  }
  return 0;
}