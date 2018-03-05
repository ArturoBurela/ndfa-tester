/*
Arturo Burela
*/
#ifndef NDFA_HPP
#define NDFA_HPP

#include "state.hpp"
#include <fstream>
#include <sstream>
#include <queue>

struct auxlink {
  std::string state;
  struct link link;
};

class NDFA {
private:
  std::string alphabet;
  std::vector<State> states;
  std::queue<char> string;

  // Returns a pointer to state searching by name
  State* findState(std::string name) {
    std::vector<State>::iterator it;
    for (it = this->states.begin(); it != this->states.end(); ++it){
      if (it->getName() == name) {
        break;
      }
    }
    return &*it;
  }

  void logStates() {
    for (std::vector<State>::iterator it = this->states.begin(); it != this->states.end(); ++it){
      it->logData();
    }
  }

  // Loads automaton data assuming that
  // the file is formatted correctly
  void cargar(const std::string& filename)
  {
    std::cout << "Loading automaton..." << std::endl;
    // States names
    std::vector<std::string> states;
    // Alphabet
    std::vector<char> alphabet;
    // Initial state
    std::string initial;
    // Final states
    std::vector<std::string> finals;
    // Aux name store
    std::string name;
    std::string input;
    std::string destination;
    std::ifstream afile(filename);
    std::string line;
    char param = ',';
    int i = 0;
    while(getline(afile,line))
    {
      std::stringstream   linestream(line);
      std::string         value;
      if (i == 4) {
        param = '\n';
      }
      while(getline(linestream,value,param))
      {
        switch (i) {
          case 0:
          // std::cout << "Loading states" << '\n';
          states.push_back(value);
          this->states.push_back(State(value));
          break;
          case 1:
          // std::cout << "Loading alphabet" << '\n';
          // Reading alphabet here is not necessary
          // alphabet.push_back(value);
          break;
          case 2:
          // std::cout << "Loading initial state" << '\n';
          initial = value;
          break;
          case 3:
          // std::cout << "Loading final state(s)" << '\n';
          finals.push_back(value);
          break;
          default:
          // std::cout << "Loading transition function" << '\n';
          destination = "";
          for ( std::string::iterator it=value.begin(); it!=value.end(); ++it){
            if (*it == ',') {
              name = destination;
              destination = "";
            } else if (*it == ':') {
              input = destination;
              destination = "";
            } else {
              destination += *it;
            }
          }
          // Find both states and add link
          State* aux = this->findState(name);
          State* des = this->findState(destination);
          aux->addLink(link(input, des));
          break;
        }
      }
      i++;
      // std::cout << "Line Finished" << std::endl;
    }
    // Close file
    afile.close();
    std::cout << "Automaton loaded" << std::endl;
  }
  NDFA(){}
public:
  NDFA(const std::string& filename, const std::string& testString){
    std::cout << filename << '\n';
    std::cout << "String to test:" << testString << '\n';
    cargar(filename);
    logStates();
  }
};

#endif
