// P026 Binary Tree Right Side View
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

vector<int> solve(TreeNode* root) {
    if (root == nullptr) {
        return {};
    }

    vector<int> ans;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();

            if (i == levelSize - 1) {
                ans.push_back(node->val);
            }
            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
    }

    return ans;
}

int main() {
    TreeNode* root = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(5)), new TreeNode(3, nullptr, new TreeNode(4)));
    vector<int> ans = solve(root);
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}

