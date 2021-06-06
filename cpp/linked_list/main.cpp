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
    cout << l.size() << endl;

    return 0;
}
