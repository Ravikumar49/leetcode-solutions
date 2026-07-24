/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* current, int pathSum) {
        if(!current) return 0;
        pathSum = pathSum * 10 + current->val;
        if(current->left == nullptr && current->right == nullptr) return pathSum;
        return dfs(current->left, pathSum) + dfs(current->right, pathSum);
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};