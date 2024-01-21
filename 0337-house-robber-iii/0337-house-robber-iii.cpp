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
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,unordered_map<bool,int>> dp;
        
        function<int(TreeNode *rt,bool flag)> memo=[&](TreeNode *rt,bool flag){
            if(!rt)return 0;
            if(dp.find(rt)!=dp.end() && dp[rt].find(flag)!=dp[rt].end())return dp[rt][flag];
            
            int pick=0,notpick=0;
            if(flag)pick=(rt->val)+memo(rt->left,false)+memo(rt->right,false);
            notpick=memo(rt->left,true)+memo(rt->right,true);
            return dp[rt][flag]=max(pick,notpick);
        };
        return memo(root,true);
    }
};