#include <iostream>

using namespace std;

template <class T>
class LIFO {

private:

	int CAP = 1;
	T* Elem = new T[CAP];
	int noElem = 0;

public:

	LIFO() {};
	LIFO(int CAP) : CAP(CAP) {};

	~LIFO() { delete[] Elem; }

	void resize() {
		if (noElem + 1== CAP) {
			CAP *= 2;
			T* Elem = new T[CAP];
			for (int i = 0; i < noElem; i++)Elem[i] = this->Elem[i];
			this->Elem = Elem;
		}
	}

	void push(T elem) {
		resize();
		Elem[noElem++] = elem;
	}

	T pop() {
		if (noElem == 0) return -1;
		T elem = Elem[--noElem];
		Elem[noElem + 1] = -1;
		return elem;
	}

	bool isEmpty() { return noElem == 0 ? true : false; }

	int get_noElem() { return noElem; }

	T* getAll() { return Elem; }

	T getAt(int pos) { return Elem[pos]; }

	int getPos(T elem) {
		for (int i = 0; i < noElem; i++)
			if (Elem[i] == elem) return i;
		return -1;
	}

};


#include "assert.h"
void Test_LIFO(){

	LIFO<int> test;
	test.push(3);
	test.push(4);
	test.push(5);
	test.push(2);

	assert(test.pop() == 2);
	assert(test.pop() == 5);
	assert(test.get_noElem() == 2);

	cout << "Test successful" << endl;
	
}

int main()
{
	Test_LIFO();

	LIFO<int> a(10);

	for (int i = 0; i < 13; i++) {
		a.push(i);
	}

	cout
		<< "\nnr elem: " << a.get_noElem()
		<< "\nelem: ";
	for (int i = 0; !a.isEmpty(); i++)cout << a.pop() << " ";

}
