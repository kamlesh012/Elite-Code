class Solution {
public:
    long long putMarbles(vector<int>& ws, int k) {
        int n=ws.size();
        //if there is only one marble or no. of marbles are equal to no. of segments
        //in these cases there would be only one distribution.
        //so min & max will be equal. resulting in 0 difference.
        // if(n==1 || k==n)return 0;
        vector<int> segments;

        //First & Last will be added at least once in every possible segment;
        long long sum=0;
        sum+=ws[0];
        sum+=ws.back();
        for(int i=0;i<n-1;i++){
            segments.push_back(ws[i]+ws[i+1]);
        }
        sort(segments.begin(),segments.end());
        long long int mx=sum,mn=sum;
        int m=segments.size();
        for(int i=0;i<k-1;i++){
            mn+=segments[i];
            mx+=segments[m-i-1];
        }
        return mx-mn;
    }
};