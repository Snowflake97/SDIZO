#include <iostream>
#include "Tablica.h"
using namespace std;

//tworzenie nowej tablicy
Tablica::Tablica(){	
    wskHead = NULL;
    size = 0;	
}

//destruktor
Tablica::~Tablica() {
	
    delete[]wskHead;
	 
}

//pobieranie wartosci z elementu na danej pozycji
int Tablica::getValue(int position){
	
	return *(wskHead + position); //przesuniecie ideksu na dana pozycje i wyluskanie w celu wydobycie wartosci
}

//nadpisanie elementu tablicy przez nowa wartosc
//przesuniecie indeksu, wyluskanie na wartosc i nadpisanie przez nowa
void Tablica::change(int value, int position)
{

	*(wskHead + position) = value;
}

//dodanie pierwszego elementu
void Tablica::addFirst(int value){
	
	int *newWskHead=new int[size+1];	//nowy wskaznik na nowa tablice
	newWskHead[0]=value;				//pierwszy element ma wartosc podawana 
	for(int i=0;i<size;i++)				//reszta jest przepisywana z przesunienciem o 1 w prawo
		newWskHead[i+1]=wskHead[i];		
	delete wskHead;						//usuniecie starego wskaznika
    wskHead=newWskHead;					//oraz nadpisanie go nowym
    size++;								//dodajac element zwiekszamy zatem wielkosc tablicy
}

//dodanie ostatniego elementu podobnie jak pierwszego
//nowy wskaznik na nowa tablice o 1 wieksza
//przepisanie dokladnie wartosc po wartosci
//wpisanie nowej wartosci jako wartosc ostatnia
//usuniecie i nadpisanie wskaznika
//zwiekszenie wielkosci
void Tablica::addLast(int value){
	
	int *newWskHead=new int[size+1];	
	for(int i=0;i<size;i++)
		newWskHead[i]=wskHead[i];
		newWskHead[size]=value;
	delete wskHead;
    wskHead=newWskHead;
    size++;
}

//dodanie wartosci na zadana pozycje
//przepisywanie wartosci do momentu znalezienia pozycji
//dodanie nowej wartosci
//przepisywanie wartosci z przesunienciem
//usuniecie i nadpisanie wskaznika
//zwiekszenie wielkosci
void Tablica::addSomewhere(int value, int position){
	
	int *newWskHead=new int[size+1];
	for(int i=0;i<position;i++)
		newWskHead[i]=wskHead[i];
		
	newWskHead[position]=value;
	
	for(int i=position;i<size;i++)
		newWskHead[i+1]=wskHead[i];
		
	delete wskHead;
    wskHead=newWskHead;
    size++;
	

} 

//usuniencie elementu pierwszego
//przepisywanie elementow do nowej tablicy z przesunienciem o 1 w lewo
//usuniecie i nadpisanie wskaznika
//zmniejszenie wielkosci
void Tablica::deleteFirst(){
	
	int *newWskHead=new int[size-1];
	for(int i=0;i<size-1;i++)
		newWskHead[i]=wskHead[i+1];
	delete wskHead;
    wskHead=newWskHead;
    size--;
	
}

//usuniencie ostatniego elementu
//przepisanie wartosci krok po kroku, poza ostatnia
//usuniecie i nadpisanie wskaznika
//zmniejszenie wielkosci
void Tablica::deleteLast(){
	int *newWskHead=new int[size-1];
	for(int i=0;i<size-1;i++)
		newWskHead[i]=wskHead[i];
	delete wskHead;
    wskHead=newWskHead;
    size--;
}

//usuniecie elementu w zadanym miejscu
//przepisywanie wartosci krok po kroku do miejca wyznaczonego
//nastepnie przepisywanie z przesunienciem o 1 w lewo
//usuniecie i nadpisanie wskaznika
//zmniejszenie wielkosci
void Tablica::deleteSomewhere(int position){

	int *newWskHead=new int[size-1];
	for(int i=0;i<position;i++)
		newWskHead[i]=wskHead[i];
	
	for(int i=position;i<size-1;i++)
		newWskHead[i]=wskHead[i+1];
		
	delete wskHead;
    wskHead=newWskHead;
    size--;	
}

//przeszukiwanie tablicy w celu sprawdzenia czy istnieje w niej zadana wartosc
//przeszukiwanie od poczatku do konca
//porownywanie wartosci elementow z szukana wartoscia
//zwrocenie znalezienia lub jego braku
bool Tablica::ifExist(int value){
	for(int i=0;i<size;i++){
		if(wskHead[i]==value)
		return true;
	}
	return false;
}

//wyswietlanie tablicy
//przeszukiwanie tablicy oraz wypisywanie kazdej jej wartosci od poczatku do konca
void Tablica::print(){
	for(int i=0; i<size;i++)
	{
		cout<<wskHead[i]<<endl;
	}
	
	cout<<endl<<endl;
}
