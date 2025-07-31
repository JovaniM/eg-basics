#include "player.h"
#include <iostream>

int main() {
  Player p{"Hero", 200};
  std::cout << "Hello " << p.get_name() << std::endl;
  return 0;
}