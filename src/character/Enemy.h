#ifndef EG_ENEMY_H
#define EG_ENEMY_H
#include "Character.h"

class Enemy : public Character {
public:
  Enemy(std::string name, uint16_t hp, uint16_t power_attack);
  std::string get_name() const override;
  uint16_t get_health_points() const override;
  void receive_damage(uint16_t damage) override;
  void attack(Character *character) override;
  virtual ~Enemy() = default;
};

#endif