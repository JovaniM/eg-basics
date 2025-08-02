#ifndef EG_CHARACTER_H
#define EG_CHARACTER_H
#include <cstdint>
#include <iostream>
#include <string>

class Character {
public:
  Character(std::string name, uint16_t hp, uint16_t power_attack);
  virtual std::string get_name() const = 0;
  virtual uint16_t get_health_points() const = 0;
  virtual void receive_damage(uint16_t damage) = 0;
  virtual void attack(Character *character) = 0;
  virtual ~Character() = default;

protected:
  std::string name;
  uint16_t hp = 0;
  uint16_t power_attack = 0;

  void apply_damage(uint16_t damage);
  void do_attack(Character *character);
};
#endif