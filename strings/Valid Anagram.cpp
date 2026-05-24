#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        std::unordered_map<char, int> map;
        if (s.size() != t.size()) return false;

        for (auto nums : s) map[nums]++;

        for (auto nums : t)
        {
            if (!map[nums]) return false;
            map[nums]--;
        }

        return true;
    }
};

int main() {
    Solution sol;
    
    // Tests
    std::cout << sol.isAnagram("anagram", "nagaram") << std::endl; // true
    std::cout << sol.isAnagram("rat" , "car") << std::endl; // false
    std::cout << sol.isAnagram("listen", "silent") << std::endl; // true
    std::cout << sol.isAnagram("ab", "a") << std::endl; //false
    return 0;
}