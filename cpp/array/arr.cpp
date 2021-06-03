#include "arr.h"

using namespace std;

myarray::myarray(int capa) : m_size(0)
{
    if (capa < 1)
    {
        cout << "array capacity cannot be less than 1";
        exit(1);
    }
    
    m_capacity = DetermCapacity(capa);
    m_arr = unique_ptr<int[]>(new int[m_capacity]);
}

/*
myarray::myarray(const myarray &arr)
{
    
}
*/

myarray::~myarray() {}

int myarray::DetermCapacity(int capa)
{
    int capacity = 4;

    while(capacity < capa * 2)
    {
        capacity *= 2;
    }

    return capacity;
}

int myarray::size() const
{
    return m_size;
}

int myarray::capacity() const
{
    return m_capacity;
}

bool myarray::is_empty() const
{
    return (m_size == 0);
}

int myarray::at(int index) const
{
    if (index < 0 || index >= m_size)
    {
        cout << "Index out of bounds." << endl;
        exit(1);
    }
    return m_arr[index];
}

int myarray::top() const
{
    if (is_empty())
    {
        cout << "Array is empty." << endl;
        exit(1);
    }
    return m_arr[m_size-1];
}

void myarray::push(int item)
{
    m_size += 1;
    resize();

    m_arr[m_size-1] = item;
}

void myarray::insert(int index, int item)
{
    if (index < 0 || index > m_size)
    {
        cout << "Index out of bounds." << endl;
        exit(1);
    }

    if (index == m_size)
        push(item);
    m_size += 1;
    resize();

    for (int i=m_size-1; i>index; i--)
    {
        m_arr[i] = m_arr[i-1];
    }
    m_arr[index] = item;
}

void myarray::prepend(int item)
{
    insert(0, item);
}

void myarray::pop()
{
    if (is_empty())
    {
        cout << "Array has no element to pop." << endl;
        exit(1);
    }

    m_size -= 1;

    resize();
}

void myarray::del(int index)
{
    if (index < 0 || index >= m_size)
    {
        cout << "Index out of bounds." << endl;
        exit(1);
    }
    
    m_size -= 1;
    resize();

    for(int i=index; i < m_size; i++)
        m_arr[i] = m_arr[i+1];
}

void myarray::rem(int item)
{
    for (int i=0; i<m_size; i++)
    {
        if (m_arr[i] == item)
        {
            del(i);
            --i;
        }
    }
}

int myarray::find(int item) const
{
   int index = -1;
   for (int i=0; i<m_size; i++)
   {
        if(m_arr[i] == item)
        {
            index = i;
            break;
        }
   }
   return index;
}

void myarray::resize()
{
    if (m_size >= m_capacity)
    {
        Increase();
    }
    if (m_size < m_capacity / 4)
    {
        Decrease();
    }
}


void myarray::Increase()
{
    int oldcapa = m_capacity;
    int newcapa = DetermCapacity(oldcapa);

    if (oldcapa == newcapa)
        return;
    unique_ptr<int[]> new_arr(new int[newcapa]);
    for (int i=0; i<m_size-1; i++)
        new_arr[i] = m_arr[i];
    m_arr = move(new_arr);
    m_capacity = newcapa;
}

void myarray::Decrease()
{
    int oldcapa = m_capacity;
    int newcapa = oldcapa / 2;

    if (newcapa < 4)
        newcapa = 4;
    if (oldcapa == newcapa)
        return;
    unique_ptr<int[]> new_arr(new int[newcapa]);
    for (int i=0; i<m_size+1; i++)
        new_arr[i] = m_arr[i];
    m_arr = move(new_arr);
    m_capacity = newcapa;
}

void myarray::Info() const
{
    cout << "Array size: " << m_size << endl;
    cout << "Array capacity: " << m_capacity << endl;
    cout << "Array elements:" << endl;
    for (int i=0; i < m_size; i++)
    {
        cout << m_arr[i] << endl;
    }
}
