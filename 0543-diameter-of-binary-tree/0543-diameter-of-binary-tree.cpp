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
    int diameterOfBinaryTree(TreeNode* root) {
    int mx=0;
     function<int(TreeNode*rt)> diam=[&](TreeNode*rt){
        if(!rt) return 0;
        int left=diam(rt->left);
        int right=diam(rt->right);
         
//          if a path passes from current node, then check if it's diameter or not
         
//          diameter passing from current node = left child edges+ right child edges
         mx=max(mx,left+right);
         
//          return the maximum path from current node to any of it's leaves
//          so that it can be used to calculate the diameter later
//          +1  to include the edge between current node & its parent as well.
         return max(left,right)+1;
     };
        
        diam(root);
        return mx;
    }
};