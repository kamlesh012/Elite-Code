class Solution {
public:
    int minOperations(vector<int>& a) {
        int i=1;
        int ops=0;
        while(i<a.size()){
            if(a[i]>a[i-1])i++;
            else{
                ops+=(a[i-1]-a[i])+1;
                a[i]=a[i-1]+1;
                i++;
            }
        }
        return ops;
        
    }
};