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
    int findBottomLeftValue(TreeNode* root) {
        map<int,int> mp;
        function<void(TreeNode *rt,int depth)> rec=[&](TreeNode *rt,int depth){
            if(!rt)return;
            
            if(mp.find(depth)==mp.end())mp[depth]=rt->val;
            rec(rt->left,depth-1);
            rec(rt->right,depth-1);
        };
        rec(root,0);
        return mp.begin()->second;
    }
};