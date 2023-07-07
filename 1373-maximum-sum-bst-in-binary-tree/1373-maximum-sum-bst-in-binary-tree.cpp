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

//Creating a Maximum Sum BST Class named MST
//with four members;
class MST{
    public:
    int sum,mx,mn;
    bool isbst;
    
    MST(){
        sum=0;      //sum of left chlid+current node + right child
        mx=INT_MIN;       //max value in tree
        mn=INT_MAX;       //min value in tree
        isbst=true; 
    }
};

class Solution {
public:
    int ans=0;
    MST* calculate(TreeNode* root){
    if(!root)return new MST();
        
    int curr=root->val;
        
    MST *node =new MST();
    MST *left=calculate(root->left);
    MST *right=calculate(root->right);
        
    // cout<<"ROOT "<<curr<<endl;
    // cout<<left->mx<<" "<<right->mn<<endl;
        
    if(left->isbst && right->isbst && left->mx<curr && right->mn>curr){
        
        node->isbst=true;
        //Recalculate the sum of whole tree now
        node->sum=(left->sum+curr+right->sum);
        
        //Recalculate the Minimum in whole tree
        node->mn=min(left->mn,curr);
        
        //Recalculate the Maximum in whole tree
        node->mx=max(right->mx,curr);
        
        ans=max(ans,node->sum);
    }
    else node->isbst=false;
        
    return node;
    }
    
    int maxSumBST(TreeNode* root) {
        calculate(root);
        return ans;
    }
};