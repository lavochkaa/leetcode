#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
   int majorityElement(std::vector<int>& nums) {
        std::unordered_map<int, int> map;

        for (int i : nums)
        {
            map[i]++;
        }

        for (auto& pair : map)
        {
            if (pair.second > nums.size() / 2) return pair.first;
        }
        return 0;
    }   
};

int main() {
    Solution sol;
    std::vector<int> test1 = {3, 2, 3};
    std::vector<int> test2 = {2, 2, 1, 1, 1, 2, 2};
    std::vector<int> test3 = {1, 2, 2, 1, 1, 1};
    // Tests
    std::cout << sol.majorityElement(test1) << std::endl; // 3
    std::cout << sol.majorityElement(test2) << std::endl; // 2
    std::cout << sol.majorityElement(test3) << std::endl; // 1
    
    return 0;
}