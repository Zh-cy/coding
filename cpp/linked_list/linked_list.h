#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include <iostream>
#include "linked_node.h"


class mylist
{
public:
    mylist();
    ~mylist();
    void push_front(int key);
    void push_back(int key);
    int front() const;
    int back() const;
    void pop_front();
    void pop_back();
    bool find(int key) const;
    void del(int index);
    // bool is_empty() const;
    void insert_before(int index, int key);
    void insert_after(int index, int key); 
    int size() const;
    void Info() const;

    // fast slow pointer, pay attention to the boundary
    // 1. fast pointer moves index steps first
    // 2. move fast and slow pointer until fast pointer points the end of linked list (nullptr)
    // 3. return value of the node pointed by slow pointer
    int value_from_back(int index) const;
    void reverse();

public:
    node* head;
    // node* tail;
// private:
    // int m_size;
};

#endif
