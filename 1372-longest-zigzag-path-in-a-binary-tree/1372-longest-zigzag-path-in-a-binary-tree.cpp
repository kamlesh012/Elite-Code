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
    int ans=0;
    
    pair<int,int> path(TreeNode*root){
        if(!root){
            return pair<int,int>{-1,-1};
        }
        else if(root->left || root->right){
            
            auto l=path(root->left);
            auto r=path(root->right);
            
            int left_ans=l.second+1,right_ans=r.first+1;
            
            ans=max({ans,left_ans,right_ans});
            
            return pair<int,int>{left_ans,right_ans};
        }
        else {
            return pair<int,int>{0,0};
        }
    }
    int longestZigZag(TreeNode* root) {
        path(root);
        return ans;
    }
};