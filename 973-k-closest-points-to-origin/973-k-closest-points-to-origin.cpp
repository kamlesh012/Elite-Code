class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair
            <int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>
            ,greater<pair<int,pair<int,int>>>
            > pq;
        
        for(auto i:points){
            //Basci Observation that I missed.
            //Not using sqrt will yeild the same result
            int distance=(((i[0]*i[0])+(i[1]*i[1])));
            pq.push({distance,{i[0],i[1]}});
        }
        vector<vector<int>> ans;
        for(int i=0;i<k;i++){
            // cout<<pq.top().first<<" "<<pq.top().second.first<<" "<<pq.top().second.second<<endl;
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};