class Solution {
public:
    map<pair<int,int>,int> dist;
    long long cost(int x1,int y1,int x2,int y2){
        return abs(x2-x1)+abs(y2-y1);
    }
    
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& sr) {
        
        // mp[{start[0],start[1]}]=0;
        // mp[{target[0],target[1]}]=0;
        vector<vector<int>> filtered_roads;
        //Filter roads that are costlier than their manhattan distance.
        //Filtering will only reduce time complexity
        //THe algorightm will still work without filtering
        //because Dijsktra's algo will automatically put that road at last.
        for(auto i:sr){
            if(cost(i[0],i[1],i[2],i[3])>i[4]){
                filtered_roads.push_back(i);
            }
        }
        
        set<vector<int>> pq;
        pq.insert({0,start[0],start[1]});
        long long ans=cost(start[0],start[1],target[0],target[1]);
        
        while(pq.size()){
            
            auto it=pq.begin();
            int cost_from_start=(*it)[0];
            int x=(*it)[1],y=(*it)[2];
            pq.erase(it);
            
            long long cost_to_target=cost_from_start+cost(x,y,target[0],target[1]);
            ans=min(ans,cost_to_target);
            
            for(auto i:filtered_roads){
                int node_cost=cost(i[0],i[1],x,y)+i[4];
                if(!dist.count({i[2],i[3]}) || dist[{i[2],i[3]}]>node_cost+cost_from_start){
                    dist[{i[2],i[3]}]=node_cost+cost_from_start;
                    pq.insert({node_cost+cost_from_start,i[2],i[3]});
                }
            }
        }
        return ans;
    }
};