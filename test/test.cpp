#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>

#include "../include/vector_t.hpp"
#include "../include/dll_node_t.hpp"
#include "../include/dll_t.hpp"
#include "../include/stack_l_t.hpp"
#include "../include/stack_v_t.hpp"
#include "../include/queue_l_t.hpp"
typedef int TDato;
using namespace AEDA;

TEST_CASE("Modificaciones en el vector") 
{
  
  vector_t<TDato> vector_i(5);
  REQUIRE (vector_i.size() == 5);
  
  SECTION ("Accedo a un elemento")
  {
    vector_i.get_set_v(4) = 3;
    REQUIRE(vector_i.get_v(4) == 3); 
  }

  SECTION ("Uso la función push-back")
  {
    vector_i.push_back(5);
    REQUIRE(vector_i.get_v(vector_i.size() - 1) == 5); //  const?
  }

  SECTION("Cambio el tamaño del vector explicitamente")
  {
    vector_i.resize(44);
    REQUIRE(vector_i.size() == 44);
  }

  SECTION("Prueba de punteros (begin)")
  {
    vector_i.get_set_v(0) = 1;
    REQUIRE(*vector_i.begin() == 1);
  }
  
  SECTION("Prueba de punteros (++)")
  {
    vector_i.get_set_v(1) = 2;
    TDato* variable = vector_i.begin();
    variable++;
    REQUIRE(*variable == 2);
  }
  
}
TEST_CASE ("Modificaciones en la pila")
{
  stack_v_t<TDato> pila_v;
  stack_l_t<TDato> pila_l;

  SECTION ("Pila vacia")
  {
    REQUIRE(pila_v.empty());
    REQUIRE (pila_l.empty());
  }

  SECTION ("Top y push")
  {
    pila_v.push(5);
    pila_l.push(5);
    REQUIRE(pila_v.top() == 5);
    REQUIRE(pila_l.top() == 5);
  }
  SECTION ("Pop")
  {
    pila_v.push(1);
    pila_v.push(2);
    pila_v.pop();
    pila_l.push(1);
    pila_l.push(2);
    pila_l.pop();
    REQUIRE(pila_v.top() == 1);
    REQUIRE(pila_l.top() == 1);
  }
}
TEST_CASE ("Listas dobles")
{
  
  dll_t<TDato> lista;
  REQUIRE (lista.get_size() == 0);

  SECTION ("Insert_after")
  {
    lista.insert_head(new dll_node_t<TDato>(1));
    lista.insert_head(new dll_node_t<TDato>(3));
    
    lista.insert_after(lista.get_head(), new dll_node_t<TDato>(2));
    REQUIRE(lista.get_head() -> get_next() -> get_data() == 2);
  }
}