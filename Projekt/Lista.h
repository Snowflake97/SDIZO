#ifndef Lista_h_
#define Lista_h_

class Elements{
	public:
		int data;
		Elements* next;
		Elements* prev;
		
		Elements(int, Elements *, Elements *);
};

class Lista{
	public:
	
	int size;
	Elements *first;
	Elements *last;
	Elements *actual;
	
	Lista();
	~Lista();
	
	void addFirst(int value);
	void addLast(int value);
	void addSomewhere(int value, int position);
	
	void deleteFirst();
	void deleteLast();
	void deleteSomewhere(int position);
	void dodajnakoniec(int value);
	
	void print();
	bool ifExist(int value);
	
	Elements* search(int position);
};






#endif
