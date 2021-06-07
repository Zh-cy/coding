#include "queue.h"

void myqueue::enqueue(int key)
{
    if (full())
    {
        std::cout << "Queue is full." << std::endl;
        exit(1);
    }
    m_queue[m_write] = key;
    m_write = (m_write + 1) % m_size;
}

int myqueue::dequeue()
{
    if (empty())
    {
        std::cout << "Queue is empty" << std::endl;
        exit(1);
    }
    int item = m_queue[m_read];
    m_read = (m_read + 1) % m_size;
    std::cout << item << " is removed from queue." << std::endl;
    return item;
}

bool myqueue::empty() const
{
    return m_write == m_read;
}

bool myqueue::full() const
{
    return (m_write+1) % m_size == m_read;
}

int myqueue::size() const
{
    int si = (m_write + m_size - m_read) % m_size;
    return si;
}

void myqueue::Info() const
{
    std::cout << "Size of queue is: " << size() << std::endl;
    std::cout << "Read pointer  is: " << m_read << std::endl;
    std::cout << "Write pointer is: " << m_write<< std::endl;
}
