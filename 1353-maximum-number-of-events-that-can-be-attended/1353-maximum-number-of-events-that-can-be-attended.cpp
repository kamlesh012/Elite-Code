class Solution {
public:
    int maxEvents(vector<vector<int>>& a) {
        
        sort(a.begin(),a.end());
        priority_queue<int,vector<int>,greater<int>> pq;
        int index=0,n=a.size(),attended=0;
        
        for(int d=1;d<=100000;d++){
            while(pq.size() && pq.top()<d)pq.pop();
            
            while(index<n && a[index][0]==d){
                pq.push(a[index][1]);
                index++;
            }
            
            if(pq.size() && pq.top()>=d){
                attended++;
                pq.pop();
            }
            
            if(index==n && pq.empty())break;
            
        }
        
        return attended;
    }
};