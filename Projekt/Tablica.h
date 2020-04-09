#ifndef Tablica_h_
#define Tablica_h_

class Tablica {
	
	public:
	
	int size;
	int *wskHead;
	
	Tablica();
	~Tablica();
	
	int getValue(int position);
	void change(int value, int position);

	
	void addFirst(int value);
	void addLast(int value);
	void addSomewhere(int value, int position);
	
	void deleteFirst();
	void deleteLast();
	void deleteSomewhere(int position);
	
	void print();
	bool ifExist(int value);
};

#endif
