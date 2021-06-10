#include <iostream>
#include "graph.h"

using namespace std;

int main(void)
{
    graph g(5);
    g.addEdge(1,2);
    g.addEdge(0,2);
    g.Info();
    g.isEdge(1,2);
    g.isEdge(0,3);
    return 0;
}
