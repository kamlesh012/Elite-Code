class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        //Using row & col flags as indicator for turning first row or col zero .
        bool col=false,row=false;
        int n=matrix.size();
        int m=matrix[0].size();
        
        //mark flags as true if first row & first col contains any zero
        for(int i=0;i<m;i++){
            if(matrix[0][i]==0)row=true;
        }
        
        for(int j=0;j<n;j++){
            if(matrix[j][0]==0)col=true;
        }
        
        //For all row & col except for first row & first col
        //if cell is zero mark it's first row & first col to zero.
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]==0){
                        matrix[i][0]=0;
                        matrix[0][j]=0;
                    }
            }
        }
        
        //if first index of ith row or jth col is zero mark current cell as zero.
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        
        //if there is any zero in first col mark the whole col as zero
        if(col){
            for(int i=0;i<n;i++){
                matrix[i][0]=0;
            }
        }
        //if there is any zero in first row mark the whole row as zero
        if(row){
            for(int i=0;i<m;i++){
                matrix[0][i]=0;
            }
        }
        
    }
};