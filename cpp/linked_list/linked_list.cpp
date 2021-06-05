#include "linked_list.h"

mylist::mylist()
{
    head = nullptr;
}

mylist::~mylist()
{
    node* cur = head;
    node* nex = nullptr;
    while(cur)
    {
        nex = cur->getNext();
        delete cur;
        cur = nex;
    }
}

void mylist::push_front(int key)
{
    node *cur = new node(key);

    cur->setNext(head);
    head = cur;
}

void mylist::push_back(int key)
{
    node *tailnode = new node(key);

    if (!head)
    {
        head = tailnode;
        return;
    }
    node *cur = head;
    while(cur->getNext())
    {
        cur = cur->getNext();
    }
    cur->setNext(tailNode);    
}

int mylist::front() const
{
    if (!head)
    {
        std::cout << "Linked list is empty." << std::endl;
        exit(1);
    }
    return head->getVal();
}

int mylist::back() const
{
    if (!head)
    {
        std::cout << "Linked list is empty." << std::endl;
        exit(1);
    }
    
    node* cur = head;
    while(cur->getNext())
    {
        cur = cur->getNext();
    }
    return cur->getVal();
}

void mylist::pop_front()
{
    if (!head)
    {
        std::cout << "Linked list is empty." << std::endl;
        exit(1);
    }

    node* cur = head;
    head = cur->getNext();
    delete cur;
}

void mylist::popback()
{
    if (!head)
    {
        std::cout << "Linked list is empty." << std::endl;
        exit(1);
    }
    
    node* prev = nullptr;
    node* cur = head;
    
    while(cur->getNext())
    {
        prev = cur;
        cur = cur->getNext();
    }    
    
    if (!prev)
    {
        head = nullptr;
        delete cur;
        return;
    }
    prev->setNext(nullptr);
    delete cur;    
}

bool mysql::find(int key) const
{
    if (!head)
        return false;
    if (head->getVal() == key)
        return true;
    node* cur = head;
    while(cur->getNext())
    {
        cur = cur->getNext();
        if (cur->getVal() == key)
            return true;
    }
    return false;
}

void mysql::del(int index)
{
   if (!head)
   {
        std::cout << "Linked list is empty." << std::endl;
        exit(1);
        for(int i = 0; i <= index; i++)
   }

}
