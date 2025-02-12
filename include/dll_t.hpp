#pragma once

#include <cassert>
#include <iostream>
#include <cstdio>

#include "dll_node_t.hpp"

using namespace std;

namespace AEDA {

  template <class T>
    class dll_t {
      private:

        dll_node_t<T>* head_;
        dll_node_t<T>* tail_;

        int sz_;

      public:

        dll_t(void);
        virtual ~dll_t(void);

        void insert_tail(dll_node_t<T>*);
        void insert_after(dll_node_t<T>*, dll_node_t<T>*);
        void insert_head(dll_node_t<T>*);

        dll_node_t<T>* extract_tail(void);
        dll_node_t<T>* extract_head(void);

        dll_node_t<T>* get_tail(void);
        dll_node_t<T>* get_head(void);
        void set_head(dll_node_t<T>*);
        void set_tail(dll_node_t<T>*);

        bool empty(void);

        void remove(dll_node_t<T>*);


        dll_node_t<T>* extract(dll_node_t<T>*);

        void modificacion (dll_t<T>&, dll_t<T>&);

        void merge (dll_t<T>&);

        void sort (void);

        int& get_size(void);

        ostream& write(ostream& os);
    };


  template <class T>
    dll_t<T>::dll_t(void) :
      head_(NULL),
      tail_(NULL),
      sz_(0) {}

  template <class T>
    dll_t<T>::~dll_t(void)
    {
      dll_node_t<T>* aux = NULL;

      while (head_ != NULL) {
        aux = head_;
        head_ = head_->get_next();
        delete aux;
        aux = NULL;
      }

      sz_ = 0;
      head_ = NULL;
      tail_ = NULL;
    }

  template <class T>
    bool dll_t<T>::empty(void)
    {
      if (head_ == NULL)
      {
        assert(tail_ == NULL);
        assert(sz_ == 0);

        return true;
      }
      else
        return false;
    }

  template <class T>
    void dll_t<T>::insert_head(dll_node_t<T>* nodo)
    {
      assert(nodo != NULL);

      if (empty())
      {
        head_ = nodo;
        tail_ = head_;
      }
      else
      {
        head_ -> set_prev(nodo);
        nodo -> set_next(head_);
        head_ = nodo;
      }
      sz_++;
    }

  template <class T>
    void dll_t<T>::insert_after(dll_node_t<T>* nodo_prev, dll_node_t<T>* nodo)
    {
      assert(nodo != NULL);

      if (!nodo_prev)
        insert_head(nodo);
      else if (nodo_prev -> get_next() == NULL)
        insert_tail(nodo);
      else
      {
        nodo -> set_next(nodo_prev -> get_next());
        nodo_prev -> set_next(nodo);
        nodo -> set_prev (nodo_prev);
        nodo -> get_next() -> set_prev(nodo);
      }
      sz_++;
    }

  template <class T>
    void dll_t<T>::insert_tail(dll_node_t<T>* nodo)
    {

      assert(nodo != NULL);

      if (empty())
      {
        head_ = nodo;
        tail_ = head_;
      }
      else
      {
        tail_ -> set_next(nodo);
        nodo -> set_prev(tail_);
        tail_ = nodo;
      }

      sz_++;
    }

  template <class T>
    dll_node_t<T>* dll_t<T>::extract_tail(void)
    {
      assert(!empty());

      dll_node_t<T>* aux = tail_;

      tail_ = tail_ -> get_prev();

      if (tail_ != NULL)
        tail_ -> set_next(NULL);
      else
        head_ = NULL;
      sz_--;
      aux -> set_next(NULL);
      aux -> set_prev(NULL);
      return aux;
    }

  template <class T>
    dll_node_t<T>* dll_t<T>::extract_head(void) {

      assert(!empty());

      dll_node_t<T>* aux = head_;

      head_ = head_ -> get_next();

      if (head_)
        head_ -> set_prev(NULL);
      else
        tail_ = NULL;

      sz_--;

      aux -> set_next(NULL);
      aux -> set_prev(NULL);

      return aux;
    }

