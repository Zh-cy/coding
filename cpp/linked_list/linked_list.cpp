#include "linked_list.h"

mylist::mylist()
{
    head = nullptr;
}

mylist::~mylist()
{
    struct node* cur = head;
    struct node* nex = nullptr;
    while(cur)
    {
        nex = cur->next;
        delete cur;
        cur = nex;
    }
}

void mylist::push_front(int key)
{

}
