#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>
#include "Tablica.h"
#include "Lista.h"
#include "Kopiec.h"
#include "Test.h"
#include <windows.h>
using namespace std;

// testy struktur

LARGE_INTEGER startTimer()
{
LARGE_INTEGER start;
DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
QueryPerformanceCounter(&start);
 SetThreadAffinityMask(GetCurrentThread(), oldmask);
 return start;
}

LARGE_INTEGER endTimer()
{
LARGE_INTEGER stop;
DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
QueryPerformanceCounter(&stop);
SetThreadAffinityMask(GetCurrentThread(), oldmask);
return stop;
}

void Test::testTablicy(){
	
	Tablica tablica;			//stworzenie struktury, zegara, wejsc, wyjsc oraz zmiennych
	clock_t time_req;				
	string outputData;
    string inputData;
    ofstream outputFile;
    ifstream inputFile;
	int value;
	int position;
	int choose=9;
	double tm;
	LARGE_INTEGER performanceCountStart,performanceCountEnd; 
    
    cout << "Plik tekstowy z danymi: ";		
    cin >> inputData;							//wprowadzenie nazwy pliku z danymi

    inputFile.open("Dane/" + inputData);		//proba owtarcia danych
    
    	if (inputFile.is_open()==0){						//sprawdzenie poprawnosci otwarcia
			cout<<"Blad odczytu pliku"<<endl;
			while(inputFile.is_open()==0){					//przy zlej nazwie, wpisywanie nazwy az do momentu
				cout<<"Wprowadz poprawna nazwe pliku: ";	//wpisania poprawnej
				cin >> inputData;
				inputFile.open("Dane/" + inputData);
			}
        }
        
        
    cout << "Plik wynikowy: ";			
    cin >> outputData;				//ustalenie nazwy pliku z wynikami
    

	outputFile.open("Dane/" + outputData, fstream::out);	//utworzenie,otworzenie pliku wyjsciowego

        if (outputFile.is_open()==0) {
            cout << "Blad odczytu pliku" << endl;
          	return;
			}
    
    performanceCountStart = startTimer();
    while (inputFile.good()) {			//wczytywanie danych az do konca
    	inputFile >> value;				//wpisywanie ich do zmiennej 
        tablica.addLast(value);			//dodawanie danych do stuktury poprzez zmienna 
    }
    performanceCountEnd = endTimer();
    tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
    outputFile <<"Czas wczytywania danych do struktury, dodajac od konca: "<<tm<< endl;
    cout<<endl;
    cout<<"Tablica zostala wypelniona danymi"<<endl<<endl;
    

    
    while(choose!=0){						// koniec testowania dopiero przy wyborze "wyjscie"
    	cout<<"Menu:"<<endl;										//Menu wyboru
    	cout<<"[1].Dodaj na poczatku"<<endl;
    	cout<<"[2].Dodaj na koncu"<<endl;
    	cout<<"[3].Dodaj na pozycji"<<endl;
    	cout<<"[4].Usun z poczatku"<<endl;
    	cout<<"[5].Usun z konca"<<endl;
    	cout<<"[6].Usun z pozycji"<<endl;
    	cout<<"[7].Sprawdz czy istnieje wartosc"<<endl;
    	cout<<"[8].Wydrukuj tablice"<<endl;
    	cout<<"[0].Wyjscie"<<endl;
    	cout<<endl;
    	cout<<"Twoj wybor: ";
    	cin>>choose;
    	cout<<endl;
	
    switch(choose){
    	case 1:	
    		cout<<"Wprowadz wartosc jaka zostanie dodana na poczatku tablicy: ";
    		cin>>value;
    		performanceCountStart = startTimer();	
    		tablica.addFirst(value);	//wykonanie operacji
    		performanceCountEnd = endTimer();
    		tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
    		outputFile << "Czas dodania na poczatek: "<<tm<< endl;
			//outputFile << tm<< endl;	//wpisanie czasu dzialania do pliku z wynikami
    	break;
	//analogicznie
    	case 2:
    		cout<<"Wprowadz wartosc jaka zostanie dodana na koncu tablicy: ";
    		cin>>value;
    		performanceCountStart = startTimer();
    		tablica.addLast(value);
    		performanceCountEnd = endTimer();
    		tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
    		outputFile <<"Czas dodania na koniec: "<< tm<< endl;
    	break;
    //analogicznie	
    	case 3:
    		cout<<"Wprowadz wartosc jaka zostanie dodana na wybranej pozycji tablicy: ";
    		cin>>value;
    		cout<<"Wprowadz pozycje: ";
    		cin>>position;
    		performanceCountStart = startTimer();
    		
    		tablica.addSomewhere(value,position);
    		performanceCountEnd = endTimer();
    		tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
    		outputFile << "Czas dodania na na okreslona pozycje: "<<tm<< endl;
    	break;
    //analogicznie	
    	case 4:
    		cout<<"Usuniecie pierwszej wartosci z tablicy "<<endl;
    		performanceCountStart = startTimer();
    		
    		tablica.deleteFirst();
    		performanceCountEnd = endTimer();
    		tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
    		outputFile << "Czas usuniecia pierwszej pozycji: "<<tm<< endl;
    	break;
    //analogicznie	
    	case 5:
    		cout<<"Usuniecie ostatniej wartosci z tablicy "<<endl;
    		performanceCountStart = startTimer();
    		
    		tablica.deleteLast();
    		performanceCountEnd = endTimer();
    		tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
    		outputFile << "Czas usuniecia ostatniej pozycji: "<<tm<< endl;
    	break;
    //analogicznie	
    	case 6:
    		cout<<"Wprowadz pozycje jaka zostanie usunieta z tablicy: ";
    		cin>>position;
    		performanceCountStart = startTimer();
    		
    		tablica.deleteSomewhere(position);
    		performanceCountEnd = endTimer();
    		tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
    		outputFile << "Czas usuniecia wybranej pozycji: "<<tm<< endl;
    	break;
    //analogicznie	
    	case 7:
    		cout<<"Podaj wartosc w celu sprawdzenia czy znajduje sie w tablicy: ";
    		cin>>value;
    		performanceCountStart = startTimer();
    		
    		tablica.ifExist(value);
    		performanceCountEnd = endTimer();
    		tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
    		outputFile <<"Czas znalezienia wartosci: "<< tm<< endl;
    	break;
    //analogicznie		
    	case 8:
    		cout<<"Drukowanie tablicy: "<<endl;
    		performanceCountStart = startTimer();
    		tablica.print();
    		performanceCountEnd = endTimer();
    		tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
    		outputFile << "Czas drukowania: "<<tm<< endl;
    	break;
}
}
	inputFile.close();		//zamkniecie plikow 
   	outputFile.close();
}

