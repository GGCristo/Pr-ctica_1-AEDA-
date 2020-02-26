#include <iostream>
#include <algorithm>
#include "../include/vector_t.hpp"
#include "../include/dll_node_t.hpp"
#include "../include/dll_t.hpp"
#include "../include/stack_l_t.hpp"
#include "../include/stack_v_t.hpp"
#include "../include/queue_l_t.hpp"
typedef int TDato;
using namespace AEDA;
int main(){
  std::cout << "Modificacion\n";
  dll_t<int> lista1;
  dll_t<int> lista2;

  lista1.insert_tail(new dll_node_t<TDato>(15));
  lista1.insert_tail(new dll_node_t<TDato>(18));
  lista1.insert_tail(new dll_node_t<TDato>(6));
  lista1.insert_tail(new dll_node_t<TDato>(0));

  lista2.insert_tail(new dll_node_t<TDato>(-16));
  lista2.insert_tail(new dll_node_t<TDato>(41));
  lista2.insert_tail(new dll_node_t<TDato>(58));
  lista2.insert_tail(new dll_node_t<TDato>(21));

  lista1.merge(lista2);
  std::cout << lista1 << std::endl;

  lista1.sort();
  std::cout << lista1 << std::endl;

  dll_t<int> lista3;
  lista3.insert_tail(new dll_node_t<TDato>(3));
  lista3.insert_tail(new dll_node_t<TDato>(5));
  lista3.insert_tail(new dll_node_t<TDato>(4));
  lista3.insert_tail(new dll_node_t<TDato>(1));
  lista3.insert_tail(new dll_node_t<TDato>(8));
  lista3.insert_tail(new dll_node_t<TDato>(0));
  lista3.sort();
  std::cout << lista3 << std::endl;
  return 0;
}

