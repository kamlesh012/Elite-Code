class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& ind, vector<int>& hlth, string dir) {
        int n=ind.size();
        for(int i=0;i<n;i++){
            if(dir[i]=='L')hlth[i]*=(-1);
        }
        map<int,int> indd;
        for(int i=0;i<n;i++){
            indd[ind[i]]=i;
        }
        vector<pair<int,int>> vp;
        for(int i=0;i<n;i++){
            vp.push_back({ind[i],hlth[i]});
        }
        sort(vp.begin(),vp.end());
        
        stack<pair<int,int>> stk;
        for(int i=0;i<n;i++){
            int curr=vp[i].second;
            if(stk.empty()){
                stk.push({curr,vp[i].first});
            }
            else{
                if(stk.top().first>=0 && curr<0)
                {
                    bool done=false;
                    while(stk.size() && stk.top().first>=0 && curr<0){
                        auto tp=stk.top();
                        int diff=(tp.first+curr);
                        stk.pop();
                        // cout<<tp.first<<" Top "<<tp.second<<endl;//17
                        // cout<<vp[i].second<<" Curr "<<vp[i].first<<endl;//-20
                        if(diff>0){
                            done=true;
                            stk.push({tp.first-1,tp.second});
                            break;
                        }
                        else if(diff<0){
                            curr++;
                        }
                        else {done=true;curr=0;break;}
                    }
                    if(!done)stk.push({curr,vp[i].first});
                }
                else stk.push({curr,vp[i].first});
            }
        }
        
        vector<pair<int,int>> ans;
        while(stk.size()){
            ans.push_back({stk.top().second,stk.top().first});
            stk.pop();
        }
        // sort(ans.begin(),ans.end());
        vector<int> res(n,-100000007);
        for(int i=0;i<ans.size();i++){
            int index=ans[i].first;
            res[indd[index]]=ans[i].second;
        }
        vector<int> res2;
        for(auto i:res){
            if(i!=-100000007){
                if(i<0)i*=-1;
                res2.push_back(i);
            }
        }
        return res2;
       
    }
};