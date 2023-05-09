#include "Collection.h"

template <class TElem>
Collection<TElem>::Collection()
	: elements(nullptr), occurrences(nullptr), capacity(5), distinct_elements(0) {};

template <class TElem>
Collection<TElem>::Collection(int capacity)
	: elements(new TElem[capacity]), occurrences(new int[capacity]), capacity(capacity), distinct_elements(0) {
	for (int i = 0; i < capacity; i++) {
		occurrences[i] = 0;
	}
}

// destroys the collection
template <class TElem>
Collection<TElem>::~Collection() {
	delete[] elements;
	delete[] occurrences;
}

// adds a new elem to elements
template <class TElem>
void Collection<TElem>::add(TElem elem) {
	if (distinct_elements == capacity) resize();
	if (search(elem) == -1) {
		occurrences[distinct_elements] = 1;
		elements[distinct_elements] = elem;
		distinct_elements++;
	}
	else
		occurrences[search(elem)]++;
}

// deletes an element from elements
template <class TElem>
void Collection<TElem>::del(TElem elem) {
	if (occurrences[search(elem)] > 1)
		occurrences[search(elem)] --;
	else if (occurrences[search(elem)] == 1) {
		for (int i = search(elem); i < distinct_elements; i++) {
			occurrences[i] = occurrences[i + 1];
			elements[i] = elements[i + 1];
		}
		distinct_elements--;
	}
}

// returns position of element
template <class TElem>
int Collection<TElem>::search(TElem elem) {
	for (int i = 0; i < distinct_elements; i++)
		if (elements[i] == elem)
			return i;
	return -1;
}

// returns elem from position
template <class TElem>
TElem Collection<TElem>::getAt(int pos) {
	if (pos >= distinct_elements or pos < 0)
		return -1;
	else
		return elements[pos];
}

// returns amount of distinct elements
template <class TElem>
int Collection<TElem>::size() {
	return distinct_elements;
}

// returns num of occurrences of an element
template <class TElem>
int Collection<TElem>::occurrences(TElem elem) {
	return occurrences[search(elem)];
}

// updates capacity of elements and occurrences
template <class TElem>
void Collection<TElem>::resize() {
	TElem* newElems = new TElem[capacity * 2];
	int* newOccurrences = new int[capacity * 2];
	for (int i = 0; i < distinct_elements; i++) {
		newElems[i] = elements[i];
		newOccurrences[i] = occurrences[i];
	}
	capacity *= 2;

	delete[] elements;
	delete[] occurrences;

	elements = newElems;
	occurrences = newOccurrences;
}