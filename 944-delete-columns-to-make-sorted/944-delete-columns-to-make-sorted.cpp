class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        
        int m=strs[0].length();
        int n=strs.size();
        // int mx=0;
        
        int cnt=0;
        for(int j=0;j<m;j++){
            for(int i=1;i<n;i++){
                 if(strs[i][j]<strs[i-1][j]){cnt++;break;}
            }
        }
        return cnt;
    }
};