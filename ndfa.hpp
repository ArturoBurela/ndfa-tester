/*
Arturo Burela
*/
#ifndef NDFA_HPP
#define NDFA_HPP

#include "state.hpp"
#include <fstream>
#include <sstream>
#include <queue>

class NDFA {
private:
  // Stores all states
  std::vector<State> states;
  // The string to test
  std::queue<char> string;
  // Pointer to initial State
  State* initialState;
  // Accepted paths
  std::vector<std::vector<link>> paths;

  // Returns a pointer to state searching by name
  State* findState(std::string name) {
    std::vector<State>::iterator it;
    for (it = states.begin(); it != states.end(); ++it){
      if (it->getName() == name) {
        break;
      }
    }
    return &*it;
  }

  // Start test
  void test() {
    paths = initialState->explore(string);
    // If explore paths are accepted
    if (paths.at(0).at(0).input =! '\0') {
      // Add initial state to final paths
      for (std::vector<std::vector<link>>::iterator it = paths.begin(); it != paths.end(); ++it){
        // Push current link to received path
        it->push_back(link('\0', initialState));
      }
      // Log all accepted paths
      logPaths(paths);
    } else {
      // If no path was found then just print and exit
      std::cout << "/* String not accepted by automaton */" << '\n';
    }
  }

  // Logs all data
  void logStates() {
    for (std::vector<State>::iterator it = states.begin(); it != states.end(); ++it){
      it->logData();
    }
  }

  //Logs all paths
  void logPaths(std::vector<std::vector<link>> paths) {
    for (std::vector<std::vector<link>>::iterator it = paths.begin(); it != paths.end(); ++it){
      std::cout << '\n' << "/* Path found: */" << '\n';
      // Paths are stored BACKWARDS!
      for (std::vector<link>::reverse_iterator it2 = it->rbegin(); it2 != it->rend(); ++it2){
        std::cout << it2->input << "->" << it2->destination->getName() << "--";
      }
      std::cout << '\n' << "/* ------------- */" << '\n';
    }
  }

  // Loads automaton data assuming that
  // the file is formatted correctly
  void cargar(const std::string& filename)
  {
    std::cout << "Loading automaton..." << std::endl;
    // Aux varaibles to store links
    std::string name;
    char input;
    std::string destination;
    // Aux pointer to state
    State* aux;
    std::ifstream afile(filename);
    // Stores a line
    std::string line;
    // Usefull to split lines
    char param = ',';
    // Line number counter
    int i = 0;
    // Get line data
    while(getline(afile,line))
    {
      std::stringstream   linestream(line);
      // Stores split line value
      std::string value;
      if (i == 4) {
        param = '\n';
      }
      // Call again with param to read by characters
      while(getline(linestream,value,param))
      {
        // Process data according to line number
        switch (i) {
          case 0:
          // std::cout << "Loading states" << '\n';
          states.push_back(State(value));
          break;
          case 1:
          // std::cout << "Loading alphabet" << '\n';
          // Reading alphabet here is not really necessary
          break;
          case 2:
          // std::cout << "Loading initial state" << '\n';
          initialState = this->findState(value);
          break;
          case 3:
          // std::cout << "Loading final state(s)" << '\n';
          this->findState(value)->setFinal();
          break;
          default:
          // std::cout << "Loading transition function" << '\n';
          destination = "";
          for ( std::string::iterator it=value.begin(); it!=value.end(); ++it){
            if (*it == ',') {
              name = destination;
              destination = "";
            } else if (*it == ':') {
              input = destination.at(0);
              destination = "";
            } else {
              destination += *it;
            }
          }
          // Find both states and add link
          this->findState(name)->addLink(link(input, this->findState(destination)));
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
    std::cout << "String to test:" << testString << '\n';
    // Transform string into char queue
    for (int i = 0; i<testString.length(); i++){
      string.push(testString.at(i));
    }
    //Load automaton
    cargar(filename);
    //Test string
    test();
  }
};

#endif
