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
    vector<TreeNode*> allPossibleFBT(int n) {
        //Check COde Story wiht MIk's video:
//https://www.youtube.com/watch?v=lNEI25uT3WM
        
        //Memoization is Optional
        unordered_map<int,vector<TreeNode*>> dp;
        
        function<vector<TreeNode*>(int)> rec=[&](int n){    
            if(n%2==0)return vector<TreeNode*>();
            else if(n==1){
                TreeNode *demo=new TreeNode(0);
                return vector<TreeNode*>{demo};
            }
            else{
                
                if(dp.count(n))return dp[n];
                    
                    vector<TreeNode *> result;
                    for(int i=1;i<n;i+=2){
                        vector<TreeNode *> l,r;

                        //returns list of root nodes of all possible tree of size i;
                        l=rec(i);

                        //returns list of root nodes of all possible tree of size n-i-1;
                        r=rec(n-i-1);

                        //This particular tree with i nodes in left & n-i-1 nodes in right will be one of the possible FBTs with n nodes

                        //We will iterate all possible FBTs of the above kind. 
                        for(auto lnode:l){
                            for(auto rnode:r){
                                //suppose l=3 & r=5.
                                //then 3 from l will paired with root of all possible FBTs with n nodes,which are 2.
                            TreeNode *rt=new TreeNode(0);
                            rt->left=lnode;
                            rt->right=rnode;
                            result.push_back(rt);

                            // Will push all of their roots to result & use if parent function call.
                            }
                        }
                     }
                return dp[n]=result;
            }
        };
        return rec(n);
    }
};