#pragma once

#include <cstdio>
#include <iostream>
#include <iomanip>

#include <cassert>

using namespace std;
namespace AEDA {

	template <class T>
	class vector_t{
	private:
		T*      v_;
		int     sz_;

	public:

		vector_t(void):
			v_(NULL),
			sz_(0) {}

		vector_t(int sz):
			v_(NULL),
			sz_(sz) {

			crea_vector();
		}

		~vector_t(void){

			destruye_vector();
		}

		const int& size ()
		{
			return sz_;
		} 

		void resize(int sz)
		{
			destruye_vector();
			sz_ = sz;
			crea_vector();
		}

		int get_sz(void) const
		{
			return sz_;
		}

		virtual T get_v(int pos) const{
		
			assert((pos < sz_) && ((pos >= 0)));

			return v_[pos];
		}

		virtual T& get_set_v(int pos){

			assert((pos < sz_) && ((pos >= 0)));

			return v_[pos];
		}

		T* begin()
		{
			return v_;
		}

		void push_back(const T& dato)
		{
			v_[sz_ - 1] = dato;
		}

		ostream& write(ostream& os) const{
	
			os << setw(5) <<  sz_ << endl;
			os << endl;

			for(int i = 0; i < sz_; i ++){
				v_[i].write(os);
				os << " ";
			}
			os << endl;
			return os;
		}
		

		istream& read(istream& is){
	
			is >> sz_;

			resize(sz_);

			for(int i = 0; i < sz_; i ++)
			 	is >> v_[i];

			return is;
		}

	private:

		void crea_vector(void){
			v_ = new T[sz_];
		}

		void destruye_vector(void)
		{
			if (v_ != NULL){
				delete [] v_;
				v_ = NULL;
			}
		}

	};

	
	template <>
	ostream& vector_t<double>::write(ostream& os) const{

		os << setw(6) <<  sz_ << endl;

		for(int i = 0; i < sz_; i ++)
		 	os << setw(8) << fixed << setprecision(2) << v_[i] << " ";

		os << endl;
		return os;
	}


	template <>
	ostream& vector_t<int>::write(ostream& os) const{

		os << setw(8) <<  sz_ << endl;

		for(int i = 0; i < sz_; i ++)
		 	os << setw(8)  << v_[i] << " ";

		os << endl;
		return os;
	}
	template <class T>
	ostream& operator << (ostream& os, vector_t<T> vector)
	{
		vector.write(os);
		return os;
	}
	
	
}
