#pragma once

#include <iostream>
#include <iomanip>
#include <cassert>

#include "../include/dll_t.hpp"

using namespace std;

namespace AEDA {

  template <class T>
    class queue_l_t{
      private:

        dll_t<T>    l_;

      public:	
        queue_l_t(void):
          l_() {}

        ~queue_l_t(void) {}

        bool empty(void)
        {
          return l_.empty();
        }

        int size(void)
        {
          return l_.get_size();		
        }

        T front(void)
        {
           assert(!empty());

          dll_node_t<T>* node = l_.get_tail();
          T data = node->get_data();
          return (data);
        }

        T back(void)
        {
          assert(!empty());
          dll_node_t<T>* node = l_.get_head();
          T data = node->get_data();
          return (data);
        }

        void pop(void)
        {
          assert(!empty());			
          dll_node_t<T>* node = l_.extract_tail();
          delete node;
        }

        void push(T dato)
        {
          dll_node_t<T>* node = new dll_node_t<T>(dato);
          l_.insert_head(node);
        }

        ostream& write(ostream& os)
        {
          dll_node_t<T>* aux = l_.get_head();

          while(aux != NULL){
            os << setw(4) << aux -> get_data();
            aux = aux -> get_next();
          }

          os << endl;			

          return os;
        }

    };
  template <class T>
    ostream& operator << (ostream& os, queue_l_t<T>& cola)
    {
      cola.write(os);
      return os;
    }
}
