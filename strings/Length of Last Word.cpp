#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int counter = 0;

        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] != ' ')
            {
                while (i >= 0 && s[i] != ' ')
                {
                    counter++;
                    i--;
                }
                return counter;
            }
        }
        return counter;
    }
};

int main() {
    Solution sol;
    
    // Tests
    std::cout << sol.lengthOfLastWord("Hello World") << std::endl;
    std::cout << sol.lengthOfLastWord("   fly me   to   the moon  ") << std::endl;
    std::cout << sol.lengthOfLastWord("luffy is still joyboy") << std::endl;

    return 0;
}
    