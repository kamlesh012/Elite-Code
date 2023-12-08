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
    string tree2str(TreeNode* root) {
        
        string ans;
        function<void(TreeNode *rt)> rec=[&](TreeNode* rt){
            if(rt){
                int vl=rt->val;
                string str=to_string(vl);
                ans+=str;
                
                if(!rt->left && !rt->right)return;
                 
                ans.push_back('(');
                  if(rt->left)rec(rt->left);
                ans.push_back(')');
                
                if(rt->right){
                        ans.push_back('(');
                        rec(rt->right);
                        ans.push_back(')');
                    }
            }
        };
        rec(root);
        return ans;
        
    }
};