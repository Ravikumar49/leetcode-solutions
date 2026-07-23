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
    int maxLevelSum(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr) return 1;
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        int total = INT_MIN;
        int rank = 1;
        while(!q.empty()) {
            int levelSize = q.size();
            int sum = 0;
            for(int i=0;i<levelSize;i++) {
                TreeNode* curr = q.front();
                q.pop();
                sum += curr->val;
                if(curr->left != nullptr) q.push(curr->left);
                if(curr->right != nullptr) q.push(curr->right);
            }
            if(total < sum) {
                ans = rank;
                total = sum;
            }
            rank++;
        }
        return ans;
    }
};