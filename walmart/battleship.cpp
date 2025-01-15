class Solution {
public:
   int  x_dir[4]={0,0,-1,1};
   int  y_dir[4]={1,-1,0,0};
    
   void dfs(vector<vector<char>>& board, int i, int j){
        // base case
         int n = board.size();
         int m = board[0].size();
         if (i<0 or j<0  or i>=n or j>=m or board[i][j]!='X') return;
         
              board[i][j]='A';

               for(int d=0;d<4;d++){
                   dfs(board,i+x_dir[d],j+y_dir[d]);
               }
   } 
    int countBattleships(vector<vector<char>>& board) {
           int n = board.size();
            int m = board[0].size();

            int ans=0;
               for(int i=0;i<n;i++){
                 for(int j=0;j<m;j++){
                    if( board[i][j]=='X'){
                         dfs(board,i,j);
                         ans++;
                    }
                 }
               }
                  return ans;

    }
};
