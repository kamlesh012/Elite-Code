class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
         int n=h.size(),sum=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=1;i<n;i++){
            int diff=h[i]-h[i-1];
            if(diff>0){
                pq.push(diff);
                if(pq.size()>ladders){
                    sum+=pq.top();
                    pq.pop();
                    if(sum>bricks)return i-1;
                }
            }
        }
        return n-1;
        
    }
};