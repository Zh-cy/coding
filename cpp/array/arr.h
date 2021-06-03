#ifndef __ARR__
#define __ARR__

#include <iostream>
#include <memory>

class myarray
{
public:
    myarray(int capa);
    myarray(const myarray &arr)=delete;
    ~myarray();

    int size() const; 
    int capacity() const;
    bool is_empty() const;
    int at(int index) const;
    int top() const;
    void push(int item);
    void insert(int index, int item);
    void prepend(int item);
    void pop();
    void del(int index);
    void rem(int item);
    int find(int item) const;
    void Info() const;

private:
    void resize();
    void Increase();
    void Decrease();
    int DetermCapacity(int capa);
    int m_size;
    int m_capacity;
    std::unique_ptr<int[]> m_arr;
};

#endif
