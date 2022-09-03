class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size();
        
        int h1[29999]={0};
        int h2[29999]={0};
        int freq[7]={0};
        for(int i=0;i<n;i++){
            h1[i]=tops[i];
            h2[i]=bottoms[i];
            freq[tops[i]]++;
            freq[bottoms[i]]++;
        }
        
        int mx=INT_MIN,mxn;
        for(int i=1;i<7;i++){
            if(freq[i]>mx){
                mx=freq[i];
                mxn=i;
            }
        }
        
        // for(int i=0;i<n;i++)cout<<h1[i]<<" ";cout<<endl;
        // for(int i=0;i<n;i++)cout<<h2[i]<<" ";cout<<endl;
        int t=0,b=0,ans=0;
        for(int i=0;i<n;i++){
            if(h1[i]==mxn)t++;
            if(h2[i]==mxn)b++;
            if(h1[i]!= mxn && h2[i]!=mxn){ans=-1;break;}
        }
        if(ans)return ans;
        return min(n-t,n-b);
        
        
    }
};