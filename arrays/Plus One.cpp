#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            digits[i]++;
            if (digits[i] < 10)
            {
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
    
};

int main() {
    Solution sol;
    std::vector<int> test1 = {1, 2, 3};
    std::vector<int> test2 = {4, 3, 2, 1};
    std::vector<int> test3 = {9};
    // Tests
    std::vector<int> result1 = sol.plusOne(test1);
    std::vector<int> result2 = sol.plusOne(test2);
    std::vector<int> result3 = sol.plusOne(test3);

    std::cout << "Test 1: ";
    for (int num : result1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << "Test 2: ";
    for (int num : result2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << "Test 3: ";
    for (int num : result3) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
    