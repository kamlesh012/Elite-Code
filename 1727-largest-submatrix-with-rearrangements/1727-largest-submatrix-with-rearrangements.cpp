class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        
        int row=matrix.size();
        int col=matrix[0].size();
        int ans=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i && matrix[i][j]!=0){
                    matrix[i][j]+=matrix[i-1][j];
                }        
            }
            
            vector<int> curr=matrix[i];
            sort(curr.begin(),curr.end(),greater());
            
            for(int k=0;k<col;k++){
                ans=max(ans,curr[k]*(k+1));
            }
        }
        return ans;
        
    }
};