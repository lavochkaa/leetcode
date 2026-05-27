#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        if (s.empty()) return 1;

        int i = 0, j = 0;
        for (; j < t.size();)
        {
            if (i == s.size()) return 1;
            if (s[i] == t[j]) i++, j++;
            else j++;
            
        }
        return i == (int)s.size();
    }
};

int main() {
    Solution sol;

    std::cout << sol.isSubsequence("ace", "abcde")  << "\n"; // 1
    std::cout << sol.isSubsequence("aec", "abcde")  << "\n"; // 0
    std::cout << sol.isSubsequence("", "ahbgdc")    << "\n"; // 1
    std::cout << sol.isSubsequence("b", "abc")      << "\n"; // 1
    std::cout << sol.isSubsequence("axc", "ahbgdc") << "\n"; // 0

    return 0;
}
