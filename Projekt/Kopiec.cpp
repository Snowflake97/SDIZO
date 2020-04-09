#include <iostream>
#include <math.h>
#include "Kopiec.h"
using namespace std;

// konstruktor, utworzenie nowej pustej tablicy, wielkosc = 0
Kopiec::Kopiec(){
	root=new Tablica();
	size=0;
}

// destruktor
Kopiec::~Kopiec(){
	delete root;
}

//dodawanie elementu do kopca
void Kopiec::add(int value){

	if (size == 0) {				//dla pustego kopca dodanie elementu 
		root->addFirst(value);
		size++;
		return;
	}
	size++;							//dla kopca posiadajacego dane, zwiekszenie wielkosci, 
	root->addLast(value);			//dodanie nowego elementu i naprawa drzewa przez zamiany wartosci
	int i=size-1;
	int j=(i-1)/2;
	while (root->getValue(j) < root->getValue(i)) {		//tak dlugo az struktura bedzie prawidlowa
		int pom = root->getValue(j);
		root->change(root->getValue(i),j);
		root->change(pom,i);
		i=j;
		j=(i-1)/2;	
}
}

//drukowanie wszystkich elementow od poczatku do konca
void Kopiec::print(){		
	
	for(int i=0;i<size;i++){
		int j=(int)log2(i);
		if (i == (int)exp2(j + 1) - 1)
		cout<<endl;
		cout<<root->getValue(i)<<", ";
	}
}

//usuwanie korzenia
void Kopiec::del(){
	
	if(size==0)    				// dla 0 wielosci, brak korzenia, brak aktywnosci
	return;
	
	size--;							
	int v=root->getValue(size);			
	int i=0;
	int j=1;
	while(j<size){												//usuniecie korzenia i naprawa drzewa od dolu
		if(j+1<size && root->getValue(j+1)>root->getValue(j))	//poprzez podmiany tak dlugo az drzewo
		j++;													//bedzie spelnialo swoje zaleznosci
		if(v>=root->getValue(j)){
			root->change(v,i);
			break;
		}
		root->change(root->getValue(j),i);
		i=j;
		j=2*j+1;
	}
	root->change(v,i);
	
}

//przeszukiwanie kopca od poczatku po kolei i sprawdzanie czy rzadana wartosc jest zgodna z wartoscia elementow
bool Kopiec::ifExist(int value){			
	for(int i=0;i<size;i++){
		if(root->getValue(i)==value)
		return true;
	}
	return false;
}

