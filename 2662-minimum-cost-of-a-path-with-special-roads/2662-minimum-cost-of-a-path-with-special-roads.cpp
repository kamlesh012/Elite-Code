class Solution {
public:
    // distance map,instead of array as values will be sparse.
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
        
        //Min heap is ideal for this situation.
        //I am using a vector as min heap.
        //the min heap will store (distance of current road from start,x-end of current road,y-end of current road);
        //only storing end coordinates of each special road .
        //doesn't need starting coordinates in pq.
        //could have been done using starting coordinates but would have been complex.
        
        set<vector<int>> pq;
        pq.insert({0,start[0],start[1]});
        long long ans=cost(start[0],start[1],target[0],target[1]);
        
        int mx=max(target[0],target[1]);
        // vector<vector<int>> dist(mx+1,vector<int>(mx+1,INT_MAX));
        
        while(pq.size()){
            
            auto it=pq.begin();
            int cost_from_start=(*it)[0];
            int x=(*it)[1],y=(*it)[2];
            pq.erase(it);
            
            //for each node calculate the cost it required to reach this node from start
            //+ the cost it will require to reach end.
            //doing this to prevent recauculating the same from distance matrix/map at the end.
            long long cost_to_target=cost_from_start+cost(x,y,target[0],target[1]);
            ans=min(ans,cost_to_target);
            
            for(auto i:filtered_roads){
                int node_cost=cost(i[0],i[1],x,y)+i[4];
                if(!dist.count({i[2],i[3]}) || dist[{i[2],i[3]}]>node_cost+cost_from_start){
                    dist[{i[2],i[3]}]=node_cost+cost_from_start;
                // if(dist[i[2]][i[3]]>node_cost+cost_from_start){
                    // dist[i[2]][i[3]]=node_cost+cost_from_start;
                    pq.insert({node_cost+cost_from_start,i[2],i[3]});
                }
            }
        }
        
        return ans;
    }
};