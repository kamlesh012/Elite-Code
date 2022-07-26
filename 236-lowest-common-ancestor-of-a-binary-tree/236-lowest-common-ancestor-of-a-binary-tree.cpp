/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q)return root;
        
        TreeNode* one=lowestCommonAncestor(root->left,p,q);
        TreeNode* two=lowestCommonAncestor(root->right,p,q);
        
        if(one==NULL)return two;
        else if(two==NULL)return one;
        else return root;
    }
};