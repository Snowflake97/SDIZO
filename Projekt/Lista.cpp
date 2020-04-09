#include "Lista.h"
#include <iostream>
using namespace std;

//funkcja umozliwiajaca nam porusznie sie poprzez wskazniki i wyciagjaca wartosc 
Elements::Elements(int data, Elements *next, Elements *prev) {

    Elements::data=data;
    Elements::next=next;
    Elements::prev=prev;
    
}

//tworzenie nowej pustej listy
Lista::Lista(){
	
	first=NULL;
	last=NULL;
	actual=NULL;
	size=0;
	
}

//usuwanie listy, wszystkich wartosci po kolei
Lista::~Lista(){
	    for (int i = 0; i < Lista::size; i++) {
        actual = first->next;
        delete first;
        first = actual;
    }

}

//dodanie wartosci na poczatku
void Lista::addFirst(int value){
	
	Elements *p=new Elements(value,first,NULL);		//tworzenie nowego elementu 
	first=p;
	size++;
	if(p->next!=NULL)
	(p->next)->prev=p;			//umiejscowienie go na poczatku 
	else
	last=p;						//ostatni i pierwszy jak nie ma nastepnika
}

//dodanie wartosci na koniec
void Lista::addLast(int value){
	

		Elements *p=new Elements(value,NULL,last); //wskazniki wskazuja ze ma byc ostatni
		last=p;
		if(p->prev) p->prev->next = p;	//umiejscownie na koncu
		else
		first=p;	// jezeli nie ma poprzednika jest pierwszy i ostatni
		size++;
	}


//dodanie w srodek listy
void Lista::addSomewhere(int value, int position){

	if(position==0)				//dla 0 wielkosci, dodanie jednego elementu jako poczatkowego
	{
		addFirst(value);
		return;
	}
	if(position==size){		//dla pelnej wielkosci, dodanie jako koncowego
		addLast(value);
		return;
	}
	if (position < 0 || position > size) {					// dla podania miejsca nie znajdujacego sie w liscie
    	cout << "W liscie nie ma takiej pozycji" << endl;
    return;
	}
	actual=first;						
	for(int i=0;i<position;i++){				
	actual=actual->next;				//znalezienie znacznika dla zadanej pozycji
	}
	Elements *p = new Elements(value, actual,actual->prev);	//utworzenie elementu dla zadanej pozcyji
	(actual->prev)->next = p;			//umiejscowienie go w danej pozycji 
	actual->prev = p;					//wraz z przesunienciem reszty elementow

	size++;
}

//usuniecie pierwszego elementu, nastepnik staje sie pierwszym
void Lista::deleteFirst(){
	size--;
	Elements *p=first;
	first=p->next;	
	delete p;
}

//usuniecie ostatnie elementu, poprzednik staje sie ostatnim
void Lista::deleteLast(){
	size--;
	Elements *p=last;
	last=p->prev;
	delete p;
}

//usuniecie elementu w srodku listy
//analogicznie dla dodania
//w zaleznosci od wybranej pozycji usuwamy pierwszy, ostatni 
//lub znajdujemy pozycje,przesuwamy calosc w lewo o 1 miejsce poczawszy od elementu nastepnego od wybranego
//usuwamy element, zmiejszamy wielkosc listy
void Lista::deleteSomewhere(int position){

	if(position==0){
		deleteFirst();
		return;
	}
	if(position==size)
	{
		deleteLast();
		return;
	}
	if (position < 0 || position > size) {
    	cout << "W liscie nie ma takiej pozycji" << endl;
    return;
	}
	actual=first;
	for(int i=0;i<position;i++){
	actual=actual->next;
}

	Elements *p=actual;
	(p->prev)->next=p->next;
	delete p;
	size--;	
}

//drukowanie listy, ustawiamy znacznik na element poczatkowy
//przesuwamy sie caly czas na nastepny az do konca
//wyswietlamy kazda wartosc elementu
void Lista::print(){
	
	actual=first;
	for(int i=0;i<size;i++)
	{
	cout<<actual->data<<endl;
	actual=actual->next;
}
}

//sprawdzanie czy dana wartosc znajduje sie w liscie
//analogicznie jak w drukowaniu listy, zaczynamy od pierwszego
//przesuwamy sie na nastepne elementy i porownujemy czy wartosc elementu jest zgodna z wartoscia szukana
bool Lista::ifExist(int value){
	actual=first;
	for(int i=0;i<size;i++)
	{
	if(actual->data==value)
	return true;
	actual=actual->next;
}
	return false;
}

void Lista::dodajnakoniec(int value){
	if(size==0)
	{
		Elements *e = new Elements(value,NULL,NULL);
		first=e;
		size++;
		return;
	}
	Elements *e= new Elements(value,NULL,last);
	Elements *p=first;
	while(p->next!=0)
	p=p->next;
	p->next=e;
	size++;
	
}

