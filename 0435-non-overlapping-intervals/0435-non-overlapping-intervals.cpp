class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        
        //Sorting in increasing order of end time.
        //breaking the tie by increasing order of start time.
    sort(a.begin(),a.end(),[&](vector<int> &f,vector<int> &s){
       if(f[1]==s[1])return f[0]<s[0];
        return f[1]<s[1];
    });
        
        //1->if next interval intersects the current one then simply don't choose the next interval
        //we are doing this because if the next interval intersects the current one then we would have only one choice out of these two. now lets call the interval after next as next2.
        //suppose next2 also intersects current interval that means it would definitely intersect next as well(because these are sorted in increasing order of end time)(see TC1 Below).
        //that means till the point a interval keeps intersecting the current one all of the intervals in between would be overlapping , & we would have to choose only one out of them.
        //so we are choosing the first one with minimum end time so that it will intersect with least possible upcoming intervals.
//         Example: TC1(Below)
        
        //2->else if next interval doesn't intersect the current one pick that one & that interval will become current interval for next iterations & follow  point(1) for rest intervals.
        
        //Test Case for Better Understanding of this algorithm
        //TC1-> [1,5][2,5][3,6][4,6]         //ans->1
        //TC2-> [1,5][5,8][3,9][4,10]        ans->2
        
        int remove=0;
        int last=-1e6;
        for(auto i:a){
            if(last>i[0]){
                remove++;
            }
            else last=i[1];
        }
        return remove;
        //CHeck offical solution for better understanding.
    }
};