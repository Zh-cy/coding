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

int graph::bfsMaxDis(int v) const
{
    int path[m_num];
    memset(path, -1, sizeof(path));
    path[v] = 0;
    
    queue<int> q;
    q.push(v);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (list<int>::iterator iter=m_vertex[node].begin(); iter!=m_vertex[node].end(); iter++)
        {
            if (path[*iter]==-1)
            {
                q.push(*iter);
                path[*iter]=path[node]+1;
            }
            else
                continue;
        }
    }
    
    int maxdis = 0;

    for (int i=0; i<m_num; i++)
    {
        if (path[i]>maxdis)
        {
            maxdis = path[i];
        }
    }
    return maxdis;
}

// this is for directed graph
/*

int father[m_num];

void graph::dfsFindCircle(int v, int* color)
{
    // 0-not visited node; 1-visiting node; 2-all child nodes of this node are visited
    color[v] = 1; 
    for (list<int>::iterator iter=m_vertex[v].begin(); iter!=m_vertex[v].end(); iter++)
    {
        // if this child node isn't visited
        // 1. record his father node (current node)
        // 2. work on this child node (dfs-depth first)
        if (color[*iter]==0)
        {
            father[*iter] = v;
            dfsFindCircle(*iter, color);
        }
        // 1. this child node is beeing visited
        // 2. this child is not father node of current node
        // that means we found the circle!
        else if (color[*iter]==1 && father[*iter]!=v)
        {
            hasCircle = true;
            break;
        }
    }
    // all child nodes are visited and no circle detected
    // that means there is no circle 
    color[v] = 2;
}
*/
