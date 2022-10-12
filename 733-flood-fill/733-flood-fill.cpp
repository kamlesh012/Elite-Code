class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color){
        if(image[sr][sc]!=color)    //enter only if color is different
        {
            int n=image.size(),m=image[0].size();
            int prev=image[sr][sc];         //store current color
            image[sr][sc]=color;            //change to desired one
            //iterate in all four directions
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if((i && !j) || (!i && j)){
                        int r=sr+i,c=sc+j;
                        if(r>=0 && r<n && c>=0 && c<m && image[r][c]==prev)//if valid && color is equal to original color of present cell 
                        dfs(image,r,c,color);
                    }
                }
            }
            
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image,sr,sc,color);
        return image;
    }
};