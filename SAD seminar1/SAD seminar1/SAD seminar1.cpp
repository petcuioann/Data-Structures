#include <iostream>
#include <cassert>

using namespace std;

int cautare_binara(int* list, int num_toSearch, int left, int right); // functia de cautare bianra

void test_cautare_binara(); // procedura de testare a functiei


int main()
{
    test_cautare_binara();

    int* num_ofNum = new int;
    cout << "dati numarul de numere al listei: ";  cin >> *num_ofNum; // introudcere numarul de elemente al listen

    int* list = new int[*num_ofNum];
    cout << "dati numerele din lista: ";  for (int i = 0; i < *num_ofNum; i++) cin >> list[i]; // introducere lista de elemente

    int* num_toSearch = new int;
    cout << "dati numarul cautat: "; cin >> *num_toSearch; // introducere numarul de cautat

    cout << "indexul numarului cautat este " << cautare_binara(list, *num_toSearch, 0, *num_ofNum); // apelare cautare_binara

    delete[] list; delete num_ofNum; delete num_toSearch; // stergere variabile

    return 0;

}


int cautare_binara(int* list, int num_toSearch, int left, int right) {

    if (left > right) return -1;

    int mid = (left + right) / 2;

    if (list[mid] == num_toSearch) return mid;

    else if (list[mid] < num_toSearch) return cautare_binara(list, num_toSearch, mid + 1, right);

    else if (list[mid] > num_toSearch) return cautare_binara(list, num_toSearch, left, mid - 1);

}

void test_cautare_binara() {

    int list[] = { 1, 2, 3, 4, 5 };

    assert(cautare_binara(list, 3, 0, 5) == 2);
    assert(cautare_binara(list, 3, 0, 4) == 2); // segmentare de dreapta
    assert(cautare_binara(list, 3, 1, 5) == 2); // segmentare de stanga
    assert(cautare_binara(list, 6, 0, 5) == -1); // numarul cautat nu exista

    cout << "test passed" << endl;

}