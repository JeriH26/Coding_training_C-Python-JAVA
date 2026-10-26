// P026 Binary Tree Right Side View Practice - BFS
#include <cassert>
#include <queue>
#include <stdexcept>
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
    // TODO: Run level-order BFS and save the last node from each level.
    if (root == nullptr){
        return {};
    }

    vector<int> ans;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()){
        int levelsize = q.size();
        for (int i = 0; i < levelsize; i++){
            TreeNode* node = q.front();
            q.pop();

            if (i == levelsize -1){
                ans.push_back(node->val);
            }
            if (node->left != nullptr){
                q.push(node->left);
            }
            if (node->right != nullptr){
                q.push(node->right);
            }
        }
    }

    return ans;
}

int main() {
    TreeNode n5(5), n4(4), n2(2, nullptr, &n5), n3(3, nullptr, &n4), root(1, &n2, &n3);
    assert(solve(&root) == vector<int>({1, 3, 4}));
    assert(solve(nullptr).empty());
}
