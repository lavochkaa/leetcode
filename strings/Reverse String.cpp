#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--)
        {
            char temp = s[i];
            
            s[i] = s[j];
            s[j] = temp;
        }
            
    }
};

int main() {
    Solution sol;
    std::vector<char> test1 = {'h', 'e', 'l', 'l', 'o'};
    std::vector<char> test2 = {'H', 'a', 'n', 's', 'o', 'l', 'm'};
    std::vector<char> test3 = {'R', 'e', 'v', 'e', 'r', 's', 'e', ' ', 'S', 't', 'r', 'i', 'n', 'g', 's'};
    // Tests
    sol.reverseString(test1);
    for (char c : test1) {
        std::cout << c;
    }
    std::cout << std::endl;
    sol.reverseString(test2);
    for (char c : test2) {
        std::cout << c;
    }
    std::cout << std::endl;
    sol.reverseString(test3);
    for (char c : test3) {
        std::cout << c;
    }
    std::cout << std::endl;
    
    return 0;
}