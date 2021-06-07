#include "queue.h"

myqueue::~myqueue()
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

void myqueue::enqueue(int key)
{
    node* newnode = new node(key);
    if (empty())
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->setNext(newnode);
    tail = newnode;
}

int myqueue::dequeue()
{
    if (empty())
    {
        std::cout << "Queue is empty." << std::endl;
        exit(1);
    }
    node* n = head;
    int value = n->getVal();
    head = head->getNext();
    delete n;
    std::cout << value << " is removed from the queue." << std::endl;
    return value;
}

bool myqueue::empty() const
{
    return head==nullptr && tail==nullptr;        
}

int myqueue::size() const
{
    int count = 0;
    node *cur = head;
    while (cur)
    {
        ++count;
        cur = cur->getNext();
    }
    std::cout << "Size of queue is: " << count << std::endl;
    return count;
}

void myqueue::Info() const
{
    if (size() == 0)
    {
        std::cout << "Queue is empty." << std::endl;
        return;
    }
    std::cout << "Value of head is: " << head->getVal() << std::endl;
    std::cout << "Value of tail is: " << tail->getVal() << std::endl;
}
