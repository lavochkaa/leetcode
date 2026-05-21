#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>


class Solution {
public:
    // Вставь сигнатуру с LeetCode
    int romanToInt(std::string s) {
        std::unordered_map<char, int> symbols = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
        int result = 0;

        for (int i = 0; i < s.size(); i++)
        {
            int val = symbols[s[i]];
            if (i + 1 >= s.size())
            {
                result += val;
                break;
            }
            int val_place_2 = symbols[s[i + 1]];

            if (val < val_place_2)
            {
                result += (val_place_2 - val);
                i++; 
            }
            else
            {
                result += val;
            }
        }
        return result;
    };
};

int main() {
    Solution sol;
    
    // Твои тесты
    std::cout << sol.romanToInt("III")     << std::endl; // 3
    std::cout << sol.romanToInt("LVIII")   << std::endl; // 58
    std::cout << sol.romanToInt("MCMXCIV") << std::endl; // 1994
    
    return 0;
}