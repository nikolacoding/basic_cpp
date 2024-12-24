#include <iostream>
#include <queue>
using std::priority_queue;
using std::vector;

int main(void){
    priority_queue<int, vector<int>, std::greater<int>> pq;

    vector<int> nums = {10, 60, 35, 90, 45, 25, -25, 95, 100, 45};

    for (int i : nums)
        pq.push(i);
    
    while (!pq.empty()){
        std::cout << pq.top() << std::endl;
        pq.pop();
    }
}