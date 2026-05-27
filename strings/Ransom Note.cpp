#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        std::unordered_map<char, int> map;

        for (char ind : magazine) map[ind]++;

        for (char ind : ransomNote)
        {
            if (!map.count(ind) || map[ind] <= 0 ) return 0;
            else map[ind]--;
        }
        
        return 1;
    }
};

int main() {
    Solution sol;

    std::cout << sol.canConstruct("a", "b")      << "\n"; // 0
    std::cout << sol.canConstruct("aa", "ab")    << "\n"; // 0
    std::cout << sol.canConstruct("aa", "aab")   << "\n"; // 1
    std::cout << sol.canConstruct("a", "aab")    << "\n"; // 1
    std::cout << sol.canConstruct("aab", "baa")  << "\n"; // 1

    return 0;
}
