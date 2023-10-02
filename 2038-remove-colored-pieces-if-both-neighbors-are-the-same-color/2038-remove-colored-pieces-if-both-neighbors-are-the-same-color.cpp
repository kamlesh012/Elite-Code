class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice=0,bob=0,n=colors.size();
        for(int i=0;i<n-2;i++){
            if(colors[i]=='A' && colors[i]==colors[i+1] && colors[i+1]==colors[i+2]){
                alice++;
            }
            else if(colors[i]=='B' && colors[i]==colors[i+1] && colors[i+1]==colors[i+2]){
                bob++;
            }
        }
        return alice>bob;
    }
};