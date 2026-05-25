#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int result;
        int summ = 0;


        for (int num : nums) summ += num;

        result = ((nums.size() * (nums.size() + 1)) / 2) - summ;

        return result;
    }
};

int main() {
    Solution sol;
    std::vector<int> test1 = {3, 0, 1};
    std::vector<int> test2 = {0, 1};
    std::vector<int> test3 = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    // Tests
    std::cout << sol.missingNumber(test1) << std::endl; // 2
    std::cout << sol.missingNumber(test2) << std::endl; // 2
    std::cout << sol.missingNumber(test3) << std::endl; // 8
    
    return 0;
}