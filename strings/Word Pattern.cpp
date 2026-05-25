#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <vector>

class Solution {
public:
    bool wordPattern(std::string pattern, std::string s) {
        std::istringstream iss(s);
        std::string word;
        std::vector<std::string> words;
        std::unordered_map<char, std::string> map_pattern;
        std::unordered_map<std::string, char> map_s;

        while (iss >> word) words.push_back(word);

        if (words.size() != pattern.size()) return 0;

        for (int i = 0; i < pattern.size(); i++)
        {
            char c = pattern[i];
            std::string w = words[i];

            if (map_pattern.count(c))
            {
                if (map_pattern[c] != w) return 0;
            }
            else
            {
                map_pattern[c] = w;
            }


            if (map_s.count(w))
            {
                if (map_s[w] != c) return 0;
            }
            else
            {
                map_s[w] = c;
            }
        }
        return 1;
        
    }
};

int main() {
    Solution sol;
    
    // Tests
    std::cout << sol.wordPattern("abba", "dog cat cat dog") << std::endl; // true
    std::cout << sol.wordPattern("abba", "dog cat cat fish") << std::endl; // false
    std::cout << sol.wordPattern("aaaa", "dog cat cat dog") << std::endl; // false
    std::cout << sol.wordPattern("abba", "dog dog dog dog") << std::endl; // false
    
    return 0;
}