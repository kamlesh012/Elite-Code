class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans=0;
        int n=mat.size(),m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]){
                    bool ok=true;
                    for(int x=0;x<m;x++){
                        if(x!=j && mat[i][x]){ok=false;break;}
                    }
                    
                    for(int x=0;x<n;x++){
                        if(x!=i && mat[x][j]){ok=false;break;}
                    }
                    if(ok)ans++;
                }
            }
        }
        return ans;
    }
};