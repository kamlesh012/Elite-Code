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
    int mxh=INT_MIN;
    vector<int> ans;
    void rv(TreeNode* root,int ch){
        if(root){
            if(ch>mxh){
                mxh=ch;
                ans.push_back(root->val);
            }
            rv(root->right,ch+1);
            rv(root->left,ch+1);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        rv(root,0);
        return ans;
    }
};