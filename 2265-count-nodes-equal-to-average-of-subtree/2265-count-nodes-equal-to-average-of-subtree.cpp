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
    int ans = 0;
    pair<int, int> solve(TreeNode* root) {
        if(!root) return {0, 0};
        auto [leftSum, leftCount] = solve(root->left);
        auto [rightSum, rightCount] = solve(root->right);
        int sum = root->val + leftSum + rightSum;
        int count = 1 + leftCount + rightCount;
        if(root->val == floor(sum/count)) ans += 1;
        return {sum, count};
    }
    int averageOfSubtree(TreeNode* root) {
        auto [sum, count] = solve(root);
        return ans;
    }
};