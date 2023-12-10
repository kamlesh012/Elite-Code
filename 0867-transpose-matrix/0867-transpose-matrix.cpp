class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> t;
        int n=matrix.size();
        int m=matrix[0].size();
        
        for(int j=0;j<m;j++)
        {
            vector<int> temp;
            for(int i=0;i<n;i++)
            {
                temp.push_back(matrix[i][j]);
            }
            t.push_back(temp);
        }
        return t;
    }
};