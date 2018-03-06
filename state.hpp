/*
Arturo Burela
*/
#ifndef STATE_HPP
#define STATE_HPP

#include <string>
#include <bitset>
#include <vector>
#include <iostream>
#include <queue>

class State;

struct link {
  char input;
  State* destination;
  link() = default;
  link(char i, State* d){
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
  void explore(std::queue<char> string) {
    //Return if empty
    if (string.empty()) {
      return;
    }
    // Get next input to test
    char input = string.front();
    std::cout << "Estado: " << name << '\n';
    // Delete input
    string.pop();
    // Check all links of current state
    for (std::vector<link>::iterator it = destinations.begin(); it != destinations.end(); ++it){
      // If the input matches explore
      if (input == it->input) {
        std::cout << "Son iguales" << '\n';
        std::cout << "Input: " << it->input << '\n';
        std::cout << "Destination: " << it->destination->getName() << '\n';
        it->destination->explore(string);
      }
    }
  }

  void logData() {
    std::cout << "State name: " << name << '\n';
    std::cout << "Final state: " << end[0] << '\n';
    std::cout << "Destinantions: " << '\n';
    for (std::vector<link>::iterator it = destinations.begin(); it != destinations.end(); ++it){
      std::cout << "Input: " << it->input << '\n';
      std::cout << "Destination: " << it->destination->getName() << '\n';
    }
  }
};

#endif
