#include <iostream>
#include "graph.h"

using namespace std;

int main(void)
{
    graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.addEdge(3,0);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.addEdge(6,0);
        
    g.Info();
    g.isEdge(1,2);
    g.isEdge(2,4);
    
    int maxdis = 0;
    for (int i=0; i<7; i++)
    {
        int temp = g.bfs(i);
        if (temp>maxdis)
            maxdis = temp;
    }
    cout << "Max distance from vertex 0 is: " << maxdis << endl;

    return 0;
}
