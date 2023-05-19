class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> colour(n,-1);
        vector<vector<int>> adjl(n);
        
        int id=0;
        for(auto i:graph){
            for(auto j:i){
                adjl[id].push_back(j);
            }
            id++;
        }
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(adjl[i].size() && colour[i]==-1){
                
                q.push(i);
                colour[i]=0;
                while(q.size()){
                    auto it=q.front();
                    q.pop();
                    for(auto curr:adjl[it]){
                        if(colour[curr]==colour[it])return false;
                        if(colour[curr]==-1){
                            colour[curr]=!colour[it];
                            q.push(curr);
                        }
                    }
                }
            }
        }
        
        return true;
    }
};