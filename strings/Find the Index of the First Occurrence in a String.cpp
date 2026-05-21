#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        char first_symbol = needle[0];

        for (int haystack_index = 0; haystack_index < haystack.size(); haystack_index++)
        {
            if (haystack[haystack_index] == first_symbol)
            {
                if (haystack.substr(haystack_index, needle.size()) == needle)
                {
                    return haystack_index;
                }
            }
        }
        return -1;
    }
    
};

int main() {
    Solution sol;
    // Твои тесты
    std::cout << sol.strStr("sadbutsad", "sad") << std::endl;
    std::cout << sol.strStr("leetcode", "leeto") << std::endl;
    std::cout << sol.strStr("hello", "ll") << std::endl;

    return 0;
}