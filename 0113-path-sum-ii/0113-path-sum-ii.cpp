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
    void findAllPaths(TreeNode* root, int sum, vector<int>& current, vector<vector<int>>& allPaths) {
        if(root == nullptr) return;
        current.push_back(root->val);
        if(root->val == sum && root->left == nullptr && root->right == nullptr) {
            allPaths.push_back(current);
        }
        else {
            findAllPaths(root->left, sum - root->val, current, allPaths);
            findAllPaths(root->right, sum - root->val, current, allPaths);
        }
        current.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> allPaths;
        vector<int> current;
        findAllPaths(root, targetSum, current, allPaths);
        return allPaths;
    }
};