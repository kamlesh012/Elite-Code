class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& weight, int start, int end) {
        
        vector<vector<pair<int,double>>> adjl(n);
        for(int i=0;i<edges.size();i++){
            adjl[edges[i][0]].push_back({edges[i][1],weight[i]*(-1)});
            adjl[edges[i][1]].push_back({edges[i][0],weight[i]*(-1)});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,start});
        vector<double> dist(n+1,1e9);
        dist[start]=1;
        
        while(pq.size()){
            auto it=pq.top();
            pq.pop();
            
            int curr=it.second;
            int curr_wt=it.first;
            
            for(auto child:adjl[curr]){
                double wt=abs(child.second);
                int node=child.first;
                
                if(dist[node]>((-1)*(abs(dist[curr])*wt))){
                    dist[node]=((-1)*(abs(dist[curr])*wt));
                    pq.push({dist[node],node});
                }
            }
        }
        if(dist[end]==1e9)return 0;
        return -1*dist[end];
    }
};