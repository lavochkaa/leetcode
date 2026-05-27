#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
    int firstUniqChar(std::string s) {
        std::unordered_map<char, int> map;

        for (char ind : s) map[ind]++;

        for (int i = 0; i < s.size(); i++)
        {
            if (map[s[i]] == 1) return i;
        }

        return -1;
    }
};

int main() {
    Solution sol;

    std::cout << sol.firstUniqChar("leetcode")    << "\n"; // 0
    std::cout << sol.firstUniqChar("loveleetcode") << "\n"; // 2
    std::cout << sol.firstUniqChar("aabb")        << "\n"; // -1
    std::cout << sol.firstUniqChar("z")           << "\n"; // 0
    std::cout << sol.firstUniqChar("aab")         << "\n"; // 2

    return 0;
}
