class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& weight, int start, int end) {
        vector<vector<pair<int,double>>> adjl(n);
        for(int i=0;i<edges.size();i++){
            adjl[edges[i][0]].push_back({edges[i][1],weight[i]*(-1)});
            adjl[edges[i][1]].push_back({edges[i][0],weight[i]*(-1)});
            // adjl[edges[i][0]].push_back({edges[i][1],weight[i]*(1)});
            // adjl[edges[i][1]].push_back({edges[i][0],weight[i]*(1)});
            
            // for(int j=0;j<adjl[i].size();j++){
            //     cout<<i<<" -> "<<adjl[i][j].first<<" => "<<adjl[i][j].second<<endl;
            // }
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        // priority_queue<pair<int,int>> pq;
        pq.push({0,start});
        vector<double> dist(n+1,1e9);
        dist[start]=1;
        
        
       // for(auto i:dist){
       //      cout<<i<< " ";
       //  }
        // int parent=-1;
        while(pq.size()){
            auto it=pq.top();
            pq.pop();
            
            int curr=it.second;
            int curr_wt=it.first;
            // cout<<"Source "<<curr<<endl;
            // cout<<"Dist from start "<<currwt<<endl;
            
            for(auto child:adjl[curr]){
                double wt=abs(child.second);
                int node=child.first;
                // cout<<"Child "<<node<<" Child Weight "<<wt<<endl;
                // cout<<"Original Dist  "<<dist[node]<<"Now Dist"<<((-1)*(abs(dist[curr])*wt))<<endl;
                if(dist[node]>((-1)*(abs(dist[curr])*wt))){
                // if(dist[node]>((1)*(abs(dist[curr])*wt))){
                    // parent=curr;
                    dist[node]=((-1)*(abs(dist[curr])*wt));
                    // dist[node]=((1)*(abs(dist[curr])*wt));
                    pq.push({dist[node],node});
                }
                // cout<<"After Dist  "<<dist[node]<<"Now Dist"<<((-1)*(abs(dist[curr])*wt))<<endl;
                // break;
            }
            // break;
        }
        // for(auto i:dist){
        //     cout<<i<< " ";
        // }
        // cout<<endl;
        if(dist[end]==1e9)return 0;
        return -1*dist[end];
        // return dist[end];
        
    }
};