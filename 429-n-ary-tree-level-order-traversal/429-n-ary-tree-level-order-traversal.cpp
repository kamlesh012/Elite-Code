/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
         //THe smartest BFS can get.
        //Processing a level at a time.
        vector<vector<int>> ans;
        
        queue<Node*> q;
        if(root)q.push(root);
        
        while(q.size()){
            
            int n=q.size();
            vector<int> curr_level;
            
            for(int i=0;i<n;i++){
                
                auto it=q.front();
                curr_level.push_back(it->val);
                q.pop();
                
                for(auto child:it->children){
                    if(child)q.push(child);
                }
                
            }
            ans.push_back(curr_level);
        }
        return ans;
    }
};