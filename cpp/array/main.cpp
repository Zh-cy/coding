#include <iostream>
#include "arr.h"

using namespace std;

int main(void)
{
    myarray a1(7);
    a1.push(1);
    a1.push(2);
    a1.insert(1, 2);
    a1.insert(1, 3);
    a1.insert(1, 4);
    a1.push(16);
    a1.Info();
    for (int i=0; i < 6; i++)
        a1.insert(4, i);
    a1.Info();

    cout << "Size of array is: " << a1.size() << endl;
    cout << "Capacity of array is: " << a1.capacity() << endl;

    cout << "--------------" << endl;
    cout << "Remove all 2." << endl;
    a1.rem(2);
    a1.Info();

    cout << "-------------" << endl;
    a1.pop();
    cout << a1.top() << endl;
    a1.pop();
    cout <<  a1.top() << endl;
    a1.pop();
    a1.pop();
    a1.pop();
    a1.pop();
    a1.Info();

    cout << "Is there any 1 in this array? If yes, what is the index? Ans: " << a1.find(1) << endl;
    cout << "Is there any 2 in this array? If yes, what is the index? Ans: " << a1.find(2) << endl;
    cout << "-------------" << endl;

    cout << a1.at(1) << endl;

    return 0;
}
