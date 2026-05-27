#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
    int longestPalindrome(std::string s) {
        std::unordered_map<char, int> map;
        int result = 0;
        bool has = false;

        for (char ind : s) map[ind]++;

        for (auto& pair : map)
        {
            result += pair.second / 2 * 2;
            if (pair.second % 2 != 0) has = true;
        }

        if (has) result++;

        return result;
    }
};

int main() {
    Solution sol;

    std::cout << sol.longestPalindrome("abccccdd") << "\n"; // 7
    std::cout << sol.longestPalindrome("a")        << "\n"; // 1
    std::cout << sol.longestPalindrome("bb")       << "\n"; // 2
    std::cout << sol.longestPalindrome("ccc")      << "\n"; // 3
    std::cout << sol.longestPalindrome("aabb")     << "\n"; // 4

    return 0;
}
