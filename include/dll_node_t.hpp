#pragma once

#include <cassert>
#include <iostream>
#include <cstdio>

using namespace std;

namespace AEDA {

  template <class T>
    class dll_node_t {
      private:

        dll_node_t<T>* next_;
        dll_node_t<T>* prev_;

        T              data_;

      public:
        dll_node_t();
        dll_node_t(const T& data);

        virtual ~dll_node_t(void);

        void set_next(dll_node_t<T>*);
        void set_prev(dll_node_t<T>*);

        dll_node_t<T>* get_next(void) const;
        dll_node_t<T>* get_prev(void) const;

        void set_data(const T& data);
        T get_data(void) const;

        ostream& write(ostream& os) const;
    };


  template <class T>
    dll_node_t<T>::dll_node_t() :
      next_(NULL),
      prev_(NULL),
      data_(){}

  template <class T>
    dll_node_t<T>::dll_node_t(const T& data) :
      next_(NULL),
      prev_(NULL),
      data_(data){}

  template <class T>
    dll_node_t<T>::~dll_node_t(void) 
    {
      prev_ = NULL;
      next_ = NULL;
    }

  template<class T>
  bool operator < (dll_node_t<T> nodo1, dll_node_t<T> nodo2)
  {
    if(nodo1.get_data() < nodo2.get_data())
    {
      return true;
    }
    return false;
  }

  template <class T>
    void dll_node_t<T>::set_next(dll_node_t<T>* next)
    {
      next_ = next;
    }

  template <class T>
    dll_node_t<T>* dll_node_t<T>::get_next(void) const
    {
      return next_;
    }

  template <class T>
    void dll_node_t<T>::set_prev(dll_node_t<T>* prev)
    {
      prev_ = prev;
    }

  template <class T>
    dll_node_t<T>* dll_node_t<T>::get_prev(void) const
    {
      return prev_;
    }

  template <class T>
    void dll_node_t<T>::set_data(const T& data)
    {
      data_ = data;
    }

  template <class T>
    T dll_node_t<T>::get_data(void) const
    {
      return data_;
    }

  template <class T>
    ostream& dll_node_t<T>::write(ostream& os) const
    {
      os << data_;
      return os;
    }

}
