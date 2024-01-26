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
        int diam=0; 
        function<int(TreeNode *rt)> height=[&](TreeNode *rt){
            if(!rt)return 0;
            int left=height(rt->left);
            int right=height(rt->right);
            diam=max(diam,left+right);
            return max(left,right)+1;
        };
        height(root);
        return diam;
    }
};