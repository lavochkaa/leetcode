#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int k = m + n - 1;

        for (int i = m - 1, j = n - 1; i >= 0 || j >= 0;)
        {
            int value = 0;
            if (i < 0) 
            {
                nums1[k--] = nums2[j--];
                continue;
            }
            if (j < 0) 
            {
                nums1[k--] = nums1[i--];
                continue;
            }
            
            if (nums1[i] > nums2[j]) 
            {
                value = nums1[i];
                i--;
            }
            else if (nums1[i] < nums2[j])
            {
                value = nums2[j];
                j--;
            }
            else {
                nums1[k--] = nums1[i--];
                continue;
            }

            nums1[k] = value;
            k--;
        }
        
    }
    
};
int main() {
    Solution sol;
    
    // тест 1: обычный случай
    std::vector<int> a1 = {1, 2, 3, 0, 0, 0};
    std::vector<int> b1 = {2, 5, 6};
    sol.merge(a1, 3, b1, 3);
    for (int x : a1) std::cout << x << " ";
    std::cout << std::endl; // 1 2 2 3 5 6

    // тест 2: nums2 пустой
    std::vector<int> a2 = {1};
    std::vector<int> b2 = {};
    sol.merge(a2, 1, b2, 0);
    for (int x : a2) std::cout << x << " ";
    std::cout << std::endl; // 1

    // тест 3: nums1 пустой
    std::vector<int> a3 = {0};
    std::vector<int> b3 = {1};
    sol.merge(a3, 0, b3, 1);
    for (int x : a3) std::cout << x << " ";
    std::cout << std::endl; // 1
}