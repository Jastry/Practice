#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    std::vector<int> GetLeastNumbers_Solution(std::vector<int> input, int k) {
        std::vector<int> res;
        if (input.empty() || k <= 0)
            return res;
        res.resize(k);
        std::priority_queue< int, std::vector<int> > pq;
        for (auto i = 0; i < input.size(); ++i) {
            pq.push(input[i]);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        int i = k;
        while (!pq.empty()) {
            res[--k] = pq.top();
            pq.pop();
        }
        return res;
    }
};

int main()
{
    std::vector<int> a = { 4, 5, 6, 7, 8, 9, 10 , 11,1, 2, 3,};
    Solution so;
    std::vector<int> res;
    res = so.GetLeastNumbers_Solution(a, 3);
    for (auto i = 0; i < res.size(); ++i) {
        std::cout << res[i] <<std::endl;
    }
    return 0;
}
