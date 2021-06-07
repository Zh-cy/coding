#include <iostream>
#include "queue.h"

using namespace std;

int main(void)
{

    cout << "----------------" << endl;

    myqueue q;    
    q.Info();
    q.enqueue(1);
    q.enqueue(6);

    cout << "----------------" << endl;
    
    q.Info();

    cout << "----------------" << endl;
    
    q.dequeue();
    q.Info();

    cout << "----------------" << endl;
    
    q.enqueue(1);
    q.enqueue(5);
    q.enqueue(5);
    q.enqueue(5);
    q.enqueue(5);
    q.enqueue(5);
    q.enqueue(5);
    q.enqueue(0);
    // q.enqueue(0); // full
    q.Info();

    cout << "----------------" << endl;
    
    q.dequeue();
    q.Info();
    q.dequeue();
    q.Info();

    cout << "----------------" << endl;

    return 0;
}
