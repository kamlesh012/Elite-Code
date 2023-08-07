class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        //Basically we have to find the nodes whose max distance from all other nodes is the minimum possible.
        //CLAIM1:These nodes are the middle of the diameter of the tree.
        //CLAIM2:The nodes are the centroid of the tree.
        //There can be at max 2 & at least 1 centriod.
        //A centroid is a node that has min possible distance to every node.
        
        //We can either use claim1 or claim2 to solve this problem.
        
        
        //I used claim 2 which uses Kahn's Topo Sort like Logic.
        //Basically we keep removing nodes with degree 1 & reduce degree of their neighbours.
        //at last level we will have either 1 or 2 nodes which will be centroid.
        
         if(n==0)
            return {};
        if(n==1)
            return {0};
        
        vector<set<int>> adjl(n);
        for(auto i:edges){
            adjl[i[0]].insert(i[1]);
            adjl[i[1]].insert(i[0]);
        }
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(adjl[i].size()==1){
                q.push(i);
                // cout<<i<<" ";
            }
        }
        // cout<<endl;
        
        vector<int> ans;
        //Performing BFS LEVEL BY LEVEL.
        while(q.size()){
            ans.clear();//clearing the node of previous level.
            int sz=q.size();
            
            //while current level is not complete do:
            for(int i=0;i<sz;i++){
                int curr=q.front();
                q.pop();
                
                //Storing Nodes at each level. as This might be possible answer.
                //as outer level gets cleared in next iterations the answer vector will 
                //store only the inner most nodes after the last iteration.
                //which will be the centroid nodes/node with min distance to every other node.
                ans.push_back(curr);
                
                for(auto node:adjl[curr]){
                    adjl[node].erase(curr);
                    if(adjl[node].size()==1)q.push(node);
                }
            }
        }
    
        
        return ans;
        
    }
};










