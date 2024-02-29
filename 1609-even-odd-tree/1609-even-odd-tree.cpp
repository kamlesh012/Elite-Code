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
    bool isEvenOddTree(TreeNode* root) {
       queue<TreeNode*> q;
        q.push(root);
        int level=0;
        while(q.size()){
            int n=q.size();
            vector<int> nodes;
            
            for(int i=0;i<n;i++){
                TreeNode *curr=q.front();
                nodes.push_back(curr->val);
                q.pop();
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
            
            
            if(level%2==0){
                if(nodes.size() &&  nodes[0]%2==0)return false;
                for(int i=1;i<nodes.size();i++){
                    if(nodes[i]%2==0 || nodes[i]<=nodes[i-1])return false;
                }
            }
            else {
                if(nodes.size() &&  nodes[0]%2)return false;
                for(int i=1;i<nodes.size();i++){
                    if(nodes[i]%2 || nodes[i]>=nodes[i-1])return false;
                }
            }
            
            level++;
        }
        return true;
    }
};