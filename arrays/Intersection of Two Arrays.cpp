#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_map<int, int> map;
        std::vector<int> result;

        for (int num : nums1) map[num]++;

        for (int num : nums2)
        {
            if (map.count(num)) 
            {
                result.push_back(num);
                map.erase(num);
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    std::vector<int> test1 = {4, 9, 5};
    std::vector<int> test2 = {9, 4, 9, 8, 4};
    std::vector<int> test3 = {1, 2, 3};
    std::vector<int> test4 = {4, 5, 6};
    // Tests
    auto result1 = sol.intersection(test1, test2);
    std::cout << "Test 1: ";
    for (int num : result1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    auto result2 = sol.intersection(test3, test4);
    std::cout << "Test 2: ";
    for (int num : result2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}