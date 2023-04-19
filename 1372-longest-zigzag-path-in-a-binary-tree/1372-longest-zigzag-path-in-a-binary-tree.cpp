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
    int ans=0;
    
    pair<int,int> path(TreeNode*root){
        if(root && (root->left || root->right)){
            auto l=path(root->left);
            auto r=path(root->right);
            
            // pair<int,int> ans={0,0};
            
            int lans=l.second+1,rans=r.first+1;
            // cout<<l.first<<" "<<l.second<<endl;
            // cout<<r.first<<" "<<r.second<<endl;
            // ans=max(ans,(l.second)+1);
            // ans=max(ans,(r.first)+1);
            ans=max(ans,lans);
            ans=max(ans,rans);
            return pair<int,int>{l.second+1,r.first+1};
        }
        else if(!root){
            return pair<int,int>{-1,-1};
        }
        else {
            return pair<int,int>{0,0};
        }
    }
    int longestZigZag(TreeNode* root) {
        path(root);
        return ans;
    }
};