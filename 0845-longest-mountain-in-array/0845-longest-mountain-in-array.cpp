class Solution {
public:
    int longestMountain(vector<int>& a) {
      int n=a.size();
        int inc=0,dec=0,ans=0;
        for(int i=1;i<n;i++){
            cout<<inc<<" "<<dec<<endl;
            if(a[i]>a[i-1]){
                if(!dec)inc++;
                else{
                    dec=0;
                    inc=1;
                }
            }
            else if(inc && a[i]<a[i-1]){
                dec++;
                ans=max(ans,inc+dec+1);
            }
            else inc=0,dec=0;
        }
        cout<<endl;
        return ans;
    }
};