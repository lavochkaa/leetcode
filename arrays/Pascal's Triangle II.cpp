#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        std::vector<std::vector<int>> result;
        std::vector<int> row(1);

        for (int i = 0; i <= rowIndex; i ++)
        {
            std::vector<int> row(i + 1, 1);
            if (i > 1)
            {
                for (int j = 1; j < i; j++)
                {
                    row[j] = result[i - 1][j - 1] + result[i - 1][j];
                }
            }
            result.push_back(row);
        }
        return result[rowIndex];
    }  
};

int main() {
    Solution sol;
    
    auto result1 = sol.getRow(3);
    for (int x : result1) std::cout << x << " ";
    std::cout << std::endl; // [1,3,3,1]

    auto result2 = sol.getRow(0);
    for (int x : result2) std::cout << x << " ";
    std::cout << std::endl; // [1]

    auto result3 = sol.getRow(1);
    for (int x : result3) std::cout << x << " ";
    std::cout << std::endl; // [1,1]
    
    return 0;
}
    