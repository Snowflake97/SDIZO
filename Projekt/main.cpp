#include <iostream>
#include <conio.h>
#include "Tablica.h"
#include "Lista.h"
#include "Kopiec.h"
#include <iostream>
#include <fstream>
#include "Test.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	

	Test test;
	int choose=9;
	
	cout<<"Adrian Sniezek 235984"<<endl<<endl;
	
	
	while(choose!=0){
		cout<<"Menu:"<<endl;
    	cout<<"[1].Testowanie tablicy"<<endl;			//Menu wyboru
    	cout<<"[2].Testowanie listy"<<endl;
    	cout<<"[3].Testowanie kopca"<<endl;
    	cout<<"[4].Tworzenie losowych danych"<<endl;
    	cout<<"[0].Wyjscie"<<endl;
    	cout<<endl;
    	cout<<"Twoj wybor: ";			// tak dlugo az zostanie wybrane "wyjscie"
    	cin>>choose;
    	cout<<endl;
	
    switch(choose){
    	case 1:
			test.testTablicy(); 	//testowanie tablicy
    	break;
	
    	case 2:
    		test.testListy(); 		//testowanie listy
    	break;
    	
    	case 3:
    		test.testKopca();		//testowanie kopca
    	break;
    	case 4:
    		test.generateData();
    	
}
}

Lista lista;
	
	lista.dodajnakoniec(7);
	lista.dodajnakoniec(32);
	lista.dodajnakoniec(32);
	lista.dodajnakoniec(32);
	lista.dodajnakoniec(32);
	lista.print();
	return 0;
}
