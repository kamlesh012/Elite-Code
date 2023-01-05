class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]){
            return a[1]<b[1];
        }
        return a[0]<b[0];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(),points.end(),comp);
        int n=points.size();
        int cnt=1,curr=INT_MAX;
        
        for(int i=0;i<n-1;i++){
            
            curr=min(curr,points[i][1]);
            
            if(curr<points[i+1][0]){
                cnt++;curr=INT_MAX;
            }
        }
        
        return cnt;
    }
};