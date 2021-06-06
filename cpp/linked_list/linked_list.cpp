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
    tailnode->setNext(nullptr);
    if (head==nullptr)
    {
        head = tailnode;
        return;
    }
    node *cur = head;
    while(cur->getNext())
    {
        cur = cur->getNext();
    }
    cur->setNext(tailnode);    
}

int mylist::front() const
{
    if (head==nullptr)
    {
        std::cout << "Linked list is empty." << std::endl;
        exit(1);
    }
    return head->getVal();
}

int mylist::back() const
{
    if (head==nullptr)
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
    if (head==nullptr)
    {
        std::cout << "Linked list is empty." << std::endl;
        exit(1);
    }

    node* cur = head;
    head = cur->getNext();
    delete cur;
}

void mylist::pop_back()
{
    if (head==nullptr)
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
    
    if (prev==nullptr)
    {
        head = nullptr;
        delete cur;
        return;
    }
    prev->setNext(nullptr);
    delete cur;    
}

bool mylist::find(int key) const
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

void mylist::del(int index)
{
    if (head==nullptr)
    {
        std::cout << "Linked list is empty." << std::endl;
        exit(1);
    }
    node *prev = nullptr;
    node *cur = head;
    for(int i = 0; i < index; i++)
    {
        if (cur==nullptr)
        {
            std::cout << "Index out of bounds." << std::endl;
            exit(1);
        }
        prev = cur;
        cur = cur->getNext();
    }

    if(cur==nullptr)
    {
        std::cout << "Index out of bounds." << std::endl;
        exit(1);
    }
    prev->setNext(cur->getNext());
    delete cur;
}

void mylist::insert_before(int index, int key)
{
    if (head==nullptr)
    {
        std::cout << "Linked list is empty." << std::endl;
        exit(1);
    }
    node* prev = nullptr;
    node* cur = head;
    for (int i = 0; i < index; i++)
    {
        if (cur==nullptr)
        {
            std::cout << "Index out of bounds." << std::endl;
            exit(1);
        }
        prev = cur;
        cur = cur->getNext();
    }
    
    if (cur==nullptr)
    {
        std::cout << "Index out of bounds." << std::endl;
        exit(1);
    }
    
    node* newnode = new node(key);
    newnode->setNext(cur);
    prev->setNext(newnode);
}

void mylist::insert_after(int index, int key)
{
    if (head==nullptr)
    {
        std::cout << "Linked list is empty." << std::endl;
        exit(1);
    }
    node* cur = head;
    for (int i=0; i < index; i++)
    {
        if (cur==nullptr)
        {
            std::cout << "Index out of bounds." << std::endl;
            exit(1);
        }
        cur = cur->getNext();
    }
    if (cur==nullptr)
    {
        std::cout << "Index out of bounds." << std::endl;
        exit(1);
    }

    node* newnode = new node(key);
    newnode->setNext(cur->getNext());
    cur->setNext(newnode);
}

int mylist::size() const
{
    int count = 0;
    node* cur = head;
    while (cur!=nullptr)
    {
        ++count;
        cur = cur->getNext();
    }
    return count;
}

void mylist::Info() const
{ 
    if (head==nullptr)
    {
        std::cout << "  Linked list is empty." << std::endl;
        return;
    }
    
    node *cur = head;
    std::cout << "Linked list size: " << this->size() << std::endl;
    std::cout << "Linked list elements: " << std::endl;
    while (cur!=nullptr)
    {
        std::cout << "  " << cur->getVal() << std::endl;
        cur = cur->getNext();
    }
}

int mylist::value_from_back(int index) const
{
    if (index < 1 || head==nullptr)
    {
        std::cout << "Index out of bounds." << std::endl;
        exit(1);
    }

    node* fast = head;
    node* slow = head;

    for (int i=0; i<index; i++)
    {
        if (fast==nullptr)
        {
            std::cout << "Index out of bounds." << std::endl;
            exit(1);
        }
        fast = fast->getNext();
    }
    while (fast!=nullptr)
    {
        slow = slow->getNext();
        fast = fast->getNext();
    }
    return slow->getVal();
}

void mylist::reverse()
{
    if (head==nullptr)
    {
        std::cout << "Linked list is empty." << std::endl;
        exit(1);
    }
    node* prev = nullptr;
    node* cur = head;
    
    while (cur!=nullptr)
    {
        node* ne = cur->getNext();
        cur->setNext(prev);
        prev = cur;
        cur = ne;
    }

    head = prev;
}
