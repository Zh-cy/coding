#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include <iostream>

class node
{
public:
    node(int key) : val(key), next(nullptr)
    ~node();
    node(const node &) = delete;
    node &operator=(const node &) = default;
    int getVal() const
    {
        return this->val;    
    }
    void setVal(const int key)
    {
        this->val = key;
    }
    node* getNext() const
    {
        return this->next;
    }
    void setNext(const node *n)
    {
        this->next = n;
    }
private:
    int val;
    node* next;
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
    void del(int index);
    bool is_empty() const;
    void insert_before(struct node* n, int key);
    void insert_after(struct node* n, int key); 


public:
    node* head;
    // node* tail;
// private:
    // int m_size;
};

#endif
