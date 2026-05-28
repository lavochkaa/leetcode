#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> fizzBuzz(int n) {
        std::vector<std::string> result;

        for (int i = 1; i <= n; i++)
        {
            if (i % 15 == 0) result.push_back("FizzBuzz");
            else if (i % 3 == 0) result.push_back("Fizz");
            else if (i % 5 == 0) result.push_back("Buzz");
            else result.push_back(std::to_string(i));
        }
        return result;
    }
};

int main() {
    Solution sol;

    // n=15 → "1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"
    std::vector<std::string> r1 = sol.fizzBuzz(15);
    for (const std::string& s : r1) std::cout << s << " ";
    std::cout << std::endl;

    // n=1 → "1"
    std::vector<std::string> r2 = sol.fizzBuzz(1);
    for (const std::string& s : r2) std::cout << s << " ";
    std::cout << std::endl;

    // n=3 → "1","2","Fizz"
    std::vector<std::string> r3 = sol.fizzBuzz(3);
    for (const std::string& s : r3) std::cout << s << " ";
    std::cout << std::endl;

    return 0;
}
