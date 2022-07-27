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
    TreeNode * fbt(TreeNode *root){
            if(!root)return root;
            root->left=fbt(root->left);
            root->right=fbt(root->right);
        
        if(root->left){
            TreeNode *stored=root->right;
            root->right=root->left;
            root->left=NULL;
            TreeNode*ptr=root->right;
            while(ptr && ptr->right!=NULL)ptr=ptr->right;
            ptr->right=stored;
        }
        return root;
    }
    void flatten(TreeNode* root) {
        root=fbt(root);
    }
};