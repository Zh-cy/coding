#ifndef __GRAPH__
#define __GRAPH__

#include <iostream>
#include <queue>
#include <list>
#include <stack>
#include <cstring>
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
    int bfsMaxDis(int v) const;
    bool cycle() const;
    void Info() const;
    //void dfsFindCircle(int v, int* color);
    // bool hasCircle = false;

private:
    int m_num;
    list<int> *m_vertex;
};

#endif
