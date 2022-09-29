#include "heap.hpp"

int main() {
    std::vector<int> v {9,8,7,6,5,4,3,2,1};

    // 4-Fork-Min-Heap
    heap<int,std::vector<int>,4,std::greater<int>> hp(v.begin(),v.end());
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
