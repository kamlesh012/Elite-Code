#define mod 1000000007
class Solution {
public:
    int countPaths(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>memory (n,vector<int>(m,0));
        //O 1 2 3 Top Right Bottom Left
        int ans=0ll;
        
        function<int(int,int)> dfs=[&](int i,int j){
            
            int res=0ll;
            for(int dir=0;dir<4;dir++){
                int r=0,c=0;
                if(dir==0)r--;
                else if(dir==1)c++;
                else if(dir==2)r++;
                else if(dir==3)c--;

                if(i+r>=0 && j+c>=0 && i+r<n && j+c<m && matrix[i+r][j+c]>matrix[i][j]){
                    if(!memory[i+r][j+c])memory[i+r][j+c]=dfs(i+r,j+c);
                    res=((res%mod)+(memory[i+r][j+c]%mod))%mod;
                }
            }
            
            //Add 1 because the current element is also contributing a path of length 1
            memory[i][j]=res+1;
            return memory[i][j];
        };
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!memory[i][j])ans+=(dfs(i,j));
                else ans+=(memory[i][j]%mod);
                ans%=mod;
            }
        }
        
        return ans;   
    }
};