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
    vector<vector<int>> master;
    void path(TreeNode *root,vector<int> ans,int targetSum){
        if(root){
            targetSum-=root->val;
            ans.push_back(root->val);
            if(!root->left && !root->right && targetSum==0){
                master.push_back(ans);
            }
            path(root->left,ans,targetSum);
            path(root->right,ans,targetSum);
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> v;
        path(root,v,targetSum);
        return master;
    }
};