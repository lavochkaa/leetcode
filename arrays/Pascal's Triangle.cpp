#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> result;

        for (int i = 0; i < numRows; i++)
        {
            std::vector<int> row(i + 1, 1);

            if (i > 1)
            {
                for (int j = 1; j < i; j ++)
                {
                    row[j] = result[i - 1][j - 1] + result[i - 1][j];
                }
            }
            result.push_back(row);
        }
        return result;
    }
};

int main() {
    Solution sol;

    auto result = sol.generate(5);
    for (auto& row : result) {
        for (int x : row) std::cout << x << " ";
        std::cout << std::endl;
    }
    // [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
    auto result2 = sol.generate(1);
    for (auto& row : result2) {
        for (int x : row) std::cout << x << " ";
        std::cout << std::endl;
    }
    // [[1]]
    auto result3 = sol.generate(2);
    for (auto& row : result3) {
        for (int x : row) std::cout << x << " ";
        std::cout << std::endl;
    }
    // [[1],[1,1]]
    return 0;
}
    