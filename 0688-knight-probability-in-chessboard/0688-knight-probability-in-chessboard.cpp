class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(101,vector<vector<double>>(25+1,vector<double>(25+1,-1)));
        
        function<double(int ck,int r,int c)> rec=[&](int ck,int r,int c){
            if(r<0 || r>=n || c<0 || c>=n)return 0.0;
            if(ck==0)return 1.0;
            
            double &ans=dp[ck][r][c];
            if(ans!=-1)return ans;
            
                double sum=0.0;
                
                sum+=rec(ck-1,r-1,c-2);
                sum+=rec(ck-1,r-1,c+2);
                
                sum+=rec(ck-1,r+1,c-2);
                sum+=rec(ck-1,r+1,c+2);
                
                sum+=rec(ck-1,r-2,c-1);
                sum+=rec(ck-1,r-2,c+1);
                
                sum+=rec(ck-1,r+2,c-1);
                sum+=rec(ck-1,r+2,c+1);

                //since we've to find the probability.
                //Probability=(No. of favourable outcomes/Total no. of outcomes).
                
              return ans=sum/8.0;
        };
        
        return rec(k,row,column);
    }
};