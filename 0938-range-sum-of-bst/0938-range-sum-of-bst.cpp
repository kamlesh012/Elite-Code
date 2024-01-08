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
    int rangeSumBST(TreeNode* root, int low, int high) {
        function<int(TreeNode *rt)> sum=[&](TreeNode *rt){
            if(rt){
                int ans=0;
                if(rt->val>=low && rt->val<=high)ans+=rt->val;
                return ans+sum(rt->left)+sum(rt->right);
            }
            else return 0;
        };
        return sum(root);
    }
};