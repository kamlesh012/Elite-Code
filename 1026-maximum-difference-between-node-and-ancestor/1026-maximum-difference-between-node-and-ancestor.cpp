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
    vector<int> nodes;
    int mx=INT_MIN;
    void rec(TreeNode *root){
        if(root){
            int curr=root->val;
            for(auto i:nodes){
                mx=max(mx,abs(i-curr));
            }
            nodes.push_back(curr);
            rec(root->left);
            rec(root->right);
            nodes.pop_back();
        }
    }
    
    int maxAncestorDiff(TreeNode* root) {
        
        rec(root);
        return mx;
        
    }
};