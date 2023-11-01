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
    vector<int> findMode(TreeNode* root) {
        map<int,int> mp;
        function<void(TreeNode *rt)> rec=[&](TreeNode *rt){
            if(rt){
                mp[rt->val]++;
                rec(rt->left);
                rec(rt->right);
            }
        };
        rec(root);
        int mx=0,mxf=0;
        for(auto i:mp){
            if(i.second>mxf){
                mxf=i.second;
            }
        }
        vector<int> ans;
        for(auto i:mp){
            if(i.second==mxf){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};