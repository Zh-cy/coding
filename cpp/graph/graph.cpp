#include "graph.h"

graph::graph(int num) : m_num(num)
{
    m_vertex = new list<int>[num];
}

void graph::addEdge(int v1, int v2)
{
    m_vertex[v1].push_back(v2);
    m_vertex[v2].push_back(v1);
}

void graph::Info() const
{
    cout << "-------Info--------" << endl;
    for(int i=0; i<m_num; i++)
    {
        cout << "vertex " << i << ": ";
        for(int j : m_vertex[i])
        {
            cout << i << "-" << j << " ";
        }
        cout << endl;
    }
    cout << "-------------------" << endl;
}

bool graph::isEdge(int v1, int v2) const
{
    cout << "-------Edge--------" << endl;
    list<int>::iterator iter = find(m_vertex[v1].begin(), m_vertex[v1].end(), v2);
    if (iter != m_vertex[v1].end())
    {
        cout << "Found edge: " << v1 << "-" << v2 << endl;
    cout << "-------------------" << endl;
        return true;
    }
    cout << "Didn't find edge: " << v1 << "-" << v2 << endl;
    cout << "-------------------" << endl;
    return false;
}
