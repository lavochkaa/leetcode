#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
    std::vector<std::string> summaryRanges(std::vector<int>& nums) {
        std::vector<std::string> result;
        
        if (nums.empty()) return result;

        int start = nums[0];

        for (int i = 0; i < nums.size() - 1; i++)
        {

            if (nums[i] + 1 != nums[i + 1])
            {
                if (start == nums[i]) result.push_back(std::to_string(start));
                else result.push_back(std::to_string(start) + "->" + std::to_string(nums[i]));

                start = nums[i + 1];
            }
        }
        if (start == nums.back()) result.push_back(std::to_string(start));
        else result.push_back(std::to_string(start) + "->" + std::to_string(nums.back()));

        return result;
    }
};

int main() {
    Solution sol;
    std::vector<int> test1 = {0, 1, 2, 4, 5, 7};
    std::vector<int> test2 = {0, 2, 3, 4, 6, 8, 9};
    std::vector<int> test3 = {1};
    // Tests
    std::vector<std::string> result1 = sol.summaryRanges(test1);
    std::vector<std::string> result2 = sol.summaryRanges(test2);
    std::vector<std::string> result3 = sol.summaryRanges(test3);

    std::cout << "Test 1: ";
    for (const std::string& range : result1) {
        std::cout << range << " ";
    }
    std::cout << std::endl;

    std::cout << "Test 2: ";
    for (const std::string& range : result2) {
        std::cout << range << " ";
    }
    std::cout << std::endl;

    std::cout << "Test 3: ";
    for (const std::string& range : result3) {
        std::cout << range << " ";
    }
    std::cout << std::endl;

    return 0;
}