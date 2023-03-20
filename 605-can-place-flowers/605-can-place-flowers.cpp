class Solution {
public:
    bool canPlaceFlowers(vector<int>& a, int n) {
        int alt1=0,alt2=0;
        for(int i=0;i<a.size();i++){
            
            // cout<<i<<" "<<a[i]<<endl;
            int prev=0,next=0;
            if(i>0)prev=a[i-1];
            if(i+1<a.size())next=a[i+1];
            // cout<<i<<endl;
            // cout<<prev<<" "<<next<<endl;
            // cout<<(i>0?a[i-1]:-1)<<" "<<((i+1<n)?a[i+1]:-2)<<endl;
            // cout<<endl;
            
            if(i&1 && !a[i]){
                // if(i>0 && (!a[i-1]) && i+1<a.size() && (!a[i+1]))
                if(!next && !prev)
                alt1++;
            }
            else if(!(i&1) && !a[i]){
                // if(i>0 && (!a[i-1]) && i+1<a.size() && (!a[i+1]))
                if(!next && !prev)
                alt2++;
            }
        }
        // cout<<alt1<<" "<<alt2<<endl;
        if(alt1>=n || alt2>=n)return true;
        return false;
    }
};