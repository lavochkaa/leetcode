#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::string start_string = strs[0];
        std::string result = "";

        for (int symbol_index = 0; symbol_index < start_string.size(); symbol_index++)
        {
            char symbol = start_string[symbol_index];
            for (int strs_index = 1; strs_index < strs.size(); strs_index++)
            {
                if (symbol == strs[strs_index][symbol_index])
                {
                    if (symbol_index >= strs[strs_index].size())
                    {
                        return result;
                    }
                    
                }
                else
                {
                    return result;
                }
            }
            result += symbol;
        }
        return result;
    }
};

int main() {
    Solution sol;

    std::vector<std::string> test1 = {"flower","flow","flight"};
    std::vector<std::string> test2 = {"dog","racecar","car"};

    std::cout << sol.longestCommonPrefix(test1) << std::endl; // "fl"
    std::cout << sol.longestCommonPrefix(test2) << std::endl; // ""

    return 0;
}