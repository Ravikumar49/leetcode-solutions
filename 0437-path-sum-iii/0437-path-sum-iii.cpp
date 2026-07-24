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
    int pathSumRec(TreeNode* curr, vector<int>& currentPath, int sum) {
        if(!curr) return 0;
        currentPath.push_back(curr->val);
        int pathCount = 0;
        long long pathSum = 0;
        for(int i=currentPath.size() - 1;i>=0;i--) {
            pathSum += currentPath[i];
            if(pathSum == sum) {
                pathCount++;
            }
        }
        pathCount += pathSumRec(curr->left, currentPath, sum);
        pathCount += pathSumRec(curr->right, currentPath, sum);
        currentPath.pop_back();
        return pathCount;
    }
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> currentPath;
        return pathSumRec(root, currentPath, targetSum);
    }
};