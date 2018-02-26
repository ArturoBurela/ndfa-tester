/*
Arturo Burela
*/
#ifndef STATE_HPP
#define STATE_HPP

#include <string>
#include <bitset>
#include <vector>

class State {
  struct link {
    char input;
    State* destination;
  };
private:
  std::string name;
  std::bitset<1> end;
  std::vector<link> destinations;
public:
  State(){}
  State(std::string n){
    name = n;
  }
};

#endif
