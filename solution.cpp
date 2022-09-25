#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>

template <typename T,const unsigned int n = 2,
    typename compare = std::less<T>>
class heap {
protected:
    std::vector<T> elem;
    compare cmp;

    inline void up(unsigned int x) {
        while(x) {
            unsigned int fa = (x - 1) / n;
            if(cmp(elem[x],elem[fa]) == 0) {
                std::swap(elem[x],elem[fa]);
                x = fa;
            }
            else break;
        }
    }

    inline void down(unsigned int x) {
        while(x * n + 1 < elem.size()) {
            unsigned int so = x * n + 1;
            T tmp = elem[x * n + 1];
            for(unsigned int i = 2;i <= n && x * n + i < elem.size();i++) {
                if(!cmp(elem[x * n + i],tmp)) {
                    tmp = elem[x * n + i];
                    so = x * n + i;
                }
            }
            if(cmp(elem[x],elem[so]) == 1) {
                std::swap(elem[x],elem[so]);
                x = so;
            }
            else break;
        }
    }

public:
    inline constexpr heap() {}

    inline heap(const std::vector<T> &x) {
        for(const auto &it : x) {
            elem.emplace_back(it);
            up(elem.size() - 1);
        }
    }

    inline void push(const T &x) {
        elem.emplace_back(x);
        up(elem.size() - 1);
    }

    inline void pop() {
        std::swap(elem[0],elem[elem.size() - 1]);
        elem.pop_back();
        down(0);
    }

    inline constexpr T & top(){
        return elem[0];
    }

    inline constexpr unsigned int size() const {
        return elem.size();
    }

    inline constexpr bool empty() const {
        return elem.empty();
    }
};

int main() {
    std::vector<int> v {9,8,7,6,5,4,3,2,1};

    // 4-Fork-Min-Heap
    heap<int,4,std::greater<int>> hp(v);
    std::cout << "hp.size() = " << hp.size() << "\n";
    std::cout << "hp.top() = " << hp.top() << "\n";

    hp.pop();
    std::cout << "hp.size() = " << hp.size() << "\n";
    std::cout << "hp.top() = " << hp.top() << "\n";

    hp.push(1);
    std::cout << "hp.size() = " << hp.size() << "\n";
    std::cout << "hp.top() = " << hp.top() << "\n";

    std::cout << "hp.empty() = " << hp.empty() << "\n";
    
    return 0;
}
