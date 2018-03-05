/*
Arturo Burela
*/
#ifndef STATE_HPP
#define STATE_HPP

#include <string>
#include <bitset>
#include <vector>
#include <iostream>

class State;

struct link {
  std::string input;
  State* destination;
  link() = default;
  link(std::string i, State* d){
    input = i;
    destination = d;
  }
};

class State {
private:
  std::string name;
  std::bitset<1> end;
  std::vector<link> destinations;
public:
  State(){}
  State(std::string n){
    name = n;
  }
  void addLink(link l) {
    destinations.push_back(l);
  }
  std::string getName() {
    return name;
  }
  void setFinal() {
    end.set();
  }
  void logData() {
    std::cout << "State name: " << name << '\n';
    std::cout << "Final state: " << end[0] << '\n';
    std::cout << "Destinantions: " << '\n';
    for (std::vector<link>::iterator it = this->destinations.begin(); it != this->destinations.end(); ++it){
      std::cout << "Input: " << it->input << '\n';
      std::cout << "Destination: " << it->destination->getName() << '\n';
    }
  }
};

#endif
