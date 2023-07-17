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
    int pathSum(TreeNode* root, int target) {
        function<long long(TreeNode*,vector<int>)> traverse=[&](TreeNode *rt,vector<int> parents){
         if(rt){
                parents.push_back(rt->val);
                int left=traverse(rt->left,parents);
                int right=traverse(rt->right,parents);
                long long curr=0ll,sum=0ll;
                for(int i=parents.size()-1;i>=0;--i){
                    curr+=parents[i];
                    if(curr==target)sum++;
                }
                parents.pop_back();
                return left+right+sum;
         }
         return 0ll;   
        };
        
        vector<int> parents;
        return traverse(root,parents);
    }
};