  template <class T>
    dll_node_t<T>* dll_t<T>::get_head(void) {
      return head_;
    }

  template <class T>
    void dll_t<T>::set_head(dll_node_t<T>* nodo) {
      head_ = nodo;
    }

  template <class T>
    void dll_t<T>::set_tail(dll_node_t<T>* nodo) {
      tail_ = nodo;
    }

  template <class T>
    dll_node_t<T>* dll_t<T>::get_tail(void) {
      return tail_;
    }

  template <class T>
    ostream& dll_t<T>::write(ostream& os) {

      dll_node_t<T>* aux = head_;

      while (aux != NULL) {
        aux -> write(os);
        os << "\t";
        aux = aux->get_next();
      }

      os << endl;

      return os;
    }
  template<class T>
    ostream& operator << (ostream&os, dll_t<T>& list)
    {
      list.write(os);
      return os;
    }

  template <class T>
    void dll_t<T>::remove(dll_node_t<T>* nodo)
    {

      assert(nodo != NULL);

      if (nodo -> get_prev() != NULL)
        nodo -> get_prev() -> set_next(nodo->get_next());
      else
        head_ = nodo->get_next();

      if (nodo -> get_next() != NULL)
        nodo -> get_next() -> set_prev(nodo->get_prev());
      else
        tail_ = nodo -> get_prev();

      delete nodo;

      sz_--;
    }

  template<class T>
    dll_node_t<T>* dll_t<T>::extract(dll_node_t<T>* nodo)
    {
      assert(nodo != NULL);

      if (nodo -> get_prev() == NULL)
      {
        return extract_head();
      }
      else if (nodo -> get_next() == NULL)
      {
        return extract_tail();
      }
      else
      {
        sz_--;
        nodo -> get_prev() -> set_next(nodo -> get_next());
        nodo -> get_next() -> set_prev(nodo -> get_prev());
        nodo -> set_prev(NULL);
        nodo -> set_next(NULL);
        return nodo;
      }
    }

  template <class T>
  void dll_t<T>::merge (dll_t<T>& lista2)
  {
    get_tail() -> set_next(lista2.get_head());
    lista2.get_head() -> set_prev(get_tail());
    set_tail(lista2.get_tail());
    sz_ += lista2.get_size();
    lista2.set_head(NULL);
    lista2.set_tail(NULL);
    lista2.get_size() = 0;
  }

  template <class T>
  void dll_t<T>::sort (void)
  {
    dll_node_t<T>* pivote;

    for (int i = 0; i < sz_ - 1; i++)
    {
      pivote = head_;
      for (int j = 0; j < i; j++)
      {
        pivote = pivote -> get_next(); // pivote = pivote + i;
      }

      dll_node_t<T>* aux = pivote;
      dll_node_t<T>* min = aux;

      while (aux != tail_)
      {
        aux = aux -> get_next();
        if (aux -> get_data() < min -> get_data())
        {
          min = aux;
        }
      }

      if (pivote == head_)
      {
        insert_head(extract(min));
      }
      else
      {
        pivote = pivote -> get_prev();
        insert_after(pivote, extract(min));
      }

    }
  }

  template <class T>
  void dll_t<T>::modificacion (dll_t<T>& lista2, dll_t<T>& resultado)
  {
    dll_node_t<T>* ptr1;
    dll_node_t<T>* ptr2;

    while (!empty() && !lista2.empty())
    {
      ptr1 = get_head();
      ptr2 = lista2.get_head();

      if (ptr1 -> get_data() < ptr2 -> get_data())
      {
        resultado.insert_tail(extract_head());
      }
      else
      {
        resultado.insert_tail(lista2.extract_head());
      }
    }

    while (!empty())
    {
      resultado.insert_tail(extract_head());
    }

    while (!lista2.empty())
    {
      resultado.insert_tail(lista2.extract_head());
    }

  }

  template <class T>
    int& dll_t<T>::get_size(void) {
      return sz_;
    }
}
