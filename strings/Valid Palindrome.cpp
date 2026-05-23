#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>
#include <vector>

class Solution {
public:
    bool isPalindrome(std::string s) {
        std::string sorted = "";

        for (char latter : s)
        {
            if (isalnum(latter)) sorted += tolower(latter);
        }

        for (int i = 0, j = sorted.size() - 1; i < j; i++, j--)
        {
            if (sorted[i] != sorted[j]) return 0;
        }

        return 1;
    }
};

int main() {
    Solution sol;
    
    // Tests
    std::cout << sol.isPalindrome("A man, a plan, a canal: Panama") << std::endl; // true
    std::cout << sol.isPalindrome("race a car") << std::endl; // false
    std::cout << sol.isPalindrome(" ") << std::endl; // true
    
    return 0;
}
    