//testowanie listy odbywa sie analogicznie do tesowania tablicy
void Test::testListy(){
	
	Lista lista;
	clock_t time_req;
	string outputData;
    string inputData;
    ofstream outputFile;
    ifstream inputFile;
	int value;
	int position;
	int choose=9;
	double tm;
	LARGE_INTEGER performanceCountStart,performanceCountEnd; 
    
    cout << "Plik tekstowy z danymi: ";
    cin >> inputData;

    inputFile.open("Dane/" + inputData);
    
    	if (inputFile.is_open()==0){
			cout<<"Blad odczytu pliku"<<endl;
			while(inputFile.is_open()==0){
				cout<<"Wprowadz poprawna nazwe pliku: ";
				cin >> inputData;
				inputFile.open("Dane/" + inputData);
			}
        }
        
        
    cout << "Plik wynikowy: ";
    cin >> outputData;
    

	outputFile.open("Dane/" + outputData, fstream::out);

        if (outputFile.is_open()==0) {
            cout << "Blad odczytu pliku" << endl;
          	return;
			}
    
	performanceCountStart = startTimer();    
    while (inputFile.good()) {
    	inputFile >> value;
        lista.addLast(value);
    }
    
    performanceCountEnd = endTimer();
    tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
	outputFile <<"Czas wczytywania danych do struktury, dodajac od konca: "<< tm<< endl;

    cout<<endl;
    cout<<"Lista zostala wypelniona danymi"<<endl<<endl;
    

    
    while(choose!=0){
	    cout<<"Menu:"<<endl;
	    cout<<"[1].Dodaj na poczatku"<<endl;
	    cout<<"[2].Dodaj na koncu"<<endl;
	    cout<<"[3].Dodaj na pozycji"<<endl;
	    cout<<"[4].Usun z poczatku"<<endl;
	    cout<<"[5].Usun z konca"<<endl;
	    cout<<"[6].Usun z pozycji"<<endl;
	    cout<<"[7].Sprawdz czy istnieje wartosc"<<endl;
	    cout<<"[8].Wydrukuj liste"<<endl;
	    cout<<"[0].Wyjscie"<<endl;
    	cout<<endl;
    	cout<<"Twoj wybor: ";
    	cin>>choose;
    	cout<<endl;
	
    switch(choose){
    	case 1:
    		cout<<"Wprowadz wartosc jaka zostanie dodana na poczatku listy: ";
    		cin>>value;
    		performanceCountStart = startTimer();
    		
    		lista.addFirst(value);
    		performanceCountEnd = endTimer();
    		tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
    		outputFile << "Czas dodania na poczatek: "<<tm<< endl;
    	break;
	
    	case 2:
    		cout<<"Wprowadz wartosc jaka zostanie dodana na koncu listy: ";
    		cin>>value;
    		performanceCountStart = startTimer();
    		
    		lista.addLast(value);
    		performanceCountEnd = endTimer();
    		tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
    		outputFile <<"Czas dodania na koniec: "<< tm<< endl;
    	break;
    	
    	case 3:
    		cout<<"Wprowadz wartosc jaka zostanie dodana na wybranej pozycji listy: ";
    		cin>>value;
    		cout<<"Wprowadz pozycje: ";
    		cin>>position;
    		performanceCountStart = startTimer();
    		
    		lista.addSomewhere(value,position);
    		performanceCountEnd = endTimer();
    		tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
    		outputFile << "Czas dodania na na okreslona pozycje: "<<tm<< endl;
    	break;
    	
    	case 4:
    		cout<<"Usuniecie pierwszej wartosci z listy "<<endl;
    		performanceCountStart = startTimer();
    		
    		lista.deleteFirst();
    		performanceCountEnd = endTimer();
    		tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
    		outputFile << "Czas usuniecia pierwszej pozycji: "<<tm<< endl;
    	break;
    	
    	case 5:
    		cout<<"Usuniecie ostatniej wartosci z listy: "<<endl;
    		performanceCountStart = startTimer();
    		
    		lista.deleteLast();
    		performanceCountEnd = endTimer();
    		tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
    		outputFile << "Czas usuniecia ostatniej pozycji: "<<tm<< endl;
    	break;
    	
    	case 6:
    		cout<<"Wprowadz pozycje jaka zostanie usunieta z listy: ";
    		cin>>position;
    		performanceCountStart = startTimer();
    		//
    		lista.deleteSomewhere(position);
    		performanceCountEnd = endTimer();
    		tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
    		outputFile << "Czas usuniecia wybranej pozycji: "<<tm<< endl;
    	break;
    	
    	case 7:
    		cout<<"Podaj wartosc w celu sprawdzenia czy znajduje sie w liscie: ";
    		cin>>value;
    		performanceCountStart = startTimer();
    		
    		lista.ifExist(value);
    		performanceCountEnd = endTimer();
    		tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
    		outputFile <<"Czas znalezienia wartosci: "<< tm<< endl;
    	break;
    		
    	case 8:
    		cout<<"Drukowanie listy: "<<endl;
    		performanceCountStart = startTimer();
    		lista.print();
    		performanceCountEnd = endTimer();
    		tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
    		outputFile << "Czas drukowania: "<<tm<< endl;
    	break;
}
}
	inputFile.close();
   	outputFile.close();
}

