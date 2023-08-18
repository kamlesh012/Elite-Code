class Solution {
public:
    vector<vector<string>> ans;
    bool validate(int r,int c,vector<string> &board){
        int n=board.size();
        for(int i=0;i<n;i++){
            if(board[r][i]=='Q')return false;
            if(board[i][c]=='Q')return false;
        }
        
        int x=r,y=c;
        while(x>=0 && x<n && y>=0 && y<n){
            if(board[x][y]=='Q')return false;
            x++;
            y++;
        }
        
        x=r,y=c;
        while(x>=0 && x<n && y>=0 && y<n){
            if(board[x][y]=='Q')return false;
            x--;
            y--;
        }
        
        x=r,y=c;
        while(x>=0 && x<n && y>=0 && y<n){
            if(board[x][y]=='Q')return false;
            x--;
            y++;
        }
        
        x=r,y=c;
        while(x>=0 && x<n && y>=0 && y<n){
            if(board[x][y]=='Q')return false;
            x++;
            y--;
        }
        return true;
    }
    //Solving Row by Row.
    //FOr first row,validating each cell & then proceeding to next row after validating each cell.
    void solve(int row,vector<string> &board){
          if(row==board.size()){
              ans.push_back(board);
              return;
          }
          for(int col=0;col<board.size();col++){
              bool ok=validate(row,col,board);
              if(ok){
                  board[row][col]='Q';
                  solve(row+1,board);
                  board[row][col]='.';
              }
          }    
        }
    vector<vector<string>> solveNQueens(int n) {
        string s(n,'.');
        vector<string> board;
        for(int i=0;i<n;i++)board.push_back(s);
        solve(0,board);
        return ans;
    }
};