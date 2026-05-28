#include <iostream>
#include <string>

class Solution {
public:
    std::string toHex(int num) {
        if (num == 0) return "0";

        std::string result;
        std::string hex = "0123456789abcdef";
        unsigned int u = (unsigned int)num;

        while(u != 0)
        {
            int digit = u & 0xF;
            result = hex[digit] + result;
            u >>= 4;
        }
        return result;
    }
};

int main() {
    Solution sol;

    // 26 → "1a"
    std::cout << sol.toHex(26) << std::endl;

    // 255 → "ff"
    std::cout << sol.toHex(255) << std::endl;

    // 0 → "0"
    std::cout << sol.toHex(0) << std::endl;

    // -1 → "ffffffff"  (все 32 бита единицы)
    std::cout << sol.toHex(-1) << std::endl;

    // 16 → "10"
    std::cout << sol.toHex(16) << std::endl;

    // INT_MIN = -2147483648 → "80000000"
    std::cout << sol.toHex(-2147483648) << std::endl;

    return 0;
}
