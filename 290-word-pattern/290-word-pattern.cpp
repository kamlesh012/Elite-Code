class Solution {
public:
    bool wordPattern(string pat, string s) {
        map<char,string> mp;
        int ind=0,words=0;
        map<string,char> smp;
        
     for(auto i:pat){
         
         string temp;
         while(ind<s.length() && s[ind]!=' '){temp.push_back(s[ind]);ind++;}
         // cout<<temp<<" "<<words<<endl;
         words++;
         ind++;
         
         if(mp.find(i)==mp.end()){
             mp[i]=temp;
         }
        else if(mp[i]!=temp)return false;
         
         if(smp.find(temp)==smp.end()){
             smp[temp]=i;
         }
         else if(smp[temp]!=i)return false;
     }
        // cout<<ind<<" "<<words<<" "<<pat.length()<<endl;
        if(s.length()!=(ind-1))return false;
        return true;
    }
};