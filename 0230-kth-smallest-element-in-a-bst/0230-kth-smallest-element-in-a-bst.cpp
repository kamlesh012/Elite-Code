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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> traversed;
        
        function<void(TreeNode*)> in=[&](TreeNode *root){
            if(root){
                in(root->left);
                traversed.push_back(root->val);
                in(root->right);
            }
        };
        in(root);
        return traversed[k-1];
    }
};