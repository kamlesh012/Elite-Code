class Solution {
public:
    int takeCharacters(string s, int k) {
        //TAG:Sliding Excluding Window
        
        //IDEA:
        //Count all characters. & Exclude those characters that don't have an impact
        //on the condition given in problem statement by taking them inside a window.
        //try to maximize to window so that we willl have to minimize the operations.
        
        //Step by Step Explaination Below:
        int i=0,j=0,n=s.length();
        int res=0;
        
        //count array represents the number of a,b,& c's included in our
        //ans for the current value of i & j;
        vector<int> cnt(3,0);
        for(auto i:s){
            cnt[i-'a']++;
        }
        
        //edge case to check if all character have at least k occurences or not.
        if(*min_element(cnt.begin(),cnt.end())<k)return -1;
        
        for(i=0;i<n;i++){
            
            //since i is the end of window.
            //it will exclude a given character.
            cnt[s[i]-'a']--;
            
            //if count of excluded character becomes less than k then 
            //we will shrink the window.
            
            if(cnt[s[i]-'a']<k){
                //Shrink means j(the start point of window) will move towards i & keep including the elements in between (that have been excluded by i earlier) until count of all characters becomes at least k
            //the length of this type of each window(i-j+1) will represent one of the many possible excluded windows.
            //out of all those we will choose the window with max size that meets the given criteria.
            //so that excluding max characters will lead to min opertaions.
                while(cnt[s[i]-'a']<k){
                    cnt[s[j]-'a']++;
                    j++;
                }
            }
            res=max(res,i-j+1);
        }
        return n-res;
        
        
    }
};