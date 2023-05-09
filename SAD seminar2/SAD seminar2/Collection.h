#pragma once

template <class TElem>
class Collection {

private:

	TElem* elemenets;
	int* occurences;
	int capacity;
	int distinctelements;

public:

	Collection();
	Collection(int capacity);
	~Collection();
	void add(TElem elem);
	void del(TElem elem);
	void resize();
	int search(TElem elem);
	TElem getAt(int pos);
	int size();
	int occurrences(TElem elem);

};