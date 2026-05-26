#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class NumArray {
    private:
    std::vector<int> prefix;

    public:
    NumArray(std::vector<int>& nums)
    {
        prefix.resize(nums.size() + 1);

        for (int i = 0; i < (int)nums.size(); i++)
        {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }

    int sumRange(int left, int right)
    {
        return prefix[right + 1] - prefix[left];   
    }
};

int main() {
    // LeetCode example
    std::vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray obj(nums);

    std::cout << obj.sumRange(0, 2) << "\n";  // 1   (-2+0+3)
    std::cout << obj.sumRange(2, 5) << "\n";  // -1  (3-5+2-1)
    std::cout << obj.sumRange(0, 5) << "\n";  // -3  (всё)

    // edge cases
    std::cout << obj.sumRange(0, 0) << "\n";  // -2  (один элемент)
    std::cout << obj.sumRange(5, 5) << "\n";  // -1  (последний)

    return 0;
}
