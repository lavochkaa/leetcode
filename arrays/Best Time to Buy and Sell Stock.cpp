#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int min_number = prices[0];
        int max_profit = 0;
        
        for (int i = 1; i < prices.size(); i++)
        {
            if (min_number > prices[i]) min_number = prices[i];
            if ((prices[i] - min_number) > max_profit) max_profit = (prices[i] - min_number);
        }

        return std::max(0, max_profit);
    }
};

int main() {
    Solution sol;
    std::vector<int> test1 = {7,1,5,3,6,4};
    std::vector<int> test2 = {7,6,4,3,1};
    std::vector<int> test3 = {1,2,3,4,5};
    // Tests
    std::cout << sol.maxProfit(test1) << std::endl; // 5
    std::cout << sol.maxProfit(test2) << std::endl; // 0
    std::cout << sol.maxProfit(test3) << std::endl; // 4

    return 0;
}
    