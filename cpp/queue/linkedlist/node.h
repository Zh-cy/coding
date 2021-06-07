#ifndef __NODE__
#define __NODE__

#include <iostream>

class node
{
public:
    node(int key) : val(key), next(nullptr){}
    node(const node &)=delete;
    node& operator=(const node &)=default;
    ~node()=default;
    node* getNext() const
    {
        return this->next;
    }
    int getVal() const
    {
        return this->val;
    }
    void setNext(node* n)
    {
        this->next = n;
    }
    void setVal(int key)
    {
        this->val = key;
    }

private:
    int val;
    node* next;
};

#endif
