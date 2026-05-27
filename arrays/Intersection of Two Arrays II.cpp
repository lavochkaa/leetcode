#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_map<int, int> map;
        std::vector<int> result;

        for (int num : nums1) map[num]++;

        for (int num : nums2)
        {
            if (map.count(num) && map[num] > 0)
            {
                result.push_back(num);
                map[num]--;
            }
        }
        return result;
    }
};

void print(const std::vector<int>& v) {
    std::cout << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        if (i) std::cout << ", ";
        std::cout << v[i];
    }
    std::cout << "]\n";
}

int main() {
    Solution sol;

    // [2, 2]
    std::vector<int> a1 = {1, 2, 2, 1}, b1 = {2, 2};
    print(sol.intersect(a1, b1));

    // [9, 4] или [4, 9]
    std::vector<int> a2 = {4, 9, 5}, b2 = {9, 4, 9, 8, 4};
    print(sol.intersect(a2, b2));

    // [] — нет пересечений
    std::vector<int> a3 = {1, 2, 3}, b3 = {4, 5, 6};
    print(sol.intersect(a3, b3));

    // [1] — один общий, хотя в nums2 три единицы
    std::vector<int> a4 = {1}, b4 = {1, 1, 1};
    print(sol.intersect(a4, b4));

    return 0;
}