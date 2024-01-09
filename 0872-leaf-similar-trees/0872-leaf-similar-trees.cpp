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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        function<vector<int>(TreeNode* rt,vector<int> &v)> rec=[&](TreeNode *rt,vector<int> &v){
            if(rt){
                if(!rt->left && !rt->right){
                    v.push_back(rt->val);
                    // return v;
                }
                else{
                    rec(rt->left,v);
                    rec(rt->right,v);
                }
                    return v;
            }
            return v;
        };
        vector<int> ans1,ans2;
        ans1=rec(root1,ans1);
        ans2=rec(root2,ans2);
        return ans1==ans2;
    }
};