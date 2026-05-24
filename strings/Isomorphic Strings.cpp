#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        std::unordered_map<char, char> array;
        std::unordered_map<char, char> map;

        for (int i = 0; i < s.size(); i++)
        {
            if (array.count(s[i]))
            {
                if (array[s[i]] != t[i]) return false;
            }
            else
            {
                array[s[i]] = t[i];
            }

            if (map.count(t[i]))
            {
                if (map[t[i]] != s[i]) return false;
            }
            else
            {
                map[t[i]] = s[i];
            }
        }

        return true;
    }
};

int main() {
    Solution sol;
    
    // Tests
    std::cout << sol.isIsomorphic("egg", "add") << std::endl; // true
    std::cout << sol.isIsomorphic("foo", "bar") << std::endl; // false
    std::cout << sol.isIsomorphic("paper", "title") << std::endl; // true

    return 0;
}
    