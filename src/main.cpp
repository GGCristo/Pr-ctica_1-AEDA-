#include <iostream>
#include "../include/vector_t.hpp"
#include "../include/dll_node_t.hpp"
#include "../include/dll_t.hpp"
#include "../include/stack_l_t.hpp"
#include "../include/stack_v_t.hpp"
#include "../include/queue_l_t.hpp"


using namespace AEDA;

int main(){
  typedef int TDato;
  std::cout << "Vector de enteros\n";
  vector_t<TDato> vector_i(5);
  vector_i.get_set_v(0) = 0;
  vector_i.get_set_v(1) = 5;
  vector_i.get_set_v(2) = 4;
  vector_i.get_set_v(3) = 3;
  vector_i.push_back(2);

  std::cout << vector_i;

  std::cout << "Vector de dobles\n";
  vector_t<double> vector_d(5);
  vector_d.get_set_v(0) = 0.0;
  vector_d.get_set_v(1) = 5.4;
  vector_d.get_set_v(2) = 4.3;
  vector_d.get_set_v(3) = 3.2;
  vector_d.push_back(2.1);

  std::cout << vector_d;

  std::cout << "Lista doblemente enlazada\n";
  dll_t<TDato> lista_d;
  lista_d.insert_tail(new dll_node_t<int> (1));
  lista_d.insert_tail(new dll_node_t<int> (2));
  lista_d.insert_tail(new dll_node_t<int> (3));
  lista_d.insert_tail(new dll_node_t<int> (4));
  lista_d.insert_tail(new dll_node_t<int> (5));
  lista_d.insert_tail(new dll_node_t<int> (6));

  std::cout << lista_d;

  std::cout << "pila_v con vector\n";
  stack_v_t<TDato> pila_v;
  pila_v.push(5);
  pila_v.push(4); 
  pila_v.push(3);
  pila_v.push(2); 
  pila_v.push(1);
  pila_v.push(-1);

  std::cout << pila_v;

  std::cout << "Pila con lista\n";
  stack_l_t<TDato> pila_l;
  pila_l.push(5);
  pila_l.push(4); 
  pila_l.push(3);
  pila_l.push(2); 
  pila_l.push(1);
  pila_l.push(-1);

  std::cout << pila_l;

  std::cout << "Cola\n";
  queue_l_t<TDato> cola;
  cola.push(5);
  cola.push(4);
  cola.push(3);
  cola.push(2);
  cola.push(1);

  std::cout << cola;

  return 0;
}