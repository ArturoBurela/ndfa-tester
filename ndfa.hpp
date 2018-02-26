/*
Arturo Burela
*/
#ifndef NDFA_HPP
#define NDFA_HPP

#include "state.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

class NDFA {
private:
  std::string alphabet;
  std::vector<State> states;
  void cargar(char const filename)
  {
    std::cout << "Cargando datos..." << std::endl;
    ifstream archivo_entrada(filename);
    char linea[128];
    int c= 0;
    archivo_entrada.open("Banco.txt");
    if(archivo_entrada.fail())
    {
      sdt::cout<<"Automaton file not found"<< std::endl;
      return;
    }
    archivo_entrada.getline(linea,sizeof(linea));
    std::string str(linea);
    std::istringstream iss(str);
    iss>>c;
    // Close file
    archivo_entrada.close();
    std::cout << "Terminado" << std::endl;
  }
public:
  NDFA(){}
};

#endif
