#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include <iostream>

struct node
{
    int val;
    struct node* next;
};

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
    void rem(int key);
    bool is_empty() const;
    void insert_before(struct node* n, int key);
    void insert_after(struct node* n, int key); 


public:
    struct node* head;
    // struct node* tail;
// private:
    // int m_size;
};

#endif
