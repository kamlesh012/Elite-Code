class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjl(n);
        //converting to adjacency list
        for(auto i:prerequisites){
            adjl[i[0]].push_back(i[1]);
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
        
        int cnt=0;
        while(!q.empty()){
            int val=q.front();
            q.pop();
            cnt++;
            for(auto i:adjl[val]){
                indegree[i]--;
                if(indegree[i]==0)q.push(i);
            }
        }
        return cnt==n;
        
    }
};