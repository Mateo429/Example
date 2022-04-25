#define CATCH_CONFIG_MAIN //Esta línea le dice a CATCH que nos proporcione una función main y solo debe ser usada en archivos .cpp
#include "catch2/catch.hpp"//Incluimos el archivo de la librería catch2 con su respectiva ruta.
#include "vector_ops.hpp" // Incluimos el archivo que contiene la declaración de la función mean().
#include <cmath> //Incluimos la librería cmath que usaremos para calcular los errores relativos.

TEST_CASE("Mean of a vector is computed", "[mean]") {

  const int N = 10;   //Declaramos el tamaño que tendrán nuestros vectores de prueba.

  const double a = 20; //Se declara un double para llenar nuestro primer vector de prueba.

  /////////////////////////////////////////////////////////////////////////////////
  std::vector<double> x; // Se declara el vector x con un tamaño N.
  x.resize(N);

  for (int ii = 0; ii < N; ++ii) { //Llenamos el vector x con el valor de a.

    x[ii] = a;
  }
  ////////////////////////////////////////////////////////////////////////////////
  std::vector<double> y; //Se declara el vector y con un tamaño N.
  y.resize(N);

  for (int ii = 0; ii < N; ++ii) { //Llenamos el vector x con el valor de N.
    y[ii] = N;
  }
  /////////////////////////////////////////////////////////////////////////////////
  std::vector<double> z; //Declaramos el vector z y con un tamaño N.
  z.resize(N);

  for (int ii = 0; ii < N; ++ii) { //Llenamos el vector con los primeros N-1 números naturales.

    z[ii] = ii;
  }
  ////////////////////////////////////////////////////////////////////////////////////

  //Procedemos a plantear los requerimientos en términos de errores relativos.
  
  REQUIRE(std::fabs(1 - (mean(x) / a)) <= 1.0e-4); //Se requiere que el vector cuyas componenetes sean a tenga promedio a.

  REQUIRE(std::fabs(1 - (2 * mean(z) / (N - 1))) <= 1.0e-4); //La suma de los primeros N-1 números naturales es N*(N-1)/2, entonces
                                                             //Se requiere que el promedio de z sea (N-1)/2.

  REQUIRE(std::fabs(1 - (mean(y) / N)) <= 1.0e-4); //Se requiere que el vector que está lleno con el número N, tenga un promedio igual N.
}
