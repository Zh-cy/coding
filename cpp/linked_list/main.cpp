#include <iostream>
#include "linked_list.h"

using namespace std;

int main(void)
{
    mylist l;
    l.push_back(1);
    l.push_front(2);
    cout << l.find(1) << endl;
    l.Info();
    
    cout << "--------------" << endl;
    for (int i = 0; i < 5; i++)
    {
        l.insert_before(1, i);
    }

    l.Info();

    cout << "--------------" << endl;
    l.insert_after(5, 123);
    //l.insert_after(23, 23);
    l.insert_after(0, 12345);

    l.Info();

    cout << "--------------" << endl;
    
    l.pop_front();
    l.pop_back();

    l.Info();
    
    cout << "--------------" << endl;

    //l.del(7);
    l.del(6);
    
    l.Info();
    
    cout << "--------------" << endl;
    
    cout << "Front element is: " << l.front() << endl;
    cout << "Back element is: " << l.back() << endl;
    
    cout << "--------------" << endl;
    
    cout << "The second element from back is: " << l.value_from_back(2) << endl;
    cout << "The 5th element from back is: " << l.value_from_back(5) << endl;
    
    cout << "--------------" << endl;
    
    l.reverse();

    l.Info();
    
    cout << "--------------" << endl;
    l.pop_back();
    l.pop_back();
    l.pop_back();
    
    l.Info();
    cout << "Linked list is reversed now." << endl;
    l.reverse();
    l.Info();

    cout << "--------------" << endl;
    l.pop_front();
    l.pop_front();
    l.Info();
    cout << "Linked list is reversed now." << endl;
    l.reverse();
    l.Info();

    return 0;

}
