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
    int longestUnivaluePath(TreeNode* root) {
        int ans=0;
       function<int(TreeNode*)>  traverse=[&](TreeNode *rt){
        if(!rt)return 0;
           int left=traverse(rt->left);
           int right=traverse(rt->right);
           
           if(rt->left && rt->val==rt->left->val){
                left++;
           }
           else left=0;
           
           if(rt->right && rt->val==rt->right->val){
                right++;
           }
           else right=0;
           if(rt->left && rt->right && rt->left->val==rt->right->val && rt->val==rt->left->val){
               ans=max(ans,left+right);
           }
           
           ans=max(ans,max(left,right));
           return max(left,right);
       };
        traverse(root);
        return ans;
    }
};