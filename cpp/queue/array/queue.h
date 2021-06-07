#ifndef __QUEUE__
#define __QUEUE__

#include <iostream>

class myqueue
{
public:
    myqueue() : m_read(0), m_write(0) {}
    myqueue(const myqueue &)=delete;
    myqueue& operator=(const myqueue &)=delete;
    ~myqueue()=default;

    void enqueue(int key);
    int dequeue();
    bool empty() const;
    bool full() const;
    int size() const;
    void Info() const;

private:
    enum {m_size=10};
    int m_read;
    int m_write;
    int m_queue[m_size];
};

#endif
