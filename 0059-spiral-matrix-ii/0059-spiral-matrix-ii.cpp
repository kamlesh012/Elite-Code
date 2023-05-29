class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // int col=matrix[0].size();
        // int row=matrix.size();
        int total=n*n;
        int cnt=1;
        vector<int> ans;
        
        vector<vector<int>> matrix(n,vector<int>(n,0));
        int startrow=0,endcol=n-1,endrow=n-1,startcol=0;
        while(cnt<=total){
            for(int i=startcol;cnt<=total && i<=endcol;i++){
                matrix[startrow][i]=cnt++;
            }
            startrow++;
            for(int i=startrow;cnt<=total && i<=endrow;i++){
                // ans.push_back(matrix[i][endcol]);
                matrix[i][endcol]=cnt++;
                // cnt++;
            }
            endcol--;
            for(int i=endcol;cnt<=total && i>=startcol;i--){
                // ans.push_back(matrix[endrow][i]);
                matrix[endrow][i]=cnt++;
                // cnt++;
            }
            endrow--;
            for(int i=endrow;cnt<=total && i>=startrow;i--){
                // ans.push_back(matrix[i][startcol]);
                matrix[i][startcol]=cnt++;
                // cnt++;
            }
            startcol++;
        }
        
        return matrix;
    }
};