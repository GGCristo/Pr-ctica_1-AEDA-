#include <iostream>
#include "../include/dll_node_t.hpp"
#include "../include/dll_t.hpp"
#include "../include/stack_l_t.hpp"
#include "../include/stack_v_t.hpp"
#include "../include/vector_t.hpp"
using namespace AEDA;

int main(){

  std::cout << "Hola\n";
  std::cout << "Vector de enteros\n";
  vector_t<int> Estructura1(5);
  Estructura1.get_set_v(0) = 0;
  Estructura1.get_set_v(1) = 5;
  Estructura1.get_set_v(2) = 4;
  Estructura1.get_set_v(3) = 3;
  Estructura1.get_set_v(4) = 2;
  Estructura1.write(std::cout);
  std::cout << "Vector de dobles\n";
  vector_t<double> Estructura2(5);
  Estructura2.get_set_v(0) = 0.0;
  Estructura2.get_set_v(1) = 5.4;
  Estructura2.get_set_v(2) = 4.3;
  Estructura2.get_set_v(3) = 3.2;
  Estructura2.get_set_v(4) = 2.1;
  Estructura2.write(std::cout);
  return 0;
}