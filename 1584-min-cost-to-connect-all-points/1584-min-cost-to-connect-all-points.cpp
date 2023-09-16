class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points){
        int n=points.size();
        vector<vector<pair<int,int>>> adjl(n+1);
        
//         Creating Adjacency List
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    int dist=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                    adjl[i].push_back({j,dist});
                }
            }
        }
        // int cnt=0;
        // for(auto i:adjl){
        //     cout<<cnt++<<endl;
        //     for(auto j:i){
        //         cout<<j.first<<" "<<j.second<<endl;
        //     }
        //     cout<<endl;
        // }
        
        //Prim's Algorithm for finding MST.
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,0});
        
        vector<int> vis(n+1,0);
        int cost=0;
        
        while(q.size()){    
            int curr=q.top().second;
            int adder=q.top().first;
            // cout<<q.top().first<<" "<<q.top().second<<endl;
            q.pop();
            
            if(!vis[curr]){
                cost+=adder;
                vis[curr]++;
                for(auto i:adjl[curr]){
                    if(vis[i.first]==0){
                        q.push({i.second,i.first});
                    }
                }
            }
        }
        return cost;
        
    }
};