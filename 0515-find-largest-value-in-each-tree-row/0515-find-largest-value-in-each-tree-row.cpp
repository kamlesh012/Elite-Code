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
    vector<int> largestValues(TreeNode* root) {
        
        map<int,int> mp;
        vector<int> ans;
        
        function<void(TreeNode*,int)> rec=[&](TreeNode* root,int level){
            if(root){
                if(mp.find(level)==mp.end())mp[level]=INT_MIN;
                mp[level]=max(mp[level],root->val);
                rec(root->left,level+1);
                rec(root->right,level+1);
            }
        };
        rec(root,0);
        
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};