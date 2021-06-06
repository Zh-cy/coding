#ifndef __LINKED_NODE__
#define __LINKED_NODE__

#include <iostream>

class node
{
public:
    node(int key) : val(key), next(nullptr){};
    ~node(){};
    node(const node &) = delete;
    node &operator=(const node &) = default;
    int getVal() const
    {
        return this->val;    
    }
    void setVal(int key)
    {
        this->val = key;
    }
    node* getNext() const
    {
        return this->next;
    }
    void setNext(node *n)
    {
        this->next = n;
    }
private:
    int val;
    node* next;
};

#endif
