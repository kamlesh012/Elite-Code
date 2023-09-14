class Solution {
public:
    int minDeletions(string s) {
        int n=s.size();
        
        //5 5 5 8 8 8 8
        // Bottom to top 5->3 4 5     8-> 6 7 8 2 (2+1+ 6+2+1)
        //Top to Bottom 8->4 6 7 8   5->2 3 5(4+2+1+ 3+2)
        
        unordered_map<char,int> mp;
        int mx=0;
        for(auto i:s){
            mp[i]++;
            mx=max(mx,mp[i]);
        }
        
        vector<int> freq(mx+1,0);
        for(auto i:mp){
            freq[i.second]++;
        }
        
        int ans=0,steps=0;
        for(int i=0;i<=mx;i++){
            if(freq[i]>1){
                int curr=freq[i]-1,steps=0;
                int j=i;
                while(j>0 && curr){
                    if(freq[j]==0){
                        curr--;
                        freq[j]++;
                        ans+=steps;
                    }
                    steps++;
                    j--;
                }
                ans+=(curr*steps);
            }
        }
        
        return ans;
    }
};