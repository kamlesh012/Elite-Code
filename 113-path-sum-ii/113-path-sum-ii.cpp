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
     vector<vector<int>> sum(TreeNode *root,int target,int curr,vector<int> ans){
         vector<int> temp;
         vector<vector<int>>t1;
        if(root && !root->left && !root->right)
        {   
            curr+=root->val;
            ans.push_back(root->val);
            if(curr==target)t1.push_back(ans);
                return t1;
        }
        else if(root){
            curr+=root->val;
            ans.push_back(root->val);
            vector<vector<int>> ok1=sum(root->left,target,curr,ans);
            vector<vector<int>> ok2=sum(root->right,target,curr,ans);
            if(!ok1.empty() && !ok1[0].empty()){
                for(auto x:ok1){
                    if(!x.empty())t1.push_back(x);
                }
            }
            if(!ok2.empty() && !ok2[0].empty()){
                for(auto x:ok2){
                    if(!x.empty())t1.push_back(x);
                }
            }
            return t1;
        }
        return t1;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        // vector<vector<int>> ans1;
        vector<int> ans;
        // vector<vector<int>> a1=sum(root,targetSum,0,ans);
        // if(a1.empty())return ans1;
        // else return a1;
        return sum(root,targetSum,0,ans);
    }
};