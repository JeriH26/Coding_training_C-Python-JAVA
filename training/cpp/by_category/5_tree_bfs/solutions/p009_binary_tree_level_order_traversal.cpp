// P009 Binary Tree Level Order Traversal
// Time: O(n), Space: O(n)

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value, TreeNode* leftNode = nullptr, TreeNode* rightNode = nullptr)
        : val(value), left(leftNode), right(rightNode) {}
};

vector<vector<int>> solve(TreeNode* root) {
    if (root == nullptr) {
        return {};
    }

    vector<vector<int>> ans;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> level;

        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();

            level.push_back(node->val);
            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }

        ans.push_back(level);
    }

    return ans;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20, new TreeNode(15), new TreeNode(7));

    vector<vector<int>> ans = solve(root);
    for (const auto& level : ans) {
        cout << "[";
        for (int x : level) {
            cout << x << " ";
        }
        cout << "] ";
    }
    cout << endl;
    return 0;
}

