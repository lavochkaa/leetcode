#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

/*
class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= target)
            {
                return i;
            }
        }
        return nums.size();
    }
};
*/
class Solution
{
public:
    int searchInsert(std::vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        if (target > nums[right])
        {
            return right + 1;
        }
        while (left <= right)
        {
            int middle = (left + right) / 2;
            
            if (nums[middle] == target)
                return middle;
            if (nums[middle] < target)
                left = middle + 1;
            else
                right = middle - 1;
        }
        return left;
    }
};

int main()
{
    Solution sol;
    std::vector<int> nums1 = {1, 3, 5, 6};
    int target1 = 5;
    int target2 = 2;
    int target3 = 7;
    // Твои тесты
    std::cout << sol.searchInsert(nums1, target1) << std::endl;
    std::cout << sol.searchInsert(nums1, target2) << std::endl;
    std::cout << sol.searchInsert(nums1, target3) << std::endl;

    return 0;
}