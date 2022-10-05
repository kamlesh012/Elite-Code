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
    bool sol(TreeNode *root,int target,int curr){
        if(root && !root->left && !root->right){
            if(curr+root->val==target)return true;
        }
        else if(root){
            bool l=sol(root->left,target,curr+(root->val));
            bool r=sol(root->right,target,curr+(root->val));
            return l || r;
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return sol(root,targetSum,0);
    }
};