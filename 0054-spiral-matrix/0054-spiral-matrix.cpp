class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //GO RIGHT->DOWN ->LEFT ->UP.
        //maintain visited cnt to avoid edge cases.
        
        int col=matrix[0].size();
        int row=matrix.size();
        int total=col*row;
        int cnt=0;
        vector<int> ans;
        
        int startrow=0,endcol=col-1,endrow=row-1,startcol=0;
        while(cnt<total){
            for(int i=startcol;cnt<total && i<=endcol;i++){
                ans.push_back(matrix[startrow][i]);
                cnt++;
            }
            startrow++;
            for(int i=startrow;cnt<total && i<=endrow;i++){
                ans.push_back(matrix[i][endcol]);
                cnt++;
            }
            endcol--;
            for(int i=endcol;cnt<total && i>=startcol;i--){
                ans.push_back(matrix[endrow][i]);
                cnt++;
            }
            endrow--;
            for(int i=endrow;cnt<total && i>=startrow;i--){
                ans.push_back(matrix[i][startcol]);
                cnt++;
            }
            startcol++;
        }
        
        return ans;
    }
};