class Solution {
public:
    double myPow(double x, int n) {
        if(x==1.000)return x;
        if(n==0)return 1;
        function<double(double num,long long pow)> binexpo=[&](double num,long long pow){
            if(pow==1)return num;
            
            double curr=1.00;
            if(pow&1)curr*=num;
            double solution=binexpo(num,pow/2);
            // cout<<num<<" "<<pow<<" "<<curr<<" "<<solution<<endl;
            curr=curr*solution*solution;
            return curr;
        };
        
        double ans;
        if(n<0){
            long long m=n;
            m*=-1;
            ans=binexpo(x,m);
            ans=1.00/ans;
        }
        else ans=binexpo(x,n);
        
        return ans;
    }
};