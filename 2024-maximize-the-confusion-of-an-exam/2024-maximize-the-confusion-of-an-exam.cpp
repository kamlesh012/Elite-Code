class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
//         Literally, The Best (Medium) Sliding Window Problem Ever.
        
        //Still Too much windows to slide LOL ->Check official solution for 3 more sliding window approaches. 
        function<int(char c)> slide=[&](char c){
          int remove=0,j=0,ans=0;
            for(int i=0;i<s.size();i++){
                if(s[i]==c)remove++;
                while(j<i && remove>k){
                    if(s[j]==c)remove--;
                    j++;
                }
                ans=max(ans,i-j+1);
            }
            return ans;
        };
        return max(slide('F'),slide('T'));
    }
};