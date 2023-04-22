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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        int cnt=0,ans=0;
        q.push({root,cnt});
        // int level=0;
        while(q.size()){
            int n=q.size();
            int flag=0,first=-1,last=0;
            // level++;
                // cout<<level<<endl;
            //a way to avoid cnt(values of nodes) from getting large.
            //explained below: or check Aryan Mittal's Video/Discuss solution.
            
            int reduce_node_value=q.front().second;
            for(int i=0;i<n;i++){
                auto it=q.front();
                q.pop();
                
                // int nodes_at_curr_level=1<<level;
                //Technically this is also correct,to take the max nodes possible till this previous level & subtract current nodes value(cnt) to avoid values from getting larget but  the total no. of nodes till previous level is overflowing itself,as 1<<1500 can get out of bounds.
                //Note that: if a same value is subtracted from all nodes then their difference will still remain the same. 
                //So we we are just subtracting the number of nodes at just previos level
                //each time so that the values won't get bigger.
                // cout<<nodes_at_curr_level<<endl;
                
                //so to avoid overflow we are using the above method.
                
                if(first==-1)first=it.second;
                last=it.second;
                int dist=it.second-reduce_node_value;
                if(it.first->left){
                        q.push({it.first->left,(2ll*dist+1)});
                }
                if(it.first->right){
                    q.push({it.first->right,(2ll*dist+2)});
                } 
                //ll is used above because the values can still get larger than int size even though the difference will
                //always be in range of int. this is written in problem statement.
            }
            ans=max(ans,last-first+1);
        }
        return ans;
        
        //check this for clear explanation:
        // https://leetcode.com/problems/maximum-width-of-binary-tree/discuss/3436593/Image-Explanation-Why-long-to-int-C%2B%2BJavaPython
        //TLEd Simulation:
        
        // while(q.size()){
        //     int n=q.size();
        //     int flag=0,first=-1,last=0;
        //     for(int i=0;i<n;i++){
        //         auto it=q.front();
        //         q.pop();
        //         if(it.first==nullptr){
        //             q.push({it.first,cnt+1});
        //             cnt++;
        //             q.push({it.first,cnt+1});
        //             cnt++;
        //         }
        //         else{
        //             if(first==-1)first=it.second;
        //             last=it.second;
        //             q.push({it.first->left,cnt+1});
        //             cnt++;
        //             q.push({it.first->right,cnt+1});
        //             cnt++;
        //         }     
        //     }
        //     if(first==-1)break;
        //     ans=max(ans,last-first+1);
        // }
        // return ans;
    }
};