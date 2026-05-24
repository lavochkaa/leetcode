#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++)
        {
            if (map.count(nums[i])) 
            {
                map[nums[i]] = i;
                if (i - map[nums[i]] <= k) return true;
                
            }
            else 
            {
                map[nums[i]] = i;
            }
        }

        return false;
    }
};

int main() {
    Solution sol;
    std::vector<int> test1 = {1, 2, 3, 1};
    std::vector<int> test2 = {1, 0, 1, 1};
    std::vector<int> test3 = {1, 2, 3, 1, 2, 3};
    
    // Tests
    std::cout << sol.containsNearbyDuplicate(test1, 3) << std::endl; // 1
    std::cout << sol.containsNearbyDuplicate(test2, 1) << std::endl; // 1
    std::cout << sol.containsNearbyDuplicate(test3, 2) << std::endl; // 0
    
    return 0;
}
    