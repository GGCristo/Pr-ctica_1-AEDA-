#include <iostream>
#include "../include/vector_t.hpp"
#include "../include/dll_node_t.hpp"
#include "../include/dll_t.hpp"
#include "../include/stack_l_t.hpp"
#include "../include/stack_v_t.hpp"
typedef int TDato;
using namespace AEDA;

int main(){

  std::cout << "Hola\n";
  std::cout << "Vector de enteros\n";
  vector_t<TDato> vector_i(5);
  vector_i.get_set_v(0) = 0;
  vector_i.get_set_v(1) = 5;
  vector_i.get_set_v(2) = 4;
  vector_i.get_set_v(3) = 3;
  vector_i.push_back() = 2;
  vector_i.write(std::cout);
  std::cout << "Vector de dobles\n";
  vector_t<double> vector_d(5);
  vector_d.get_set_v(0) = 0.0;
  vector_d.get_set_v(1) = 5.4;
  vector_d.get_set_v(2) = 4.3;
  vector_d.get_set_v(3) = 3.2;
  vector_d.push_back() = 2.1;
  vector_d.write(std::cout);
  std::cout << "Lista doblemente enlazada\n";
  dll_t<TDato> lista_d;
  lista_d.insert_tail(new dll_node_t<int> (1));
  lista_d.insert_tail(new dll_node_t<int> (2));
  lista_d.insert_tail(new dll_node_t<int> (3));
  lista_d.insert_tail(new dll_node_t<int> (4));
  lista_d.insert_tail(new dll_node_t<int> (5));
  lista_d.insert_tail(new dll_node_t<int> (6));
  lista_d.write(std::cout);
  return 0;
}