#include <iostream>
#include <set>
#include <vector>

class Solution {
public:
    int thirdMax(std::vector<int>& nums) {
        std::set<int> set;

        for (int num : nums) set.insert(num);

        auto it = set.end();
        
        if (set.size() < 3) return *set.rbegin();

        std::advance(it, -3);
        return *it;

    }
};

int main() {
    Solution sol;

    // [3,2,1] → 1
    std::vector<int> t1 = {3, 2, 1};
    std::cout << sol.thirdMax(t1) << std::endl;

    // [1,2] → 2  (третьего нет → максимум)
    std::vector<int> t2 = {1, 2};
    std::cout << sol.thirdMax(t2) << std::endl;

    // [2,2,3,1] → 1  (дубликаты не считаются)
    std::vector<int> t3 = {2, 2, 3, 1};
    std::cout << sol.thirdMax(t3) << std::endl;

    // [1,2,2,5,3,5] → 1  (уникальные: 5,3,2,1 → третий = 2)
    std::vector<int> t4 = {1, 2, 2, 5, 3, 5};
    std::cout << sol.thirdMax(t4) << std::endl;

    // [1] → 1  (третьего нет → максимум)
    std::vector<int> t5 = {1};
    std::cout << sol.thirdMax(t5) << std::endl;

    return 0;
}
