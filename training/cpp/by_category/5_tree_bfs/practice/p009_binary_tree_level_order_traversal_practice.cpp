// P009 Binary Tree Level Order Traversal Practice - BFS
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

vector<vector<int>> solve(TreeNode* root) {
    // TODO: BFS one complete queue level at a time.
    if (root == nullptr){
        return {};
    }

    vector<vector<int>> ans;
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int levelsize = q.size();
        vector<int> level;

        for(int i = 0; i < levelsize; i++){
            TreeNode* node = q.front();
            q.pop();

            level.push_back(node->val);
            if(node->left != nullptr){
                q.push(node->left);
            }
            if(node->left != nullptr){
                q.push(node->right);
            }
        }

        ans.push_back(level);
    }

    return ans;
}

int main() {
    TreeNode n15(15), n7(7), n9(9), n20(20, &n15, &n7), root(3, &n9, &n20);
    assert(solve(&root) == vector<vector<int>>({{3}, {9, 20}, {15, 7}}));
    assert(solve(nullptr).empty());
}
