#ifndef Kopiec_h_
#define Kopiec_h_
#include "Tablica.h"

class Kopiec{
	private:
		int size;
		Tablica *root;
		
		
	public:
		Kopiec();
		~Kopiec();
		void add(int value);
		void del();
		void print();
		bool ifExist(int value);

};


#endif
