//
// Created by camel on 4/10/2023.
//

#include "TestList.h"
#include "List.h"
#include <C:\Users\ipetc\Desktop\SAD seminar 4\SAD seminar 4\List.cpp>
#include <assert.h>

void TestList::test_push_back()
{
    List<int> newList;
    newList.push_back(1);
    newList.push_back(2);
    newList.push_back(3);
    newList.push_back(4);
    assert(newList.size() == 4);
    std::cout << "Test successful: push_back" << std::endl;
}

void TestList::test_get_at() {
    List<int> newList;
    newList.push_back(1);
    newList.push_back(2);
    newList.push_back(3);
    newList.push_back(4);
    assert (newList.get_at(0) == 1);
    assert (newList.get_at(1) == 2);
    assert (newList.get_at(2) == 3);
    assert (newList.get_at(3) == 4);
    std::cout << "Test successful: get_at" << std::endl;
}

void TestList::test_update() {
    List<int> newList;
    newList.push_back(1);
    newList.push_back(2);
    newList.push_back(3);
    newList.push_back(4);
    newList.update(2, 17);
    assert (newList.get_at(0) == 1);
    assert (newList.get_at(1) == 2);
    assert (newList.get_at(2) == 17);
    assert (newList.get_at(3) == 4);
    std::cout << "Test successful: update" << std::endl;
}

//bonus:

void TestList::test_set_at()
{
    List<int> newList;
    newList.push_back(1);
    newList.push_back(2);
    newList.push_back(3);
    newList.push_back(4);

    newList.set_at(0, 5);
    newList.set_at(1, 6);
    newList.set_at(newList.size() - 1, 7);

    assert(newList.get_at(0) == 5);
    assert(newList.get_at(1) == 6);
    assert(newList.get_at(newList.size() - 1) == 7);

    std::cout << "Test successful: set_at" << std::endl;
}

void TestList::test_delete_at()
{
    List<int> newList;
    newList.push_back(1);
    newList.push_back(2);
    newList.push_back(3);
    newList.push_back(4);

    assert(newList.size() == 4);

    assert(newList.delete_at(2) == 3); // [2]
    assert(newList.size() == 3);
    assert(newList.get_at(0) == 1);
    assert(newList.get_at(1) == 2);
    assert(newList.get_at(2) == 4);

    assert(newList.delete_at(0) == 1); //[0]
    assert(newList.size() == 2);
    assert(newList.get_at(0) == 2);
    assert(newList.get_at(1) == 4);

    assert(newList.delete_at(1) == 4); // [1]
    assert(newList.size() == 1);
    assert(newList.get_at(0) == 2);

    assert(newList.delete_at(0) == 2); // [0]
    assert(newList.size() == 0);

    assert(newList.is_empty()); // test_is_empty()

    std::cout << "Test successful: delete_at" << std::endl;
}
