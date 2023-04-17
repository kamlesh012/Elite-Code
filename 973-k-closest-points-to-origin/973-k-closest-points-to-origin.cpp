class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair
            <double,pair<int,int>>,
        vector<pair<double,pair<int,int>>>
            ,greater<pair<double,pair<int,int>>>
            > pq;
        
        for(auto i:points){
            //Basic Observation that I missed.
            //If using sqrt use double as datatype
            
            //else the same problem can also be solved without using sqrt at all.
            
            double number=((i[0]*i[0])+(i[1]*i[1]));
            double distance=sqrt(number);
            pq.push({distance,{i[0],i[1]}});
        }
        vector<vector<int>> ans;
        for(int i=0;i<k;i++){
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};