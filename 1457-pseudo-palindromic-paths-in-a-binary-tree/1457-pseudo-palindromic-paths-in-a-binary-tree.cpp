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
    
    int pseudoPalindromicPaths (TreeNode* root) {
//         Understand the XOR approach as well.
//         & CLarify this approach as well.
//         why is passing oddcnt by reference causing an error.
        vector<int> freq(10,0);
        function<int(TreeNode *rt,int oddcnt)> solve=[&](TreeNode *rt,int oddcnt){
            if(rt){
                int curr=rt->val;
                freq[curr]++;
                if(freq[curr]&1)oddcnt++;
                else oddcnt--;

                int ans=solve(rt->left,oddcnt)+solve(rt->right,oddcnt);
                if(!rt->left && !rt->right && oddcnt<=1)ans++;
                
                freq[curr]--;
                return ans;  
            }
            return 0;
        };
        return solve(root,0);
    }
};