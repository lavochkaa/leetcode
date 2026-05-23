#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    int titleToNumber(std::string columnTitle) {
        int result = 0;

        for (char str : columnTitle)
        {
            result = result * 26 + (str - 'A' + 1);
        }
        return result;
    }
};

int main() {
    Solution sol;
    
    // Tests
    std::cout << sol.titleToNumber("A") << std::endl; // 1
    std::cout << sol.titleToNumber("AB") << std::endl; // 28
    std::cout << sol.titleToNumber("ZY") << std::endl; // 701
    
    return 0;
}
    