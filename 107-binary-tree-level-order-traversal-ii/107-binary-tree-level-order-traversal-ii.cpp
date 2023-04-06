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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
         //THe smartest BFS can get.
        //Processing a level at a time.
        vector<vector<int>> ans;
        
        queue<TreeNode*> q;
        if(root)q.push(root);
        
        while(q.size()){
            
            int n=q.size();
            vector<int> curr_level;
            
            for(int i=0;i<n;i++){
                
                auto it=q.front();
                curr_level.push_back(it->val);
                q.pop();
                
                if(it->left)q.push(it->left);
                if(it->right)q.push(it->right);
                
            }
            ans.push_back(curr_level);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};