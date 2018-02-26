/*
Arturo Burela
*/
#ifndef STATE_HPP
#define STATE_HPP

#include <string>
#include <bitset>
#include <vector>

class State {
private:
  std::string name;
  std::bitset<2> foo;
  std::vector<State*> destinations;
public:
  State(){}
  State(std::string n){
    name = n;
  }
};

#endif
