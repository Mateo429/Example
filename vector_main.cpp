#include<iostream>//Incluimos librería iostream que nos permite visualizar la salida del programa en la terminal
#include<cstdlib>//Incluimos librería cstdlib que nos permite ingresar valores desde la terminal que interactuan con el programa 
#include<numeric>//Librería necesaria para usar el algoritmo iota.
#include "vector_ops.hpp"//Archivo que contiene la declaración de la función mean().

int main(int argc, char **argv) {

  const int N = std::atoi(argv[1]);

  std::vector<double> x;

  x.resize(N);

  std::iota(x.begin(), x.end(), 0.0); // ver: https://en.cppreference.com/w/cpp/algorithm/iota


  std::cout << mean(x) << "\n";
}
