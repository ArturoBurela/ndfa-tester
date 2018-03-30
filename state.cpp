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

// Struct to represents links
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
  // State name
  std::string name;
  // If state is final
  std::bitset<1> end;
  // Vector of links to states
  std::vector<link> destinations;
public:
  State(){}
  State(std::string n){
    name = n;
  }

  // Add link to state
  void addLink(link l) {
    destinations.push_back(l);
  }

  // Returns state name
  std::string getName() {
    return name;
  }

  // Mark state as final
  void setFinal() {
    end.set();
  }

  // Recursive function returns valid paths by testing string
  std::vector<std::vector<link>> explore(std::queue<char> string) {
    // New paths to return
    std::vector<std::vector<link>> paths;
    std::vector<link> x;
    // Aux to tell if valid paths were found
    std::bitset<1> valid;
    // First call on all epsilon links
    for (std::vector<link>::iterator it = destinations.begin(); it != destinations.end(); ++it){
      // If the link matches
      if (it->input == '&') {
        // Get new vector of paths from next call
        std::vector<std::vector<link>> p = it->destination->explore(string);
        // Iterate over paths and append current link
        for (std::vector<std::vector<link>>::iterator it2 = p.begin(); it2 != p.end(); ++it2){
          // If we receive valid paths append to current state
          if (it2->at(0).input != '\0') {
            valid.set();
            // Push current link to received path
            it2->push_back(*it);
            // Push path to paths
            paths.push_back(*it2);
          }
        }
      }
    }
    //Stop condition when string is empty
    if (string.empty()) {
      // Check if state is final
      if (end.test(0)) {
        // Return a link with '\n' if accepted
        x.push_back(link('\n', this));
      } else {
        // Else return '\0'
        x.push_back(link('\0', this));
      }
      paths.push_back(x);
      return paths;
    }
    // Get next input to test
    char input = string.front();
    // Delete input
    string.pop();
    // Check all links of current state
    for (std::vector<link>::iterator it = destinations.begin(); it != destinations.end(); ++it){
      // If the input matches links input
      if (input == it->input) {
        // Get new vector of paths from next call
        std::vector<std::vector<link>> p = it->destination->explore(string);
        // Iterate over paths and append current link
        for (std::vector<std::vector<link>>::iterator it2 = p.begin(); it2 != p.end(); ++it2){
          // If we receive valid paths append to current state
          if (it2->at(0).input != '\0') {
            valid.set();
            // Push current link to received path
            it2->push_back(*it);
            // Push path to paths
            paths.push_back(*it2);
          }
        }
      }
    }
    // If no valid paths were found append no valid path
    if (!valid.test(0)) {
      x.push_back(link('\0', NULL));
      paths.push_back(x);
    }
    return paths;
  }

  //Logs all state data
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
