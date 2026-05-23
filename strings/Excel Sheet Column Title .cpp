#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::string convertToTitle(int columnNumber) {
        char str = ' ';
        std::string result = "";

        for (int i = columnNumber; i > 0;)
        {
            i--;
            str = ('A' + i % 26);
            result = str + result;
            i /= 26;
        }
        return result;
    }
};

int main() {
    Solution sol;
    
    // Tests
    std::cout << sol.convertToTitle(1) << std::endl; // "A"
    std::cout << sol.convertToTitle(28) << std::endl; // "AB"
    std::cout << sol.convertToTitle(701) << std::endl; // "ZY"
    
    return 0;
}
    