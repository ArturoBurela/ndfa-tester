/*
Arturo Burela
*/
#ifndef NDFA_HPP
#define NDFA_HPP

#include "state.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>

class NDFA {
private:
  std::string alphabet;
  std::vector<State> states;
  std::queue<char> string;
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
    std::ifstream afile(filename);
    std::string line;
    char param = ',';
    int i = 0;
    int j;
    while(getline(afile,line))
    {
      std::stringstream   linestream(line);
      std::string         value;
      if (i == 4) {
        param = '\n';
      }
      while(getline(linestream,value,param))
      {
        std::cout << "Value(" << value << ")\n";
        switch (i) {
          case 0:
          // std::cout << "Loading states" << '\n';
          states.push_back(value);
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
          j = 0;
          name = "";
          for ( std::string::iterator it=value.begin(); it!=value.end(); ++it){
            if (*it == ',') {
              std::cout << name << '\n';
              name = "";
            } else if (*it == ':') {
              std::cout << name << '\n';
              name = "";
            } else {
              name += *it;
            }
          }
          std::cout << name << '\n';
          break;
        }
      }
      i++;
      std::cout << "Line Finished" << std::endl;
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
  }
};

#endif
