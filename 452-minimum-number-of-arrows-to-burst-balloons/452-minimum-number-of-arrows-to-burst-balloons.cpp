class Solution {
public:
    //Comparator for sorting points in increasing order of first index.
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
        
        //THe Idea is simple:-
        //sort all points in increasing order of index.
        //let each point be denoted as start & end (as given in problem satement).
        
        //Now while traversing the whole array
        //at each index curr will represent the minimum end point(the max range till which we can burst the balloon with a single arrrow)
        // in other words: curr=min(curr,end point of current point)
        
        //if curr is >= start of (i+1) :
        //it means single arrow can shoot both ballons because intervals are overlapping so we will continue checking 
        // if further intervals also overlap or not. & curr will still store the minimum of all endpoints in this overlap.
        
        //else if curr is <start of (i+1):
        //it means the next balloon cannot be burst with the same arrow as previous ones because it's not overlapping.
        //so we will incremeent the answer & do the same procedure from current index for further onwards.
        
        for(int i=0;i<n-1;i++){
            
            curr=min(curr,points[i][1]);
            
            if(curr<points[i+1][0]){
                cnt++;curr=INT_MAX;
            }
        }
        
        return cnt;
    }
};