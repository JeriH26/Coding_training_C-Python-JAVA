// P027 Minimum Depth of Binary Tree Practice - BFS
#include <cassert>
#include <queue>
#include <stdexcept>
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
    // TODO: BFS with depth; return when the first leaf is removed from the queue.
    if (root == nullptr){
        return 0;
    }

    queue<pair<TreeNode*, int>> q;
    q.push({root, 1});

    while (!q.empty()){
        auto [node, depth] = q.front();
        q.pop();

        if (node->left == nullptr && node->right == nullptr){
            return depth;
        }
        if (node->left != nullptr){
            q.push({node->left, depth + 1});
        }
        if (node->right != nullptr){
            q.push({node->right, depth + 1});
        }
    }

    return 0;
}

int main() {
    TreeNode n15(15), n7(7), n9(9), n20(20, &n15, &n7), root(3, &n9, &n20);
    assert(solve(&root) == 2);
    assert(solve(nullptr) == 0);
}
