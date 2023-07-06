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
    int ans,xk;
    void in(TreeNode *root,int &count){
            if(root){
                in(root->left,count);
                
                count++;
                
                if(count==xk){
                    ans=root->val;
                }
                
                in(root->right,count);   
            }
        }
    
    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        xk=k;
        // function<void(TreeNode*,int)> in=[&]
        in(root,count);
        return ans;
    }
};