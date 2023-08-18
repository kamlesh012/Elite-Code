class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        
        vector<int> ans;
        unordered_map<int,int> row,col,diag,adiag;
        set<pair<int,int>> bulbs;   //stores the bulbs that are turned on by themselves/that are centers.
        
        for(auto i:lamps){
            int r=i[0],c=i[1];
            if(bulbs.find({r,c})==bulbs.end()){
                
                //Illuminate complete row,col,diag & anti-diag
                row[r]++;
                col[c]++;
                diag[r-c]++;
                adiag[r+c]++;
                
                //insert current bulb into list of bulbs that are turned on by themselves.
                bulbs.insert({r,c});
            }
        }
        
        for(auto i:queries){
            int r=i[0],c=i[1];
            
            if(row[r] || col[c] || diag[r-c] || adiag[r+c]){
                
                //if current bulb is illuminated by itself or an other bulb,add 1 to ans
                ans.push_back(1);
                
                for(int j=-1;j<=1;j++){
                    for(int k=-1;k<=1;k++){
                        int nr=r+j,nc=c+k;
                        //if current buld is turned on because of one of it's neighbours turn that off.
                        if(nr>=0 && nr<n && nc>=0 && nc<n && bulbs.find({nr,nc})!=bulbs.end()){
                            row[nr]--;
                            col[nc]--;
                            diag[nr-nc]--;
                            adiag[nr+nc]--;
                            bulbs.erase({nr,nc});
                        }
                        
                        //if not due to neighbours we can't turn current bulb off then.
                    }
                }
            }
            else ans.push_back(0);
        }
        
        return ans;
    }
};