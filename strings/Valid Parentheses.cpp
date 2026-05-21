#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    bool isValid(std::string s) {
        std::unordered_map<char, char> brackets = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
        std::stack<char> stack;

        for (int i = 0; i < s.size(); i++)
        {
            if (brackets.count(s[i]))
            {
                stack.push(s[i]);
            }
            else
            {
                if (!stack.empty() && brackets[stack.top()] == s[i])
                {
                    stack.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return stack.empty();
    }
};

int main() {
    Solution sol;
    std::string test1 = "()";
    std::string test2 = "()[]{}";
    std::string test3 = "(]";
    std::string test4 = "([)]";
    std::string test5 = "{[]}";
    // Твои тесты
    std::cout << sol.isValid(test1) << std::endl; // true
    std::cout << sol.isValid(test2) << std::endl; // true
    std::cout << sol.isValid(test3) << std::endl; // false
    std::cout << sol.isValid(test4) << std::endl; // false
    std::cout << sol.isValid(test5) << std::endl; // true

    return 0;
}