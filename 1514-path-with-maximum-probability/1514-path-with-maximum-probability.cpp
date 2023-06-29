class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& weight, int start, int end) {
        
        vector<vector<pair<int,double>>> adjl(n);
        for(int i=0;i<edges.size();i++){
            adjl[edges[i][0]].push_back({edges[i][1],weight[i]*(-1)});
            adjl[edges[i][1]].push_back({edges[i][0],weight[i]*(-1)});
        }
        //how is this code working for three connected nodes with weights
        //0.5 0.3 && 0.5
        ///dry run.
        
        vector<double> dist(n+1,1);//setting as 1 because 1 is the max dist possible. b/w 0 & 1.you can take it as infinity also.
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        //Pushing -1 to priority queue as -1 is the minimum distance possible b/w -1 & 0.
        //since start node will have min distance with itself,
        //so dist[start]=-1;     
        
        pq.push({-1,start});
        dist[start]=-1;
        
        while(pq.size()){
            
            auto it=pq.top();
            pq.pop();
            
            int curr=it.second;
            int curr_wt=it.first;
            
            for(auto child:adjl[curr]){
                
                double wt=abs(child.second);
                int node=child.first;
                
                if(dist[node]>(-1*abs(dist[curr])*wt)){
                    dist[node]=(-1*abs(dist[curr])*wt);
                    pq.push({dist[node],node});
                }
                
            }
       } 
        // for(auto i:dist){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        if(dist[end]==1)return 0;
        return -1*dist[end];
    }
};