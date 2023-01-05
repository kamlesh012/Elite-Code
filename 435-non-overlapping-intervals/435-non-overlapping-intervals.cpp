class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        int cnt=0,end=intervals[0][1];
        
        for(int i=1;i<n;i++){
            if(end>intervals[i][0]){
                cnt++;
                end=min(end,intervals[i][1]);
            }
            else end=intervals[i][1];
        }
        
        return cnt;
    }
};