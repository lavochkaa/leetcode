#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
    char findTheDifference(std::string s, std::string t) {
        std::unordered_map<char, int> map;

        for (char ind : s) map[ind]++;

        for (char ind : t)
        {
            if (map.count(ind) && map[ind] > 0) map[ind]--;
            else return ind;
        }
        
        return ' ';
    }
};

int main() {
    Solution sol;

    std::cout << sol.findTheDifference("abcd", "abcde") << "\n"; // e
    std::cout << sol.findTheDifference("", "y")         << "\n"; // y
    std::cout << sol.findTheDifference("a", "aa")       << "\n"; // a
    std::cout << sol.findTheDifference("ae", "aea")     << "\n"; // a

    return 0;
}
