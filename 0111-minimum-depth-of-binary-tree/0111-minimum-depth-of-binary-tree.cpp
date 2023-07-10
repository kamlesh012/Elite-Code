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
    int minDepth(TreeNode* root) {
        function<int(TreeNode *)> rec=[&](TreeNode *ptr){
            if(!ptr)return 0;
            int l=10008,r=10008;
            if(ptr->left)l=rec(ptr->left);
            if(ptr->right)r=rec(ptr->right);
            
            if(l==10008 && r==10008)l=0;
            
            return min(l,r)+1;
        };
        return rec(root);
    }
};