#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int result = 0;
        for (int num : nums)
        {
            result = result ^ num;
        }
        return result;
    }
};

int main() {
    Solution sol;
    std::vector<int> test1 = {2, 2, 1};
    std::vector<int> test2 = {4, 1, 2, 1, 2};
    std::vector<int> test3 = {1};
    // Tests
    std::cout << sol.singleNumber(test1) << std::endl; // 1
    std::cout << sol.singleNumber(test2) << std::endl; // 4
    std::cout << sol.singleNumber(test3) << std::endl; // 1
    
    return 0;
}
    