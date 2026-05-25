// P027 Minimum Depth of Binary Tree
// Time: O(n), Space: O(n)

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value, TreeNode* leftNode = nullptr, TreeNode* rightNode = nullptr)
        : val(value), left(leftNode), right(rightNode) {}
};

int solve(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    queue<pair<TreeNode*, int>> q;
    q.push({root, 1});

    while (!q.empty()) {
        auto [node, depth] = q.front();
        q.pop();

        if (node->left == nullptr && node->right == nullptr) {
            return depth;
        }
        if (node->left != nullptr) {
            q.push({node->left, depth + 1});
        }
        if (node->right != nullptr) {
            q.push({node->right, depth + 1});
        }
    }

    return 0;
}

int main() {
    TreeNode* root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    cout << solve(root) << endl;
    return 0;
}
