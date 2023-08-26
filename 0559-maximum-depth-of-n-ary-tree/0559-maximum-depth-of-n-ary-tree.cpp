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
    int maxDepth(Node* root) {
        function<int(Node *rt)> rec=[&](Node *rt){
            if(!rt)return 0;
            
            int curr=1;
            for(auto i:rt->children){
                curr=max(curr,rec(i)+1);
            }
            // cout<<rt->val<<" "<<curr<<endl;
            return curr;
        };
        return rec(root);
    }
};