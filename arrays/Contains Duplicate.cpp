#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> set;
        
        for (int number : nums)
        {
            if (set.count(number)) return true;
            else set.insert(number);
        }
        return false;
    }
};

int main() {
    Solution sol;
    std::vector<int> test1 = {1, 2, 3, 1};
    std::vector<int> test2 = {1, 2, 3, 4};
    std::vector<int> test3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    // Tests
    std::cout << sol.containsDuplicate(test1) << std::endl; // 1
    std::cout << sol.containsDuplicate(test2) << std::endl; // 0
    std::cout << sol.containsDuplicate(test3) << std::endl; // 1
    
    return 0;
}
    