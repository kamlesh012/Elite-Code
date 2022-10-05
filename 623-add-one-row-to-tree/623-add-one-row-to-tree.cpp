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
    TreeNode *add(TreeNode* root,TreeNode *prev,int val,int depth,int curr){
        if(curr==depth){
            TreeNode *here=new TreeNode(val);
            if(prev && prev->left==root){
                prev->left=here;
                here->left=root;
                return prev->left;
            }
            else if(prev && prev->right==root){
                prev->right=here;
                here->right=root;
                return prev->right;
            }
            else{
                here->left=root;
                return here;
            }
        }
        if(root){
            root->left=add(root->left,root,val,depth,curr+1);
            root->right=add(root->right,root,val,depth,curr+1);
            return root;
        }
        return NULL;
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        root=add(root,NULL,val,depth,1);
        return root;
    }
};