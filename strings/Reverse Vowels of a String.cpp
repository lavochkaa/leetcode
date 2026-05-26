#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

bool isVowel(char c)
{
    static const std::string vowels = "aeiouAEIOU";
    return vowels.find(c) != std::string::npos;
}

class Solution {
public:
    std::string reverseVowels(std::string s) {

        for (int i = 0, j = s.size() - 1; i < j;)
        {
            if (isVowel(s[i]) && isVowel(s[j])) 
            {
                char temp = s[i];

                s[i] = s[j];
                s[j] = temp;
                i++;
                j--;
            }
            else if (!isVowel(s[i])) i++;
            else if (!isVowel(s[j])) j--;
        
        }
        return s;
    }
};

int main() {
    Solution sol;
    
    // Tests
    std::cout << sol.reverseVowels("hello") << std::endl; // "holle"
    std::cout << sol.reverseVowels("leetcode") << std::endl; // "leotcede"
    std::cout << sol.reverseVowels("aeiou") << std::endl; // "uoiea"

    return 0;
}