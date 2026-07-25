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
    vector<TreeNode*> generateTreesRec(int start, int end) {
        vector<TreeNode*> res;
        if(start > end) {
            res.push_back(nullptr);
            return res;
        }
        for(int i=start;i<end+1;i++) {
            vector<TreeNode*> leftSubtree = generateTreesRec(start, i-1);
            vector<TreeNode*> rightSubtree = generateTreesRec(i+1, end);
            for(int p=0;p<leftSubtree.size();p++) {
                for(int q=0;q<rightSubtree.size();q++) {
                    TreeNode* root = new TreeNode(i, leftSubtree[p], rightSubtree[q]);
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        return generateTreesRec(1, n);
    }
};