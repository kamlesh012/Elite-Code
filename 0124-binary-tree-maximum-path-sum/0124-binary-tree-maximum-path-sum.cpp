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
    int mx=INT_MIN;
    int maxPathSum(TreeNode* root) {
        
        function<int(TreeNode*)> trav=[&](TreeNode* root){
          if(!root) return 0;
            
            int left=trav(root->left);
            int right=trav(root->right);
            int path_mx=max(left,right)+root->val;
            int total_mx=left+right+root->val;
            
            mx=max(mx,max(total_mx,max(path_mx,root->val)));
            
            return max(root->val,path_mx);
        };
        
        trav(root);
        return mx;
    }
};