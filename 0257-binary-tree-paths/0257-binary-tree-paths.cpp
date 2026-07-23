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
    void findPath(TreeNode* node, vector<string>& allPaths, string temp) {
        temp += to_string(node->val);
        if(node->left) findPath(node->left, allPaths, temp + "->");
        if(node->right) findPath(node->right, allPaths, temp + "->");
        if(!node->left && !node->right) allPaths.push_back(temp);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> allPaths;
        if(root) findPath(root, allPaths, "");
        return allPaths;
    }
};