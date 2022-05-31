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
    bool sum(TreeNode *root,int target,int curr){
        if(root && !root->left && !root->right)
        {
            curr+=root->val;
            if(curr==target)return true;
            return false;
        }
        else if(root){
            curr+=root->val;
            bool ok1=sum(root->left,target,curr);
            bool ok2=sum(root->right,target,curr);
            return ok1||ok2;
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
     return sum(root,targetSum,0)   ;
    }
};