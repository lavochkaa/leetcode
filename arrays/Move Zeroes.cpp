#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int shift = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0) 
            {
                nums[shift] = nums[i];
                shift++;
            }
        }

        for (int i = shift; i < nums.size(); i++) nums[i] = 0;
    }
};

int main() {
    Solution sol;
    std::vector<int> test1 = {0, 1, 0, 3, 12};
    std::vector<int> test2 = {0};
    std::vector<int> test3 = {1, 0, 1};
    // Tests
    sol.moveZeroes(test1);
    std::cout << "Test 1: ";
    for (int num : test1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    sol.moveZeroes(test2);
    std::cout << "Test 2: ";
    for (int num : test2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    sol.moveZeroes(test3);
    std::cout << "Test 3: ";
    for (int num : test3) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}