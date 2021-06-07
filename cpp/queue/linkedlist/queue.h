#ifndef __QUEUE__
#define __QUEUE__

#include <iostream>
#include "node.h"

class myqueue
{
public:
    myqueue() : head(nullptr), tail(nullptr) {}
    myqueue(const myqueue &)=delete;
    myqueue& operator=(const myqueue &)=default;
    ~myqueue();
    
    void enqueue(int key);
    int dequeue();
    bool empty() const;
    // bool full() const;
    int size() const;
    void Info() const;    

private:
    node* head;
    node* tail;
};

#endif
