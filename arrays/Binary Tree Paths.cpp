#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    std::vector<std::string> binaryTreePaths(TreeNode* root) {
        std::vector<std::string> result;

        std::function<void(TreeNode* node, std::string path)> dfs = [&](TreeNode* node, std::string path)
        {
            if (node == nullptr) return;

            if (path.empty()) path = std::to_string(node->val);
            else path = path + "->" + std::to_string(node->val);

            if (node->left == nullptr && node->right == nullptr) 
            {
                result.push_back(path);

                return;
            }

            dfs(node->left, path);
            dfs(node->right, path);

        };
        dfs(root, "");
        
        return result;
    }
};

bool check(std::vector<std::string> result, std::vector<std::string> expected) {
    std::sort(result.begin(), result.end());
    std::sort(expected.begin(), expected.end());
    return result == expected;
}

int main() {
    Solution sol;

    // Test 1: базовый пример из условия
    //     1
    //    / \
    //   2   3
    //    \
    //     5
    TreeNode* t1 = new TreeNode(1);
    t1->left = new TreeNode(2);
    t1->right = new TreeNode(3);
    t1->left->right = new TreeNode(5);
    std::cout << "Test 1: " << (check(sol.binaryTreePaths(t1), {"1->2->5", "1->3"}) ? "OK" : "FAIL") << "\n";

    // Test 2: один узел (он же лист)
    TreeNode* t2 = new TreeNode(1);
    std::cout << "Test 2: " << (check(sol.binaryTreePaths(t2), {"1"}) ? "OK" : "FAIL") << "\n";

    // Test 3: только левая ветка
    //   1
    //  /
    // 2
    // |
    // 3
    TreeNode* t3 = new TreeNode(1);
    t3->left = new TreeNode(2);
    t3->left->left = new TreeNode(3);
    std::cout << "Test 3: " << (check(sol.binaryTreePaths(t3), {"1->2->3"}) ? "OK" : "FAIL") << "\n";

    // Test 4: полное дерево глубиной 2
    //     1
    //    / \
    //   2   3
    //  / \
    // 4   5
    TreeNode* t4 = new TreeNode(1);
    t4->left = new TreeNode(2);
    t4->right = new TreeNode(3);
    t4->left->left = new TreeNode(4);
    t4->left->right = new TreeNode(5);
    std::cout << "Test 4: " << (check(sol.binaryTreePaths(t4), {"1->2->4", "1->2->5", "1->3"}) ? "OK" : "FAIL") << "\n";

    return 0;
}
