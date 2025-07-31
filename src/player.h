#ifndef EG_PLAYER_H
#define EG_PLAYER_H
#include <cstdint>
#include <string>

class Player {
public:
  Player(std::string name, uint16_t hp);
  std::string get_name() const;

private:
  std::string name;
  int16_t hp = 0;
};
#endif