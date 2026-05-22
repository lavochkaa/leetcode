#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        std::string result = "";
        int carry = 0;

        for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; i--, j--)
        {   
            int sum = carry;

            if (i >= 0) sum += a[i] - '0';
            if (j >= 0) sum += b[j] - '0';
            
            result = std::to_string(sum % 2) + result;
            carry = sum / 2;
            
        }
        if (carry == 1) result = "1" + result;
        return result;
    }
};

int main() {
    Solution sol;
    
    std::cout << sol.addBinary("11", "1") << std::endl; // "100"
    std::cout << sol.addBinary("1010", "1011") << std::endl; // "10101"
    std::cout << sol.addBinary("0", "0") << std::endl; // "0"
    
    return 0;
}
    