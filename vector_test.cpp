#define CATCH_CONFIG_MAIN // Esta línea le dice a CATCH que nos proporcione una función main y solo debe ser usada en archivos .cpp
#include "catch2/catch.hpp" //Incluimos el archivo de la librería catch2 con su respectiva ruta.
#include "vector_ops.hpp" // Incluimos el archivo que contiene la declaración de la función mean().
#include <cmath> //Incluimos la librería cmath que usaremos para calcular los errores relativos.

TEST_CASE("Mean of a vector is computed", "[mean]") {

  const int N = 10; // Declaramos el tamaño que tendrán nuestros vectores de prueba.

  const double a = 20; // Se declara un double para llenar nuestro primer vector de prueba.

  /////////////////////////////////////////////////////////////////////////////////
  std::vector<double> v1; // Se declara el vector v1 con un tamaño N.
  v1.resize(N);

  for (int ii = 0; ii < N; ++ii) { // Llenamos el vector v1 con el valor de a.

    v1[ii] = a;
  }
  ////////////////////////////////////////////////////////////////////////////////
  std::vector<double> v2; // Se declara el vector v2 con un tamaño N.
  v2.resize(N);

  for (int ii = 0; ii < N; ++ii) { // Llenamos el vector v2 con el valor de N.
    v2[ii] = N;
  }
  /////////////////////////////////////////////////////////////////////////////////
  std::vector<double> v3; // Declaramos el vector v3  con un tamaño N.
  v3.resize(N);

  for (int ii = 0; ii < N;
       ++ii) { // Llenamos el vector con los primeros N-1 números naturales.

    v3[ii] = ii;
  }
  ////////////////////////////////////////////////////////////////////////////////////
  std::vector<double> v4; // Declaramos el vector v4 con un tamaño N.
  v4.resize(N);

  for (int ii = 0; ii < N; ++ii) { // Llenamos el vector con ceros.

    v4[ii] = 0;
  }
  //////////////////////////////////////////////////////////////////////////////////

  std::vector<double> v5; // Declaramos el vector v5 con un tamaño N.
  v5.resize(N);

  for (int ii = 0; ii < N; ++ii) { // Llenamos el vector con los cuadrados de
                                   // los primeros N-1 números naturales.

    v5[ii] = ii * ii;
  }
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////


  // Procedemos a plantear los requerimientos en términos de errores relativos.

  double error = 1.0e-5; //Declaramos el erorr relativo que vamos a tolerar en nuestros cálculos. 

  REQUIRE(std::fabs(1 - (mean(v1) / a)) <= error); // Se requiere que el vector cuyas componenetes sean a tenga promedio a.

  REQUIRE(std::fabs(1 - (2 * mean(v3) / (N - 1))) <= error); // La suma de los primeros N-1 números naturales es N*(N-1)/2,
                                                            // entonces Se requiere que el promedio de z sea (N-1)/2.

  REQUIRE(std::fabs(1 - (mean(v2) / N)) <= error); // Se requiere que el vector que está lleno con el número N,
                                                  // tenga un promedio igual N

  REQUIRE(mean(v4) <= error); // Se requiere que el promedio del vector lleno de ceros sea cero.

  REQUIRE(std::fabs(1 - (6 * mean(v5) / ((N - 1) * (2 * N - 1)))) <= error); /*La suma de los cuadrados de los primeros N-1 números
									       naturales es N*(2*N-1)(N-1)/6 por lo tanto, requerimos que                                                                              el promedio de este sea (2*N-1)(N-1)/6.*/
                   
 }


