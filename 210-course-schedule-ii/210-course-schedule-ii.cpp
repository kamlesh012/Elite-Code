class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
         vector<vector<int>> adjl(n);
        //converting to adjacency list
        for(auto i:prerequisites){
            adjl[i[1]].push_back(i[0]);
        }
        vector<int> indegree(n,0);
        //calculating indegree of each node
        for(auto i:adjl){
            for(auto j:i){
                indegree[j]++;
            }
        }
        //kahn's algorithm for topological sorting.
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)q.push(i);
        }
        
        vector<int> ans;
        while(!q.empty()){
            int val=q.front();
            q.pop();
            ans.push_back(val); //storing the node that is to be visted first.
            for(auto i:adjl[val]){
                indegree[i]--;
                if(indegree[i]==0)q.push(i);
            }
        }
        //if all nodes cannot be visited then clear the stored nodes.
        if(ans.size()!=n)ans.clear();
        return ans;
    }
};