//testowanie kopca odbywa sie analogicznie do tesowania tablicy
void Test::testKopca(){
	
	Kopiec kopiec;
	clock_t time_req;
	string outputData;
    string inputData;
    ofstream outputFile;
    ifstream inputFile;
	int value;
	int position;
	int choose=9;
	double tm;
	LARGE_INTEGER performanceCountStart,performanceCountEnd; 
    
    cout << "Plik tekstowy z danymi: ";
    cin >> inputData;

    inputFile.open("Dane/" + inputData);
    
    	if (inputFile.is_open()==0){
			cout<<"Blad odczytu pliku"<<endl;
			while(inputFile.is_open()==0){
				cout<<"Wprowadz poprawna nazwe pliku: ";
				cin >> inputData;
				inputFile.open("Dane/" + inputData);
			}
        }
        
        
    cout << "Plik wynikowy: ";
    cin >> outputData;
    

	outputFile.open("Dane/" + outputData, fstream::out);

        if (outputFile.is_open()==0) {
            cout << "Blad odczytu pliku" << endl;
          	return;
			}
    
	performanceCountStart = startTimer();
    
    while (inputFile.good()) {
    	inputFile >> value;
        kopiec.add(value);
    }
    
    performanceCountEnd = endTimer();
    tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
	outputFile <<"Czas wczytywania danych do struktury, dodajac od konca: "<< tm<< endl;
    
    cout<<endl;
    cout<<"Kopiec zostala wypelniony danymi"<<endl<<endl;
    
    
    while(choose!=0){
    	cout<<"Menu:"<<endl;
	    cout<<"[1].Dodaj do kopca"<<endl;
	    cout<<"[2].Usun korzen"<<endl;
	    cout<<"[3].Sprawdz czy istnieje"<<endl;
	    cout<<"[4].Wydrukuj kopiec"<<endl;
	    cout<<"[0].Wyjscie"<<endl;
    	cout<<endl;
    	cout<<"Twoj wybor: ";
    	cin>>choose;
    	cout<<endl;
	
    switch(choose){
    	case 1:
    		cout<<"Wprowadz wartosc jaka zostanie dodana do kopca: ";
    		cin>>value;
    		performanceCountStart = startTimer();
    		
    		kopiec.add(value);
    		performanceCountEnd = endTimer();
    		tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
    		outputFile << "Czas dodania do kopca: "<<tm<< endl;
    	break;
	
    	case 2:
    		cout<<"Usuwanie korzenia "<<endl;
    		performanceCountStart = startTimer();
    		
    		kopiec.del();
    		performanceCountEnd = endTimer();
    		tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
    		outputFile << "Czas usuwania korzenia: "<<tm<< endl;
    	break;
    	
    	case 3:
    		cout<<"Podaj wartosc w celu sprawdzenia czy znajduje sie w kopcu: ";
    		cin>>value;
    		performanceCountStart = startTimer();
    		
    		kopiec.ifExist(value);
    		performanceCountEnd = endTimer();
    		tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
    		outputFile <<"Czas znalezienia wartosci: "<< tm<< endl;
    	break;
    	
       	case 4:
    		cout<<"Drukowanie kopca: "<<endl;
    		performanceCountStart = startTimer();
    		kopiec.print();
    		performanceCountEnd = endTimer();
    		tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
    		outputFile << "Czas drukowania: "<<tm<< endl;
    	break;
}
}
	inputFile.close();
   	outputFile.close();
}

void Test::generateData()
{
	
	string outputData;
    ofstream outputFile;
	int size, range, value;
	
	cout << "Plik wynikowy: ";			
    cin >> outputData;				//ustalenie nazwy pliku z wynikami
    
	outputFile.open("Dane/" + outputData, fstream::out);

	cout<<"Wprowadz ilosc wartosci tworzonych: ";
	cin>>size;
	cout<<"Wprowadz zakres: ";
	cin>>range;
	srand(time(NULL));
	for (int i = 0; i < size;i++){
		value = rand() % range;
		outputFile << value <<endl;
	}
	outputFile.close();
}
