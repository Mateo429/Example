#include "vector_ops.hpp" //Se incluye el encabezado con la declaración de la función mean

double mean(std::vector<double> &data) {
  double sum = 0; //Se declara la variable sum que contendrá la suma de los elementos del vector.

  for (int ii = 0; ii < data.size(); ++ii) {    

    sum += data[ii];
  }

  return sum / data.size(); //Se calcula el promedio diviendiendo la suma de los elementos por el número de elementos. 
}
