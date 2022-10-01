#ifndef HEAP_H
#define HEAP_H

#include <deque>
#include <vector>
#include <algorithm>
#include <functional>

template <const unsigned int n,
    typename T,
    typename sequence = std::vector<T>,
    typename compare = std::less<T>>   
class Heap {
protected:
    sequence elem;
    compare cmp;
    
    void up(unsigned int x) {
        while(x) {
            unsigned int fa = (x - 1) / n;
                if(this->cmp(this->elem[x],this->elem[fa]) == 0) {
                    std::swap(this->elem[x],this->elem[fa]);
                    x = fa;
                }
                else break;
            }
    } 

    void down(unsigned int x) {
        while(x * n + 1 < this->elem.size()) {
            unsigned int so = x * n + 1;
            T tmp = this->elem[x * n + 1];
            for(unsigned int i = 2;i <= n && x * n + i < this->elem.size();i++) {
                if(!this->cmp(this->elem[x * n + i],tmp)) {
                    tmp = this->elem[x * n + i];
                    so = x * n + i;
                }
            }
            if(this->cmp(this->elem[x],this->elem[so]) == 1) {
                std::swap(this->elem[x],this->elem[so]);
                x = so;
            }
            else break;
        }
    }

public:
    Heap() {}

    Heap(const std::vector<T> &x) {
        for(const auto &it : x) {
            this->elem.emplace_back(it);
            this->up(this->elem.size() - 1);
        }
    }

    Heap(const std::deque<T> &x) {
        for(const auto &it : x) {
            this->elem.emplace_back(it);
            this->up(this->elem.size() - 1);
        }
    }

    Heap(const T x[]) {
        for(const auto &it : x) {
            this->elem.emplace_back(it);
            this->up(this->elem.size() - 1);
        }
    }

    template<typename iter> 
    Heap(iter begin,const iter end) {
        for(;begin < end;begin++) {
            this->elem.emplace_back(*begin);
            this->up(this->elem.size() - 1);
        }
    }

    ~Heap() {}

    void push(const T &x) {
        this->elem.emplace_back (x);
        this->up(this->elem.size() - 1);
    }

    void pop() {
        std::swap(this->elem[0],this->elem[this->size() - 1]);
        this->elem.pop_back();
        this->down(0);
    }

    const T & top() const {
        return this->elem[0];
    }

    const unsigned int size() const {
        return this->elem.size();
    }

    const bool empty() const {
        return this->elem.empty();
    }
};

#endif
