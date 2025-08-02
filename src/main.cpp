#include "character/Character.h"
#include "character/Enemy.h"
#include "character/Player.h"
#include <iostream>
#include <memory>

int main() {
  std::unique_ptr<Character> hero = std::make_unique<Player>("Hero", 200, 30);
  std::unique_ptr<Character> enemy = std::make_unique<Enemy>("Enemy", 100, 25);
  Character *winner = nullptr;
  while (hero->get_health_points() > 0 && enemy->get_health_points() > 0) {
    hero->attack(enemy.get());
    if (enemy->get_health_points() == 0) {
      winner = hero.get();
      break;
    }
    enemy->attack(hero.get());
    if (hero->get_health_points() == 0) {
      winner = enemy.get();
      break;
    }
  }
  if (winner != nullptr) {
    std::cout << winner->get_name() << " wins!" << std::endl;
  } else {
    std::cout << "None of those character won!" << std::endl;
  }
  return 0;
}