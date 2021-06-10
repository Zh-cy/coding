#ifndef __GRAPH__
#define __GRAPH__

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class graph
{
public:
    graph(int num);
    graph(const graph &)=delete;
    graph& operator=(const graph &)=delete;
    ~graph()=default;

public:
    void addEdge(int v1, int v2);
    bool isEdge(int v1, int v2) const;
    void Info() const;

private:
    int m_num;
    list<int> *m_vertex;
};

#endif
