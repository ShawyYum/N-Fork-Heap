#ifndef HEAP_H
#define HEAP_H

#include <deque>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

template <typename T,
    typename sequence = std::vector<T>,
    const unsigned int n = 2,
    typename compare = std::less<T>>   
class heap {
protected:
    sequence elem;
    compare cmp;

    void up(unsigned int x);
    void down(unsigned int x);

public:
    heap();
    heap(const std::vector<T> &x);
    heap(const std::deque<T> &x);
    heap(const T x[]);
    template<typename iter> 
    heap(iter begin,const iter end);
    ~heap();

    void push(const T &x);
    void pop();
    const T & top() const;
    const unsigned int size() const;
    const bool empty() const;
};

#endif
